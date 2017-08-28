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
goal :	prog	{printf("%s\n",$1);}
;
prog :		MacroDefinationstar MainClass TypeDeclarationStar	
			{$$ = (char*)malloc((strlen($2) + strlen($3))*sizeof(char));
			strcpy($$,$2);strcat($$,$3);free($2);free($3);}
;
MainClass :	CLASS IDENTIFIER LFPAREN PUBLIC STATIC VOID MAIN LPAREN STRING LSPAREN RSPAREN
			IDENTIFIER RPAREN LFPAREN SYSTEM LPAREN Expression RPAREN SCOLON RFPAREN RFPAREN
			{
				int l = strlen($2) + strlen($12) + strlen($17) + 100;
				$$ = (char*)malloc(l*sizeof(char));
				strcpy($$,"class ");strcat($$,$2);strcat($$,"{ public static void main(String[]");
				strcat($$,$12);strcat($$,"){System.out.println(");strcat($$,$17);strcat($$,");}}");
				free($2);free($12);free($17);
			}
;
MacroDefinationstar :	MacroDefinationstar MacroDefination
						| {;}
;
MacroDefination :	MacroDefExpression | MacroDefStatement
;
StatementStar :		StatementStar Statement
					{
						$$ = (char*)malloc((strlen($1) + strlen($2))*sizeof(char));
						strcpy($$,$1);strcat($$,$2);
						free($1);free($2);
					}
					| {;}
;
Statement :		LFPAREN StatementStar RFPAREN
				{
					$$ = (char*)malloc((strlen($2) + 10)*sizeof(char));
					strcpy($$,"{");strcat($$,$2);strcat($$,"}\n");
					free($2);
				}
				| SYSTEM LPAREN Expression RPAREN SCOLON {/*what happens when you macro the print*/;}
				{
					$$ = (char*)malloc((strlen($1) + strlen($3) + 10)*sizeof(char));
					strcpy($$,"System.out.println(");strcat($$,$3);strcat($$,");\n");
					free($1);free($3);
				}
				| IDENTIFIER EQ Expression SCOLON
				{
					$$ = (char*)malloc((strlen($1) + strlen($3) + 10)*sizeof(char));
					strcpy($$,$1);strcat($$,"=");strcat($$,$3);strcat($$,";");
					free($1);free($3);
				}
				| IDENTIFIER LSPAREN Expression RSPAREN EQ Expression SCOLON
				{
					$$ = (char*)malloc((strlen($1) + strlen($3) + strlen($6) + 10)*sizeof(char));
					strcpy($$,$1);strcat($$,"[");strcat($$,$3);strcat($$,"]=");strcat($$,$6);strcat($$,";");
					free($1);free($3);free($6);
				}
				| IF LPAREN Expression RPAREN Statement
				{
					$$ = (char*)malloc((strlen($3) + strlen($5) + 10)*sizeof(char));
					strcpy($$,"if(");strcat($$,$3);strcat($$,")");strcat($$,$5);
					free($3);free($5);
				}
				| IF LPAREN Expression RPAREN Statement ELSE Statement
				{
					$$ = (char*)malloc((strlen($3) + strlen($5) + strlen($7) + 15)*sizeof(char));
					strcpy($$,"if(");strcat($$,$3);strcat($$,")");strcat($$,$5);strcat($$,$7);
					free($3);free($5);free($7);
				}
				| WHILE LPAREN Expression RPAREN Statement
				{
					$$ = (char*)malloc((strlen($3) + strlen($5) + 10)*sizeof(char));
					strcpy($$,"while(");strcat($$,$3);strcat($$,")");strcat($$,$5);
					free($3);free($5);
				}
				|IDENTIFIER LPAREN CommaExpressionStar RPAREN SCOLON
				{
					$$ = (char*)malloc((strlen($1) + strlen($3) + 10)*sizeof(char));
					strcpy($$,$1);strcat($$,"(");strcat($$,$3);strcat($$,");");
					free($1);free($3);
				}
;
CommaIdentifierStar :	IDENTIFIER COMMA CommaIdentifierStar
						{
							$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
							strcpy($$,$1);strcat($$,",");strcat($$,$3);
							free($1);free($3);
						}
						| IDENTIFIER
						{
							$$ = (char*)malloc(strlen($1)*sizeof(char));
							strcpy($$,$1);
							free($1);
						}
						| {;}
