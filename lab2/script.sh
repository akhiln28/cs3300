# !bin/bash
flex expression.l
bison -d expression.y
gcc lex.yy.c expression.tab.c 
./a.out
