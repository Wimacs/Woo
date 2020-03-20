%{
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "myLang.tab.h"

%}
Separators	[\(\)\{\}\[\]\,\.]
Comment    \/\/.*|\/\*(.|\n)*\*\/
%%


int 	{yylval.iValue = INT;return INT;}
void	{yylval.iValue = VOID;return VOID;}
return	{yylval.iValue = RETURN;return RETURN;}
while	{yylval.iValue = WHILE;return WHILE;}
if	{yylval.iValue = IF;return IF;}
else	{yylval.iValue = ELSE;return ELSE;}
==   { yylval.iValue = CMP;return CMP; }
"=" | 
"+" | 
"-" |
"*" |
"/"	{ return yytext[0]; }
\>|\<	{yylval.iValue = CMP;return CMP;}

[0-9]+ { yylval.iValue = atoi(yytext);return NUMBER; }
[a-zA-Z][a-zA-Z_0-9]*	 { yylval.icontent = (char*)malloc(sizeof(char)*strlen(yytext));strcpy(yylval.icontent,yytext); return ID; }
{Separators}	{ return yytext[0]; }
\;	{return yytext[0];}
{Comment}	{}
\"(\\.|[^"\\])*\"	{yylval.icontent = (char*)malloc(sizeof(char)*strlen(yytext)); strcpy(yylval.icontent,yytext);return STRING; }
\n	{}
[ \t] { /* ignore whitespace */ }
. {printf("invalid character %s", yytext);}


%%

int yywrap()
{
	return 1;
}
