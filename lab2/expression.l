%{

%}

%%
\+  {return PLUS;}
\-  {return MINUS;}
\*  {return MUL;}
\/  {return DIV;}
[a-zA-z][a-zA-Z0-9]*    {return IDENTIFIER;}
0|[1-9][0-9]*   {return NUM;/* as the starting digit of a number cannot be zero*/ }
\(  {return OPEN_B;}
\)  {return CLOSE_B;}
\;  {return SEMICOLON;}
\=  {return EQUAL;}
%%

