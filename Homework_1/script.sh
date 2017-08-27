# !bin/bash
bison -d P1.y
flex P1.l
gcc lex.yy.c P1.tab.c 
./a.out < X.Java