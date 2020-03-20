#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "genllvm.h"
#include "myLang.tab.h"


char sprintfBuffer[500];
int temVarNum = 0;

void addLLVMCodes(char* codes)
{
	//把生成的指令加入到指令队列，这里为了说明，仅用printf把生成的指令打印出来
	printf("%s", codes);
	printf("\n");
}


int getTemVarNum()
{
	temVarNum ++;
	return temVarNum;
}

void push_ID(char* name, char* str){
    symtable p = symbol_table->next;
    while(p!=NULL){
        if(strcmp(p->symbol_name, name)==0){
            strcpy(p->symbol_num, str);
            break;
        }
        p = p->next;
    }
}

char* get_idnum(char* name){    //remember to free
    symtable p = symbol_table->next;
    char *num;
    num = (char*)malloc(MAX);
    while(p!=NULL){
        if(strcmp(p->symbol_name, name)==0){
            strcpy(num,p->symbol_num);
            break;
        }
        p = p->next;
    }
    return num;
}

int genTemp(past node){
    char temp_num[MAX], *source;
    sprintf(temp_num,"%%%d",getTemVarNum());
    source = get_idnum(node->nodeName);
    sprintf(sprintfBuffer,"%s = load i32, i32* %s, align 4",temp_num, source);
    addLLVMCodes(sprintfBuffer);
    free(source);
    return temVarNum;
}



char* genInit_g(past node){
    char global_ID[MAX], int_value[MAX], *temp_buffer;
    temp_buffer = (char*)malloc(500);
    if(node->left!=NULL) sprintf(global_ID,"@%s",node->left->nodeName);
    push_ID(node->left->nodeName, global_ID);
    sprintf(int_value,"%d", node->right->ivalue);
    sprintf(temp_buffer,"%s = dso_local global i32 %s, align 4",global_ID,int_value);
    return temp_buffer;
}

char* genInit(past node){
    char get_ID[MAX], expr[MAX], *temp_buffer;
    past p= node->right;

    temp_buffer = (char*)malloc(500);
    sprintf(get_ID,"%%%d",getTemVarNum());
    sprintf(temp_buffer,"%s = alloca i32, align 4", get_ID);
    push_ID(node->left->nodeName,get_ID);
    addLLVMCodes(temp_buffer);
    if(strcmp(p->nodeType,"intValue")==0){
        sprintf(expr,"%d", p->ivalue);
        sprintf(temp_buffer,"store i32 %s, i32* %s, align 4",expr,get_ID);
    }
    else if(strcmp(p->nodeType,"idRef")==0){
        sprintf(expr, "%%%d", genTemp(p));
        sprintf(temp_buffer,"store i32 %s, i32* %s, align 4",expr,get_ID);
    }
    else if(strcmp(p->nodeType,"expr")==0){
        sprintf(expr, "%%%d", genExpr(p));
        sprintf(temp_buffer,"store i32 %s, i32* %s, align 4",expr,get_ID);
    }
    else{
        printf("Unsupported type!");
        exit(0);
    }

    return temp_buffer;
}

int genDecl(past node, int level){
    past p = node;
    past trace = p->right;

    if(level==1){
        char global_ID[MAX];
        char* temp;
        if(strcmp(trace->nodeType,"list")==0) trace = trace->next;
        while(trace!=NULL){

            if(strcmp(trace->nodeType,"varInitDecl")==0){
                temp = genInit_g(trace);
                sprintf(sprintfBuffer, "%s", temp);
                free(temp);
            }
            else{
                sprintf(global_ID,"@%s",trace->nodeName);
                push_ID(trace->nodeName,global_ID);
                sprintf(sprintfBuffer,"%s = common dso_local global i32 0, align 4",global_ID);

            }
            addLLVMCodes(sprintfBuffer);
            trace = trace->next;
        }
    }
    else{
        char *temp, id_num[MAX];
        if(strcmp(trace->nodeType,"list")==0) trace = trace->next;
        while(trace!=NULL){
            if(strcmp(trace->nodeType,"varInitDecl")==0){
                temp = genInit(trace);
                sprintf(sprintfBuffer, "%s", temp);
                free(temp);
            }
            else{
                sprintf(id_num,"%%%d",getTemVarNum());
                push_ID(trace->nodeName, id_num);
                sprintf(sprintfBuffer,"%s = alloca i32 0, align 4",id_num);
                addLLVMCodes(sprintfBuffer);
            }
            trace = trace->next;
        }
    }
    return temVarNum;
}

