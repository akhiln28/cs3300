%{
	#include <stdio.h>
%}

%%
\+	{ printf("What the fuck, you mean plus");}
[a-zA-Z]+	{ printf("you mean a word or letter");}
%%