#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "myLang.tab.h"

past newAstNode()
{
    past node = (past)malloc(sizeof(ast));
    if(node == NULL)
    {
        printf("run out of memory.\n");
        exit(0);
    }
    memset(node, 0, sizeof(ast));

    return node;
}

past newList(past list, past node)
{
	if(list != NULL)
	{
		//add node to the tail of list
		listTail(list)->next = node;

		//make tail to point to the last element of list
		listTail(list) = node;
		list->ivalue += 1;
		return list;
	}

	list = newAstNode();
	strcpy(list->nodeType,"list");
	strcpy(list->nodeName,"Init");
	list->next = node;
	list->ivalue = 1;

	listHead(list) = node;
	listTail(list) = node;

	return list;
}




past newType(int value)
{
    past var = newAstNode();
    strcpy(var->nodeType, "type");
    strcpy(var->nodeName, ".");
    var->ivalue = value;

    return var;
}

past newPara(char* name, past left)
{
    past var = newAstNode();
    strcpy(var->nodeType, "parameter");
    strcpy(var->nodeName, name);
    var->ivalue = 0;
    var->left = left;

    return var;
}

past newDecl(char* type, int value, char* name,past left, past right)
{
    past var = newAstNode();
    strcpy(var->nodeType, type);
    strcpy(var->nodeName, name);
    var->ivalue = value;
    var->left = left;
    var->right = right;

    return var;
}

past newNum(int value)
{
    past var = newAstNode();
    strcpy(var->nodeType, "intValue");
    strcpy(var->nodeName, ".");
    var->ivalue = value;

    return var;
}

past newStr(int value, char* name)
{
    past var = newAstNode();
    strcpy(var->nodeType, "strValue");
    strcpy(var->nodeName, name);
    var->ivalue = value;

    return var;
}

past newId(int value, char* name)
{
    past var = newAstNode();
    strcpy(var->nodeType, "varDecl");
    strcpy(var->nodeName, name);
    var->ivalue = value;

    return var;
}

past newExpr(int oper, past left, past right)
{
    past var = newAstNode();
    strcpy(var->nodeType, "expr");
    strcpy(var->nodeName, ".");
    var->ivalue = oper;
    var->left = left;
    var->right = right;

    return var;
}

past newStmt(char* type, int ivalue, past left, past right)
{
    past var = newAstNode();
    strcpy(var->nodeType, type);
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    strcpy(var->nodeName, ".");

    return var;
}

past newRef(char* type, past left, past right)
{
    past var = newAstNode();
    strcpy(var->nodeType, type);
    var->ivalue = 0;
    var->left = left;
    var->right = right;
    strcpy(var->nodeName, ".");

    return var;
}

past newExtend(char* type, int ivalue, past left, past right, past extand)
{
    past var = newAstNode(), p = newAstNode();
    strcpy(var->nodeType, type);
    strcpy(p->nodeType, "Extend");
    p->left = right;
    p->right = extand;

    var->ivalue = ivalue;
    var->left = left;
    var->right = p;
    strcpy(var->nodeName, ".");

    return var;
}

int list_get_value(past node, int i)
{
    if(node->next != NULL)
        i = list_get_value(node->next, i+1);

    return i;
}

void through_list(past node, int nest)
{
    past p = node;
    do{
        showAst(p, nest);
        p = p->next;
    }while(p != NULL);

}


void showAst(past node, int nest)
{
    if(node == NULL)
        return;

    if(strcmp(node->nodeType, "funcDef") == 0)
        symbol_table = insert(symbol_table, nest, node);
    if(strcmp(node->nodeType, "decl") == 0)
        symbol_table = insert(symbol_table, nest, node);

    int i;

    for (i = 0; i < nest; i++)
        printf("  ");

    if(strcmp(node->nodeType, "Extend") == 0)
    {
        showAst(node->left, nest);
        showAst(node->right, nest);
        return;
    }
    if(strcmp(node->nodeType,"list") == 0)
    {
        past q = node;
        q->ivalue = list_get_value(q, 0);
    }

    printf("%s    %s    %d\n", node->nodeType, node->nodeName, node->ivalue);

    if(strcmp(node->nodeType, "list") == 0)
    {
        past p = node->next;
        through_list(p, nest+1);
    }

    if(strcmp(node->nodeType,"list") != 0)
    {
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
}


symtable init_symbol()
{
    symtable node = (symtable)malloc(sizeof(smbt));
    if(node == NULL)
    {
        printf("run out of memory.\n");
        exit(0);
    }
    memset(node,0, sizeof(smbt));
    return node;
}

int check_id(symtable temp)
{
    symtable p = symbol_table;
    while(p != NULL)
    {
        if(strcmp(p->symbol_name, temp->symbol_name) == 0)
        {
            if(p->level == temp->level)
            {
                printf("There is a conflict in the symbol table.\n");
                free(temp);
                return 0;
            }
        }
        p = p->next;
    }
    return 1;
}

symtable new_symbol(int level, past node)
{
    symtable p = init_symbol();
    p->symbol_type = node->left->ivalue;
    p->level = level;
    if(strcmp(node->nodeType, "decl") == 0)
    {
        past sign = node->right;
        past temp_sign = sign->next;
        if(strcmp(temp_sign->nodeType,"varInitDecl") == 0)
        {
            strcpy(p->symbol_name, temp_sign->left->nodeName);
        }
        else
            strcpy(p->symbol_name, temp_sign->nodeName);
        temp_sign = temp_sign->next;
        while(temp_sign != NULL)
        {
            symtable q = init_symbol();
            q->symbol_type = node->left->ivalue;
            q->level = level;
            //temp_sign = sign->right;
            if(strcmp(temp_sign->nodeType,"varInitDecl") == 0)
            {
                strcpy(q->symbol_name, temp_sign->left->nodeName);
            }
            else
                strcpy(q->symbol_name,temp_sign->nodeName);
            temp_sign = temp_sign->next;
            q->next = p->next;
            p->next = q;
        }
    }
    else if(strcmp(node->nodeType,"funcDef") == 0)
    {
        int i = level;
        past temp = node->left;
        i++;
        p->symbol_type = node->ivalue;
        strcpy(p->symbol_name, temp->left->nodeName);
        temp = temp->right;
        if (temp!=NULL){
            temp = temp->next;
        }
        i++;
        if(temp != NULL)
        {
            i++;
            do{
                symtable q = init_symbol();
                q->level = i;
                q->symbol_type = temp->left->ivalue;
                strcpy(q->symbol_name, temp->nodeName);
                q->next = p->next;
                p->next = q;
                temp = temp->next;
            } while(temp != NULL);
        }
    }
    return p;
}

symtable insert(symtable tab, int level, past node)
{
    if(tab==NULL){
        tab = init_symbol();
    }
    symtable p, q;
    p = new_symbol(level, node);
    q = tab;

    while(q->next != NULL)
        q = q->next;

    q->next = p;

    return tab;
}



void show_symtable(symtable tab)
{
    int level;
    symtable temp = tab;

    printf("The Symbol table of the test.c:\n");
    printf("Type:\tName:\tLevel:\tLLVM ID:\n");
    while(temp != NULL)
    {
        printf("%d    %s    %d    %s\n", temp->symbol_type, temp->symbol_name, temp->level, temp->symbol_num);
        temp = temp->next;
    }
}