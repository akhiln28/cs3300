%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "expression.tab.h"
%}

%%
0|[1-9][0-9]*   {yylval.integer = atoi(yytext);return NUM;/* as the starting digit of a number cannot be zero*/ }
\+  {return PLUS;}
\-  {return MINUS;}
\*  {return MUL;}
\/  {return DIV;}
\=  {return EQUAL;} 
\(  {return OPENB;}
\)  {return CLOSEB;}
%%

