%{	
	#include "y.tab.h"
	extern int yyerror(char *e);
%}

%%
[0-9]+|[0-9]+\.[0-9]+ {yylval.dval = atof(yytext); return num;}
sin {return (SIN);}
cos {return (COS);}
tan {return (TAN);}
root {return (ROOT);}
log {return (LOG);}
cube {return (CUBE);}
power {return (POWER);}
square {return (SQUARE);}
[()] {return yytext[0];}
[a-zA-Z]+ {yylval.dname = yytext[0]; return name;}
[ \t]+ 
\n return 0;
. return yytext[0];
%%
int yywrap()
{
	return 1;
}
