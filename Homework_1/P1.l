%{
	#include <stdio.h>
	#include "P1.tab.h"
%}

%%
[ \t\n]	;	//ignoring tabs,spaces,newlines
\/\/.*	{;}	//ignoring singleline comments
\/\*.*\*\/	{;}//ignoring multiline commentsreturn LPAREN;}
\)		{return RPAREN;}
\{		{return LFPAREN;}
\}		{return RFPAREN;}
\[		{return LSPAREN;}
\]		{return RSPAREN;}
\<		{return LT;}
\>		{return GT;}
\=		{return EQ;}
\+		{return PLUS;}
\-		{return MINUS;}
\*		{return MUL;}
\/		{return DIV;}
\;		{return SCOLON;}
\,		{return COMMA;}
class	{return CLASS;}
if 		{return IF;}
else	{return ELSE;}
while	{return WHILE;}
public 	{return PUBLIC;}
static 	{return STATIC;}
void 	{return VOID;}
main 	{return MAIN;}
return 	{return RETURN;}
new 	{return NEW;}
this	{return THIS;}
extends {return EXTENDS;}
#define	{return DEFINE;}
true	{return TRUE;}
false 	{return FALSE;}
int		{return INT;}
String 	{return STRING;}
boolean {return BOOL;}
&		{return AND;}
\|		{return OR;}
!		{return NOT;}


"System.out.println" 		{return SYSTEM;}
"."		{return DOT;}
".length"	{return LENGTH;}
[a-zA-Z][a-zA-Z0-9_]*	{yylval.str = strdup(yytext);return IDENTIFIER;}
0|[1-9][0-9]*			{yylval.str = strdup(yytext);return NUM;}
.			{return OTHER;}
%%

int yywrap() {return 1;}
int yyerror(char* s) {fprintf(stderr,"Parse error\n");}
int main()
{
	yyparse();
}