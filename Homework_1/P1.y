%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	int yylex();
	int yyerror();

	typedef struct Macro_
	{
		char *id;
		char *replaceWith;
		char **argList;
		int num_arg;
		bool type;
	}Macro;
	Macro List[10000];
	int num_macros = 0;

	char** getList(char *args,int *n)
	{
		int i;
		//size of list
		int l = strlen(args);
		*n = 1;
		for(i = 0;i < l;i++)
		{
			if(args[i] == ',')
			{
				(*n)++;
			}
		}
		char **list = (char**)malloc((*n)*sizeof(char*));
		for(i = 0;i < *n;i++)
		{
			list[i] = (char*)malloc((l)*sizeof(char));
		}
		int j = 0,k = 0;
		for(i = 0;i < l;i++)
		{
			if(args[i] == ',')
			{
				list[j][k] = '\0';
				k = 0;
				j++;
			}
			else
			{
				list[j][k] = args[i];
				k++;
			}
		}
		return list;
	}
	void addMacro(char *id,char *args,bool type,char *replaceWith)
	{
		//we need to check if the Macro is already present
		int i = 0;
		for(i = 0;i < num_macros;i++)
		{
			if(strcmp(id,List[i].id) == 0)
			{
				printf("Failed, macro already present\n");
				exit(0);
			}
		}
		//if id is not already present
		int n;
		List[num_macros].id = id;
		List[num_macros].argList = getList(args,&n);
		List[num_macros].replaceWith = replaceWith;
		List[num_macros].type = type;
		List[num_macros].num_arg = n;
		num_macros++;
		if(!type)
		{
			printf("added Macrostatement\n");
			//printf("%d\n",num_macros);
		}
		else
		{
			printf("added MacroExpression\n");
			//printf("%d\n",num_macros);
		}
	}

	char *replace(char *id,char *args,bool type)
	{
		//first we have to find the index of id
		int index = 0;
		bool flag = false;
		for(index = 0;index < num_macros;index++)
		{
			if(strcmp(id,List[index].id) == 0)
			{
				break;
				flag = true;
			}
		}
		// int i = 0;
		// printf("printing macros\n");
		// for(i = 0;i < num_macros;i++)
		// {
		// 	printf("%s\n",List[i].id);
		// }
		// printf("%s\n",id);
		//if the id is not present in the array, then it should be an error
		if(!flag)
		{
			if(!type)
			{
				printf("Failed,macro is absent, unable to replace in Macrostatement\n");
			}
			else
			{
				printf("Failed,macro is absent, unable to replace in MacroExpression\n");	
			}
			exit(0);
		}
		if(args == NULL)
		{
			if(List[index].num_arg == 0)
			{
				return List[index].replaceWith;
			}
			else
			{
				printf("Failed,Incorrect arguments passed in replace\n");
				exit(0);
			}
		}
		// int n;
		// char **argList = getList(args,&n);
		// if(n != List[index].num_arg)
		// {
		// 	printf("Failed to parse MacorJava\n");
		// 	exit(0);
		// }
	}
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
%type <str> CommaExpressionStar
%type <str> CommaIdentifierStar
%type <str> MethodDeclaration
%type <str> MethodDeclarationStar
%type <str> TypeDeclaration
%type <str> TypeDeclarationStar
%type <str> Type
%type <str> goal
%type <str> prog
%%
goal :	prog	{printf("good %s\n",$1);}
;
prog :		MacroDefinationstar MainClass TypeDeclarationStar
			{
				$$ = (char*)malloc((strlen($2) + strlen($3) + 10)*sizeof(char));
				strcpy($$,$2);strcat($$,$3);
				free($2);free($3);
			}
;
MainClass :	CLASS IDENTIFIER LFPAREN PUBLIC STATIC VOID MAIN LPAREN STRING LSPAREN RSPAREN
			IDENTIFIER RPAREN LFPAREN SYSTEM LPAREN Expression RPAREN SCOLON RFPAREN RFPAREN
			{
				int l = strlen($2) + strlen($12) + strlen($17) + 100;
				$$ = (char*)malloc(l*sizeof(char));
				strcpy($$,"class ");strcat($$,$2);strcat($$,"\n{ public static void main(String[]");
				strcat($$,$12);strcat($$,")\n{\n\tSystem.out.println(");strcat($$,$17);strcat($$,");\n}\n}");
				free($2);free($12);free($17);
			}
;
MacroDefinationstar :	MacroDefinationstar MacroDefination
						| {;}
;
MacroDefination :	MacroDefExpression | MacroDefStatement
;
StatementStar :		Statement StatementStar
					{
						$$ = (char*)malloc((strlen($1) + strlen($2) + 10)*sizeof(char));
						strcpy($$,$1);strcat($$,$2);
						free($1);free($2);
					}
					| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
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
						//here i need to replace this production(MacroExpression)
						$$ = replace($1,$3,true);
					}
;
Statement :		LFPAREN StatementStar RFPAREN
				{
					$$ = (char*)malloc((strlen($2) + 10)*sizeof(char));
					strcpy($$,"{");strcat($$,$2);strcat($$,"}\n");
					free($2);
				}
				| SYSTEM LPAREN Expression RPAREN SCOLON {/*what happens when you macro the print*/;}
				{
					$$ = (char*)malloc((strlen($3) + 30)*sizeof(char));
					strcpy($$,"System.out.println(");strcat($$,$3);strcat($$,");\n");
					free($3);
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
					//here i need to replace this production(Macrostatement)
					$$ = replace($1,$3,false);
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
						| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
;
MacroDefStatement	:	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LFPAREN StatementStar RFPAREN
						{
							//need to add the macro of type 0
							addMacro($2,$4,false,$7);
						}
;
MacroDefExpression : 	DEFINE IDENTIFIER LPAREN CommaIdentifierStar RPAREN LPAREN Expression RPAREN
						{
							//need to add macro of type 1
							addMacro($2,$4,true,$7);
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
						| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
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
						| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
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
						| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
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
								$$ = (char*)malloc((strlen($1) + strlen($2) + 10)*sizeof(char));
								strcpy($$,$1);strcat($$,$2);
								free($1);free($2);
							}
							| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
;
TypeDeclaration	:	CLASS IDENTIFIER LFPAREN TypeIdentifierStar MethodDeclarationStar RFPAREN
					{
						$$ = (char*)malloc((strlen($2) + strlen($4) + strlen($5) + 15)*sizeof(char));
						strcpy($$,"class ");strcat($$,$2);strcat($$,"{");strcat($$,$4);
						strcat($$,$5);strcat($$,"}");
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
							$$ = (char*)malloc((strlen($1) + strlen($2) + 10)*sizeof(char));
							strcpy($$,$1);strcat($$,$2);
							free($1);free($2);
						}
						| {$$=(char*)malloc(2*sizeof(char));strcpy($$,"");}
;
%%