int genFunc(past node){
    //define dso_local i32 @main() #0 {}
    temVarNum =0;
    int para_num = 0;
    char type[MAX], para[100];
    past para_list = node->left->right;
    past p = NULL;
    if(para_list!=NULL) p = para_list->next;
    memset(para,'\0', sizeof(para));
    if(node->ivalue==INT){
        sprintf(type, "i32");
    }
    else if(node->ivalue==VOID){
        sprintf(type, "void");
    }
    while(p!=NULL){
        if(para[0]=='\0'){
            sprintf(para, "i32 ");
        }
        else{
            strcat(para, "i32 ");
        }
        para_num++;
        p= p->next;
    }
    sprintf(sprintfBuffer,"define dso_local %s @%s(%s) #0 {", type,node->left->nodeName,para);
    addLLVMCodes(sprintfBuffer);
    if(para_list!=NULL) p=para_list->next;
    for(;para_num>0&&p!=NULL;para_num--){
        char tem_num[MAX];
        sprintf(tem_num,"%%%d",getTemVarNum());
        sprintf(sprintfBuffer,"%s = alloca i32, align 4",tem_num);
        addLLVMCodes(sprintfBuffer);
        push_ID(p->nodeName,tem_num);
        p = p->next;
    }
    return temVarNum;
}

int func_ref(past node){
    past para_list = node->right;
    past p = NULL;
    if(para_list!=NULL) p = para_list->next;
    char expr_list[MAX];
    int temp;
    memset(expr_list,'\0', sizeof(expr_list));
    while(p!=NULL){
        if(strcmp(p->nodeType,"intValue")==0){
            temp = p->ivalue;
            if(expr_list[0]=='\0'){
                sprintf(expr_list,"i32 %d", temp);
            }
            else{
                char int_temp[MAX];
                sprintf(int_temp,"i32 %d", temp);
                strcat(expr_list,int_temp);
            }
            sprintf(sprintfBuffer,"%%%d = load i32, i32* %d, align 4", getTemVarNum(), temp);
            addLLVMCodes(sprintfBuffer);
        }
        else if(strcmp(p->nodeType,"idRef")==0){
            char *temp_para;
            temp_para = get_idnum(p->nodeName);
            sprintf(sprintfBuffer,"%%%d = load i32, i32* %s, align 4", getTemVarNum(), temp_para);
            addLLVMCodes(sprintfBuffer);
            temp = temVarNum;
            if(expr_list[0]=='\0'){
                sprintf(expr_list,"i32 %%%d",temp);
            }
            else{
                char int_temp[MAX];
                sprintf(int_temp,"i32 %%%d", temp);
                strcat(expr_list, int_temp);
            }
            free(temp_para);
        }
        else if(strcmp(p->nodeType,"expr")==0){
            temp = genExpr(node);
            if(expr_list[0]=='\0'){
                sprintf(expr_list,"i32 %%%d", temp);
            }
            else{
                char int_temp[MAX];
                sprintf(int_temp,"i32 %%%d", temp);
                strcat(expr_list,int_temp);
            }
        }
        else{
            printf("error: unsupported error");
            exit(0);
        }
        p =p->next;
    }
    sprintf(sprintfBuffer,"%%%d = call i32 %s(%s)", getTemVarNum(), node->left->nodeName, expr_list);
    addLLVMCodes(sprintfBuffer);

    return temVarNum;


}

int see_left(past node){

    if(node==NULL){
        return 0;
    }

    int temp;
    if(strcmp(node->nodeType,"expr")==0){
        temp = genExpr(node);
    }
    else if(strcmp(node->nodeType,"intValue")==0){
        temp = node->ivalue;
    }
    else if(strcmp(node->nodeType,"idRef")==0){
        char *id_num;
        id_num = get_idnum(node->nodeName);
        sprintf(sprintfBuffer,"%%%d = load i32, i32* %s, align 4", getTemVarNum(),id_num);
        addLLVMCodes(sprintfBuffer);
        free(id_num);
        temp = temVarNum;
    }
    else if(strcmp(node->nodeType,"funcRef")==0){
        temp = func_ref(node);
    }
    else{
        printf("Error: unsupported type");
        exit(0);
    }
    return temp;
}

