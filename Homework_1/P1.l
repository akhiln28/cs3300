%{
	#include <stdio.h>
	#include "P1.tab.h"
%}

%%
[ \t\n]	;
\(		{printf("(\n");return LPAREN;}
\)		{printf(")\n");return RPAREN;}
\{		{printf("{\n");return LFPAREN;}
\}		{printf("}\n");return RFPAREN;}
\[		{printf("[\n");return LSPAREN;}
\]		{printf("]\n");return RSPAREN;}
\<		{printf("<\n");return LT;}
\>		{printf(">\n");return GT;}
\=		{printf("=\n");return EQ;}
\+		{printf("+\n");return PLUS;}
\-		{printf("-\n");return MINUS;}
\*		{printf("*\n");return MUL;}
\/		{printf("/\n");return DIV;}
\;		{printf(";\n");return SCOLON;}
\,		{printf(",\n");return COMMA;}
class	{printf("class\n");return CLASS;}
if 		{printf("if\n");return IF;}
else	{printf("else\n");return ELSE;}
while	{printf("while\n");return WHILE;}
public 	{printf("public\n");return PUBLIC;}
static 	{printf("static\n");return STATIC;}
void 	{printf("void\n");return VOID;}
main 	{printf("main\n");return MAIN;}
new 	{printf("new\n");return NEW;}
this	{printf("this\n");return THIS;}
extends {printf("extends\n");return EXTENDS;}
#define	{printf("define\n");return DEFINE;}
true	{printf("true\n");return TRUE;}
false 	{printf("false\n");return FALSE;}
int		{printf("int\n");return KINT;}
String 	{printf("String\n");return STRING;}
boolean {printf("boolean\n");return BOOL;}
&		{printf("&\n");return AND;}
\|		{printf("|\n");return OR;}
!		{printf("!\n");return NOT;}
"."		{printf(".\n");return DOT;}
.length	{printf("length\n");return LENGTH;}


System.out.println 		{printf("System\n");SYSTEM;}
[a-zA-Z][a-zA-Z0-9]*	{printf("id\n");yylval.str = strdup(yytext);return IDENTIFIER;}
0|[1-9][0-9]*			{yylval.str = strdup(yytext);return INT;}
\/\/.*\n;
\/\*.*\*\/	;
.			{printf("other charactor\n");return OTHER;}
%%

int yywrap() {return 1;}
int yyerror(char* s) {fprintf(stderr,"Parse error\n");}
int main()
{
	yyparse();
}