%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int yylex();
	int yyerror();
%}
%union{
	char *str;
}
%token SCOLON CLASS IF ELSE WHILE LPAREN RPAREN LFPAREN RFPAREN LSPAREN RSPAREN
		GT LT EQ PLUS MINUS DIV MUL COMMA PUBLIC STATIC VOID MAIN NEW EXTENDS THIS
		DEFINE TRUE FALSE BOOL AND OR NOT DOT LENGTH SYSTEM KINT OTHER
		STRING
%token<str> IDENTIFIER INT
%type <str> MacroDefinationstar
%type <str> MainClass
%type <str> Expression
%type <str> PrimaryExpression
%type <str> MacroDefExpression
%type <str> MacroDefStatement
%type <str> Statement
%type <str> StatementStar
%%
goal :		SYSTEM	{printf("Found Macros\n");}
;
MainClass :	CLASS IDENTIFIER LFPAREN PUBLIC STATIC VOID MAIN LPAREN STRING LSPAREN RSPAREN
			IDENTIFIER RPAREN LFPAREN SYSTEM LPAREN Expression RPAREN SCOLON RFPAREN RFPAREN
;
MacroDefinationstar :	MacroDefinationstar MacroDefination
						| {;}
;
MacroDefination :	MacroDefExpression | MacroDefStatement
;
StatementStar :		StatementStar Statement
					| {;}
;
Statement :		LFPAREN StatementStar RFPAREN
				| SYSTEM LPAREN Expression RPAREN SCOLON
				| IDENTIFIER EQ Expression SCOLON
				| IDENTIFIER LSPAREN Expression RSPAREN EQ Expression SCOLON
				| IF LPAREN Expression RPAREN Statement
				| IF LPAREN Expression RPAREN ELSE Statement
				| WHILE LPAREN Expression RPAREN Statement
;
CommaIdentifierStar :	IDENTIFIER COMMA CommaIdentifierStar
						| IDENTIFIER
						| {;}
;
MacroDefStatement	:	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LFPAREN StatementStar RFPAREN
;
MacroDefExpression : 	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LPAREN Expression RPAREN
;
CommaExpressionStar : 	CommaExpressionStar COMMA Expression
						| {;}
;
Expression  :		PrimaryExpression AND AND PrimaryExpression
					| PrimaryExpression OR OR PrimaryExpression
					| PrimaryExpression NOT EQ PrimaryExpression
					| PrimaryExpression LT EQ PrimaryExpression
					| PrimaryExpression PLUS PrimaryExpression
					| PrimaryExpression MINUS PrimaryExpression
					| PrimaryExpression MUL PrimaryExpression
					| PrimaryExpression DIV PrimaryExpression
					| PrimaryExpression LSPAREN PrimaryExpression RSPAREN
					| PrimaryExpression LENGTH
					| PrimaryExpression 
					| PrimaryExpression DOT IDENTIFIER LPAREN Expression CommaExpressionStar RPAREN
					| IDENTIFIER LPAREN Expression CommaExpressionStar RPAREN
PrimaryExpression 	: 	INT
						| TRUE
						| FALSE
						| IDENTIFIER
						| THIS
						| NEW KINT LSPAREN Expression RSPAREN
						| NEW IDENTIFIER LPAREN RPAREN
						| NOT Expression
						| LPAREN Expression RPAREN
;
%%