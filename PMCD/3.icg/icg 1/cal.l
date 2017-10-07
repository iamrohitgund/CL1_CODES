%{
#include "y.tab.h"
#include<stdio.h>
extern int yyerror(char *e);

%}

%%


[a-zA-Z]+ {yylval.dname=strdup(yytext);
		return id;}
[ \t]+ 

\n return 0;
. return yytext[0];
%%
int yywrap()
{
	return 1;
}

