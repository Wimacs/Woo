%{

#include <stdio.h>
#include <string.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
extern char* yytext;

%}

%union{
	int	     iValue;
	char*	 icontent;
	past	 pAst1, pAst2, pAst3, pAst4;
};


%token <iValue>   NUMBER INT STR VOID IF ELSE WHILE RETURN CMP
%token <icontent> STRING ID
%type  <pAst1>	  program external_declaration function_definition declaration init_declarator_list init_declarator intstr_list
%type  <pAst2>    initializer declarator direct_declarator parameter_list parameter type statement compound_statement begin_scope
%type  <pAst3>    end_scope statement_list expression_statement selection_statement iteration_statement jump_statement 
%type  <pAst4>    expr assign_expr cmp_expr add_expr mul_expr primary_expr expr_list

%%

program
    : external_declaration			  { $$ = newList(NULL,$1); strcpy($$->nodeName,"program"); astRoot=$$; }
    | program external_declaration                { $$ = newList($1,$2);}
    ;

external_declaration
    : function_definition  			  { $$ = $1; }        
    | declaration                       	  { $$ = $1; }  
    ; 

function_definition
    : type declarator compound_statement          { $$ = newDecl("funcDef", $1->ivalue, ".", $2, $3); }
    ;

declaration
    : type init_declarator_list ';'               { $$ = newDecl("decl", $1->ivalue, ".", $1, $2); }
    ;

init_declarator_list
    : init_declarator                             { $$ = newList(NULL,$1); }
    | init_declarator_list ',' init_declarator    { $$ = newList($1, $3); }
    ;

init_declarator
    : declarator				  { $$ = $1; }  
    | declarator '=' add_expr                     { $$ = newDecl("varInitDecl", 0, "=", $1, $3); }
    | declarator '=' '{' intstr_list '}'          { $$ = newDecl("arrayInitDecl", 1, "=", $1, $4); }
    ;

intstr_list
    : initializer                                 { $$ = newList(NULL,$1); }
    | intstr_list ',' initializer                 { $$ = newList($1, $3); }
    ;

initializer
    : NUMBER                                      { $$ = newNum($1); }
    | STRING                                      { $$ = newStr(STRING, $1); }
    ;

declarator
    : direct_declarator				  { $$ = $1; }  
    ; 

direct_declarator
    : ID                                          { $$ = newDecl("varDecl", ID, $1, NULL, NULL); }
    | direct_declarator '(' parameter_list ')'    { $$ = newDecl("funcDecl", $1->ivalue, $1->nodeName, $1, $3); }
    | direct_declarator '(' ')'                   { $$ = newDecl("funcDecl", $1->ivalue, $1->nodeName, $1, NULL); }
    | ID '[' expr ']'                             { past temp= newId(ID, $1); $$ = newDecl("arrayDecl", ID, temp->nodeName, $3, NULL); }
    | ID '[' ']'                                  { past temp= newId(ID, $1); $$ = newDecl("arrayDecl", ID, temp->nodeName, NULL, NULL); }
    ;

parameter_list
    : parameter                                   { $$ = newList(NULL,$1); }
    | parameter_list ',' parameter                { $$ = newList($1, $3); }
    ;

parameter
    : type ID                                     { past temp= newId(ID, $2); $$ = newPara(temp->nodeName, $1); }
    ;

type
    : INT                                         { $$ = newType($1); }
    | STR                                         { $$ = newType($1); }
    | VOID                                        { $$ = newType($1); }
    ;

statement
    : compound_statement		          { $$ = $1; }  
    | expression_statement			  { $$ = $1; }  
    | selection_statement			  { $$ = $1; }  
    | iteration_statement		    	  { $$ = $1; }  
    | jump_statement				  { $$ = $1; }  
    | declaration				  { $$ = $1; }  
    ;

compound_statement 
    : begin_scope end_scope                       { $$ = NULL; }
    | begin_scope statement_list end_scope        { $$ = newStmt("compStmt", 0, $2, NULL); }
    ; 

begin_scope
    : '{'                                         {}
    ;

end_scope
    : '}'                                         {}
    ; 

statement_list
    : statement                                   { $$ = newList(NULL,$1); } 
    | statement_list statement                    { $$ = newList($1, $2); } 
    ;

expression_statement
    : ';'					  {}
    | expr ';'                                    { $$ = $1; }
    ;

selection_statement
    : IF '(' expr ')' statement                   { $$ = newStmt("ifStmt", $1, $3, $5); }
    | IF '(' expr ')' statement ELSE statement    { past temp1 = newStmt("elseStmt",$6,NULL,$7); past temp2 = newStmt("ifStmt",$1,$3,$5); $$ = newStmt("if_elseStmt", $1, temp2, temp1); } 
    ;

iteration_statement
    : WHILE '(' expr ')' statement                { $$ = newStmt("whileStmt", $1, $3, $5); }
    ; 

jump_statement
    : RETURN ';'                                  { $$ = newStmt("returnStmt", $1, NULL, NULL); }
    | RETURN expr ';'                             { $$ = newStmt("returnStmt", $1, NULL, $2); }
    ;

expr
    : assign_expr                                 { $$ = $1; } 
    ;

assign_expr
    : cmp_expr				          { $$ = $1; }  
    | ID '=' assign_expr                          { past temp = newId(ID, $1); strcpy(temp->nodeType,"idRef");$$ = newExpr('=', temp, $3); }
    | ID '[' expr ']' '=' assign_expr             { past temp = newId(ID, $1); strcpy(temp->nodeType,"idRef");$$ = newExtend("expr", '=', temp, $3, $6); }
    ;

cmp_expr
    : add_expr					  { $$ = $1; }  
    | cmp_expr CMP add_expr                       { $$ = newExpr($2, $1, $3); }
    ; 

add_expr
    : mul_expr                                    { $$ = $1; }
    | add_expr '+' mul_expr                       { $$ = newExpr('+', $1, $3); }
    | add_expr '-' mul_expr                       { $$ = newExpr('-', $1, $3); }
    ;

mul_expr
    : primary_expr				  { $$ = $1; }  
    | mul_expr '*' primary_expr                   { $$ = newExpr('*', $1, $3); }
    | mul_expr '/' primary_expr                   { $$ = newExpr('/', $1, $3); }
    | mul_expr '%' primary_expr                   { $$ = newExpr('%', $1, $3); }
    | '-' primary_expr                            { $$ = newExpr('-', NULL, $2); }
    ;   

primary_expr
    : ID '(' expr_list ')'                        { past temp = newId(ID, $1); strcpy(temp->nodeType,"idRef");$$ = newRef("funcRef", temp, $3); }
    | ID '(' ')'                                  { past temp = newId(ID, $1); strcpy(temp->nodeType,"idRef");$$ = newRef("funcRef", temp, NULL); }
    | '(' expr ')'                                { $$ = $2; }
    | ID                                          { $$ = newId(ID, $1); strcpy($$->nodeType,"idRef");}
    | initializer                                 { $$ = $1; }
    | ID '[' expr ']'                             { past temp = newId(ID, $1); strcpy(temp->nodeType,"idRef");$$ = newRef("arrayRef", temp, $3); }
    ;

expr_list
    : expr                                        { $$ = newList(NULL,$1); }
    | expr_list ',' expr                          { $$ = newList($1, $3); }
    ;
%%

void yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
}