int genExpr(past node){
    if(node == NULL) return -1;
    char loperand[MAX], roperand[MAX], oper[MAX];
    past left = node->left, right = node->right;
    int left_val, right_val;

    left_val = see_left(left);
    right_val = see_left(right);
    if(node->ivalue == '+'){
        sprintf(oper, "add nsw");
    }
    else if(node->ivalue=='-'){
        sprintf(oper, "sub nsw");
    }
    else if(node->ivalue=='*'){
        sprintf(oper, "mul nsw");
    }
    else if(node->ivalue=='/'){
        sprintf(oper, "sdiv");
    }
    else if(node->ivalue=='%'){
        sprintf(oper, "srem");
    }
    else if(node->ivalue==CMP){
        sprintf(oper,"icmp ed");
    }
    else if(node->ivalue=='='){
        sprintf(sprintfBuffer,"store i32 %%%d, i32* %%%d, align 4", right_val, left_val);
        addLLVMCodes(sprintfBuffer);
        return left_val;
    }
    else{
        printf("Error: unsupported type!");
        exit(0);
    }
    if(strcmp(left->nodeType,"intValue")==0){
        if(strcmp(right->nodeType,"intValue")==0){
            sprintf(loperand, "%d", left_val);
            sprintf(roperand, "%d", right_val);
        }
        else{
            sprintf(loperand, "%d", left_val);
            sprintf(roperand, "%%%d", right_val);
        }

    }
    else{
        if(strcmp(right->nodeType,"intValue")==0){
            sprintf(loperand, "%%%d", left_val);
            sprintf(roperand, "%d", right_val);
        }
        else{
            sprintf(loperand, "%%%d", left_val);
            sprintf(roperand, "%%%d", right_val);
        }
    }
    sprintf(sprintfBuffer,"%%%d = %s i32 %s, %s", getTemVarNum(), oper, loperand, roperand);
    addLLVMCodes(sprintfBuffer);
    return temVarNum;
}

void gen_llvm(past node, int level){
    if(node==NULL) return;
    if(strcmp(node->nodeType,"decl")==0){
        genDecl(node,level);
    }
    else if(strcmp(node->nodeType,"funcDef")==0){
        genFunc(node);
        gen_llvm(node->right->left->next, level+1);
        printf("}\n");
    }
    else if(strcmp(node->nodeType,"expr")==0){
        genExpr(node);
    }
    else if(strcmp(node->nodeType,"funcRef")==0){
        func_ref(node);
    }
    gen_llvm(node->next,level);
}

/*
int genPrimaryExpr(past node, char* operand)
{
    int type = -1;
    if(strcmp(node->nodeType, "intValue") == 0)
    {
        type = T_INT;
        if(operand != NULL)
            sprintf(operand, "%d", node->ivalue);
    }
    else if(strcmp(node->nodeType, "expr") == 0)
    {
        //表达式的中间结果用临时变量保存
        //其结果为当前的 temVarNum
        type = genExpr(node);
        if(operand != NULL)
            sprintf(operand, "%%%d", temVarNum);
    }
    else
    {
        printf("ERROR: 发现不支持的运算类型, line %d\n", node->lineno);
    }
    return type;
}

int genExpr(past node)
{
	if(node == NULL)
		return -1;


	int ltype = -1;
	int rtype = -1;

	if( strcmp(node->nodeType, "expr") == 0)
	{
		char loperand[50];
		char roperand[50];
		char oper[50];

		//一元表达式左操作符为空
		if( node->left != NULL)
			ltype = genPrimaryExpr(node->left, loperand);
		rtype = genPrimaryExpr(node->right, roperand);
		if(node->ivalue == 'M')
		{
			//处理一元表达式
			ltype = rtype;
			sprintf(loperand, "0");
		}

		if( ltype == rtype && ltype == T_INT)
		{
			switch(node->ivalue)
			{
			case '+': sprintf(oper, "add nsw"); break;
			case '-': sprintf(oper, "sub nsw"); break;
			case '*': sprintf(oper, "mul nsw"); break;
			case '/': sprintf(oper, "sdiv"); break;
			case '%': sprintf(oper, "srem"); break;
			case 'M': sprintf(oper, "sub nsw"); break;
			}

			sprintf(sprintfBuffer, "  %%%d = %s i32 %s, %s\n",	getTemVarNum(), oper, loperand, roperand);
			addLLVMCodes(sprintfBuffer);

			return T_INT;
		}

	}
	return temVarNum;
}
*/