;
MacroDefStatement	:	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LFPAREN StatementStar RFPAREN
						{

						}
;
MacroDefExpression : 	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LPAREN Expression RPAREN
						{

						}
;
CommaExpressionStar : 	Expression COMMA CommaExpressionStar
						{
							$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
							strcpy($$,$1);strcat($$,",");strcat($$,$3);
							free($1);free($3);
						}
						| Expression
						{
							$$ = (char*)malloc(strlen($1)*sizeof(char));
							strcpy($$,$1);
							free($1);
						}
						| {;}
;
Expression  :		PrimaryExpression AND AND PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($4) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"&&");strcat($$,$4);
						free($1);free($4);
					}
					| PrimaryExpression OR OR PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($4) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"||");strcat($$,$4);
						free($1);free($4);
					}
					| PrimaryExpression NOT EQ PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($4) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"!=");strcat($$,$4);
						free($1);free($4);
					}
					| PrimaryExpression LT EQ PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($4) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"<=");strcat($$,$4);
						free($1);free($4);
					}
					| PrimaryExpression PLUS PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"+");strcat($$,$3);
						free($1);free($3);
					}
					| PrimaryExpression MINUS PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"-");strcat($$,$3);
						free($1);free($3);
					}
					| PrimaryExpression MUL PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"*");strcat($$,$3);
						free($1);free($3);
					}
					| PrimaryExpression DIV PrimaryExpression
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"/");strcat($$,$3);
						free($1);free($3);
					}
					| PrimaryExpression LSPAREN PrimaryExpression RSPAREN
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"[");strcat($$,$3);strcat($$,"]");
						free($1);free($3);
					}
					| PrimaryExpression LENGTH
					{
						$$ = (char*)malloc((strlen($1) + 10)*sizeof(char));
						strcpy($$,$1);strcat($$,".length");
						free($1);
					}
					| PrimaryExpression 
					{
						$$ = (char*)malloc((strlen($1) + 10)*sizeof(char));
						strcpy($$,$1);
						free($1);
					}
					| PrimaryExpression DOT IDENTIFIER LPAREN CommaExpressionStar RPAREN
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + strlen($5) + 10)*sizeof(char));
						strcpy($$,$1);strcat($$,".");strcat($$,$3);
						strcat($$,"(");strcat($$,$5);strcat($$,")");
						free($1);free($3);free($5);
					}
					| IDENTIFIER LPAREN CommaExpressionStar RPAREN
					{
						$$ = (char*)malloc((strlen($1) + strlen($3) + 5)*sizeof(char));
						strcpy($$,$1);strcat($$,"(");strcat($$,$3);strcat($$,")");
						free($1);free($3);
					}
;
PrimaryExpression 	: 	NUM
						{
							$$ = (char*)malloc((strlen($1) + 5)*sizeof(char));
							strcpy($$,$1);
							free($1);
						}
						| TRUE	{$$ = (char*)malloc(10*sizeof(char));strcpy($$,"true");}
						| FALSE	{$$ = (char*)malloc(10*sizeof(char));strcpy($$,"false");}
						| IDENTIFIER
						{
							$$ = (char*)malloc((strlen($1) + 5)*sizeof(char));
							strcpy($$,$1);
							free($1);
						}
						| THIS	{$$ = (char*)malloc(10*sizeof(char));strcpy($$,"this");}
						| NEW INT LSPAREN Expression RSPAREN
						{
							$$ = (char*)malloc((strlen($4) + 15)*sizeof(char));
							strcpy($$,"new ");strcat($$,"int ");strcat($$,"[");
							strcat($$,$4);strcat($$,"]");
							free($4);
						}
						| NEW IDENTIFIER LPAREN RPAREN
						{
							$$ = (char*)malloc((strlen($2) + 10)*sizeof(char));
							strcpy($$,"new ");strcat($$,$2);strcat($$,"()");
							free($2);
						}
						| NOT Expression
						{
							$$ = (char*)malloc((strlen($2) + 10)*sizeof(char));
							strcpy($$,"!");strcat($$,$2);
							free($2);
						}
						| LPAREN Expression RPAREN
						{
							$$ = (char*)malloc((strlen($2) + 10)*sizeof(char));
							strcpy($$,"(");strcat($$,$2);strcat($$,")");
							free($2);
						}
