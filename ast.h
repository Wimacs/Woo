#ifndef AST_H
#define AST_H
#define MAX 20
typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	int ivalue;
    char nodeType[MAX];
    char nodeName[MAX];
	past left;
	past right;
	past next;
	int lineno;
};

typedef struct _symbol_table smbt;
typedef struct _symbol_table *symtable;
struct _symbol_table{
    int level;
    int symbol_type;
    char symbol_num[MAX];
    char symbol_name[MAX];
    symtable next;
};

past newList(past list, past node);
#define listHead(node) node->left
#define listTail(node) node->right


past newNum(int value);
past newExpr(int oper, past left,past right);
void showAst(past node, int nest);
past newType(int value);
past newPara(char* name, past left);
past newDecl(char* type, int value, char* name,past left, past right);
past newStr(int value, char* name);
past newId(int value, char* name);
past newStmt(char* type, int ivalue, past left, past right);
past newRef(char* type, past left, past right);
past newExtend(char* type, int ivalue, past left, past right, past extand);
int list_get_value(past node, int i);
void through_list(past node, int nest);
past astRoot;

symtable init_symbol();
int check_id(symtable temp);
symtable new_symbol(int level, past node);
symtable insert(symtable tab, int level, past node);
void show_symtable(symtable tab);
symtable symbol_table;




#endif
