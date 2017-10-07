%{
	#include<stdio.h>
	#include<math.h>
	extern int yyerror(char *e);
	extern int yylex();
	extern int yyparse();
%}
%union
{
	double dval;
	char dname;
}
%token <dval> num
%type <dval> exp
%token <dname> name
%token SIN COS TAN ROOT LOG CUBE POWER SQUARE
%left '+' '-'
%left '*' '/'
%%
S : name '=' exp {printf("\n%c = %.2f",$1,$3); printf("\n");}
    | exp	{printf("\n Result = %.2f",$1); printf("\n");}
    ; 

exp : exp '*' exp {$$ = $1 * $3;}
      | exp '/' exp {
      		    	if($3==0)
      		    		{
      		    			yyerror("Divide by zero error.."); 
      		    			exit(0);
      		    		}
      		   	 else
      		    		{$$ = $1 / $3;}
      		    }
      | exp '+' exp {$$ = $1 + $3;}
      | exp '-' exp {$$ = $1 - $3;}
      | SIN '(' exp ')'	{$$ = sin($3*3.141/180);}
      | COS '(' exp ')'	{$$ = cos($3*3.141/180);}
      | TAN '(' exp ')'	{$$ = tan($3*3.141/180);}
      | ROOT '(' exp ')' {$$ = sqrt($3);}
      | LOG '(' exp ')' {$$ = log($3);}
      | CUBE '(' exp ')' {$$ = $3*$3*$3;}
      | SQUARE '(' exp ')' {$$ = $3*$3;}
      | POWER '(' exp ',' exp ')' {$$ = pow($3,$5);}
      | '(' exp ')' {$$ = $2;}
      | num
      ;
%%
int main()
{
	printf("\nEnter a expression...\n");
	yyparse();
	return 0;
}

extern int yyerror(char *e)
{
	printf("\n%s\n",e);
}

