
#ifndef GENLLVM_H
#define GENLLVM_H

#include "ast.h"

enum {T_INT = 1};
#define true 1
#define false 0

int genExpr(past node);
int genDecl(past node, int level);
int see_left(past node);
int func_ref(past node);
char* genInit(past node);
char* genInit_g(past node);
int genTemp(past node);
void push_ID(char* name, char* str);
int genFunc(past node);

void gen_llvm(past node, int level);
#endif
