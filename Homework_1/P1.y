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
%token<str> SCOLON CLASS IF ELSE WHILE LPAREN RPAREN LFPAREN RFPAREN LSPAREN RSPAREN
		GT LT EQ PLUS MINUS DIV MUL COMMA PUBLIC STATIC VOID MAIN NEW EXTENDS THIS
		DEFINE TRUE FALSE BOOL AND OR NOT DOT LENGTH SYSTEM INT OTHER IDENTIFIER NUM
		STRING RETURN
%type <str> MacroDefinationstar
%type <str> MainClass
%type <str> Expression
%type <str> PrimaryExpression
%type <str> MacroDefExpression
%type <str> MacroDefStatement
%type <str> Statement
%type <str> StatementStar
%type <str> TypeIdentifierStar
%type <str> CommaTypeIdentifier
%type <str> MethodDeclaration
%type <str> MethodDeclarationStar
%type <str> TypeDeclaration
%type <str> TypeDeclarationStar
%type <str> Type
%%
goal :		MacroDefinationstar MainClass TypeDeclarationStar	{printf("Found Macros\n");}
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
				| SYSTEM LPAREN Expression RPAREN SCOLON {/*what happens when you macro the print*/;}
				| IDENTIFIER EQ Expression SCOLON
				| IDENTIFIER LSPAREN Expression RSPAREN EQ Expression SCOLON
				| IF LPAREN Expression RPAREN Statement
				| IF LPAREN Expression RPAREN Statement ELSE Statement
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
CommaExpressionStar : 	Expression COMMA CommaExpressionStar
						| Expression
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
					| PrimaryExpression DOT IDENTIFIER LPAREN CommaExpressionStar RPAREN
					| IDENTIFIER LPAREN CommaExpressionStar RPAREN
;
PrimaryExpression 	: 	NUM
						| TRUE
						| FALSE
						| IDENTIFIER
						| THIS
						| NEW INT LSPAREN Expression RSPAREN
						| NEW IDENTIFIER LPAREN RPAREN
						| NOT Expression
						| LPAREN Expression RPAREN
;
Type 	: 	INT
			| BOOL
			| INT LSPAREN RSPAREN
			| IDENTIFIER
;
TypeIdentifierStar 	:	TypeIdentifierStar Type IDENTIFIER SCOLON
						| {;}
;
CommaTypeIdentifier :	Type IDENTIFIER 
						| Type IDENTIFIER COMMA CommaTypeIdentifier
						| {;}
;
MethodDeclaration	:	PUBLIC Type IDENTIFIER LPAREN CommaTypeIdentifier RPAREN LFPAREN TypeIdentifierStar 
						StatementStar RETURN Expression SCOLON RFPAREN
;
MethodDeclarationStar	:	MethodDeclaration MethodDeclarationStar
							| {;}
;
TypeDeclaration	:	CLASS IDENTIFIER LFPAREN TypeIdentifierStar MethodDeclarationStar RFPAREN
					| CLASS IDENTIFIER EXTENDS IDENTIFIER LFPAREN TypeIdentifierStar MethodDeclarationStar RFPAREN
;
TypeDeclarationStar :	TypeDeclaration TypeDeclarationStar
						| {;}
;
%%