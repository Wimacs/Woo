#include<stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "genllvm.h"

extern int temVarNum;

int main(int argc, char* argv[])
{
	extern int yyparse(void);
	extern FILE *yyin;

	if (argc < 2)
		yyin = fopen("test.c", "r");
	else
		yyin = fopen(argv[1], "r");

	if (yyparse())
	{
		printf("Error\n");
		return -1;
	}
	fclose(yyin);

	past expr = astRoot;
	int count = 1;
    symtable p;
	showAst(expr,0);
    show_symtable(symbol_table->next);
    gen_llvm(expr->next,1);
	return 0;
}
