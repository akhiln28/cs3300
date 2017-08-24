%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%union{
	int integer;
	char* string;
}

%token<integer> NUM
%token<string> PLUS MINUS MUL DIV EQUAL OPEN CLOSE
%start goal
%type<integer> expr term

%%
goal: expr {printf("The value of the expression is: %d\n",$1);};

expr: expr PLUS term {$$ = $1 + $3;} 
    | expr MINUS term {$$ = $1 - $3;} 
    | term {$$ = $1;};

term: term MUL NUM {$$ = $1 * $3;} 
    | term DIV NUM {$$ = $1 / $3;} 
    | OPENB expr CLOSEB {$$ = $2;printf("within brackets is : %d\n",$2);};
    | NUM {$$ = $1;}
%%
int yywrap() {return 1;}
int yyerror(char* s) {fprintf(stderr,"Parse error\n");}

int main()
{
	yyparse();
	return 0;
}