;
Type 	: 	INT {$$ = (char*)malloc(10*sizeof(char));strcpy($$,"int ");}
			| BOOL	{$$ = (char*)malloc(10*sizeof(char));strcpy($$,"boolean ");}
			| INT LSPAREN RSPAREN
			{
				$$ = (char*)malloc(10*sizeof(char));strcpy($$,"int[] ");
			}
			| IDENTIFIER 
			{
				$$ = (char*)malloc((strlen($1) + 5)*sizeof(char));
				strcpy($$,$1);
				free($1);
			}
;
TypeIdentifierStar 	:	TypeIdentifierStar Type IDENTIFIER SCOLON
						{
							$$ = (char*)malloc((strlen($1) + strlen($2) + strlen($3) + 10)*sizeof(char));
							strcpy($$,$1);strcat($$,$2);strcat($$,$3);strcat($$,";");
							free($1);free($2);free($3);
						}
						| {;}
;
CommaTypeIdentifier :	Type IDENTIFIER 
						{
							$$ = (char*)malloc((strlen($1) + strlen($2) + 5)*sizeof(char));
							strcpy($$,$1);strcat($$,$2);
							free($1);free($2);
						}
						| Type IDENTIFIER COMMA CommaTypeIdentifier
						{
							$$ = (char*)malloc((strlen($1) + strlen($2) + strlen($4) + 10)*sizeof(char));
							strcpy($$,$1);strcat($$,$2);strcat($$,",");strcat($$,$4);
							free($1);free($2);free($4);
						}
						| {;}
;
MethodDeclaration	:	PUBLIC Type IDENTIFIER LPAREN CommaTypeIdentifier RPAREN LFPAREN TypeIdentifierStar 
						StatementStar RETURN Expression SCOLON RFPAREN
						{
							int l = strlen($8) + strlen($9) + strlen($11) + 20;
							$$ = (char*)malloc((strlen($2) + strlen($3) + strlen($5) + l)*sizeof(char));
							strcpy($$,"public ");strcat($$,$2);strcat($$,$3);strcat($$,"(");
							strcat($$,$5);strcat($$,"){");strcat($$,$8);strcat($$,$9);strcat($$,"return");
							strcat($$,$11);strcat($$,";}");
						}
;
MethodDeclarationStar	:	MethodDeclaration MethodDeclarationStar
							{
								$$ = (char*)malloc((strlen($1) + strlen($2))*sizeof(char));
								strcpy($$,$1);strcat($$,$2);
								free($1);free($2);
							}
							| {;}
;
TypeDeclaration	:	CLASS IDENTIFIER LFPAREN TypeIdentifierStar MethodDeclarationStar RFPAREN
					{
						$$ = (char*)malloc((strlen($2) + strlen($4) + strlen($5) + 15)*sizeof(char));
						strcpy($$,"class ");strcat($$,$2);strcat($$,"{");strcat($$,$4);
						strcat($$,$5);strcat($$,"}"):
						free($5);free($2);free($4);
					}
					| CLASS IDENTIFIER EXTENDS IDENTIFIER LFPAREN TypeIdentifierStar 
					  MethodDeclarationStar RFPAREN
					{
						int l = strlen($6) + strlen($7) + 15;
						$$ = (char*)malloc((strlen($2) + strlen($4) + l)*sizeof(char));
						strcpy($$,"class ");strcat($$,$2);strcat($$,"extends");strcat($$,$4);
						strcat($$,"{");strcat($$,$6);strcat($$,$7);strcat($$,"}");
						free($6);free($2);free($4);free($7);
					}
;
TypeDeclarationStar :	TypeDeclaration TypeDeclarationStar
						{
							$$ = (char*)malloc((strlen($1) + strlen($2))*sizeof(char));
							strcpy($$,$1);strcat($$,$2);
							free($1);free($2);
						}
						| {;}
;
%%