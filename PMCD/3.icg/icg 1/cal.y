%{
	#include<stdio.h>
	#include<math.h>
	#include<stdlib.h>
	extern int yylex();
	extern int yyparse();
	extern int yyerror(char *e);
	struct quadadd
	{
		char op;
		char *arg1;
		char *arg2;
		char *arg3;
	}q[10];
	char* addquad(char ,char *,char *,char *);
	char *returnRes();
	int i=0;
	int k=0;
	
%}

%union
{
	
	char *dname;
	
}

%token <dname>id
%right '='
%left '+' '-'
%left '*' '/'

%type <dname>exp
%start S
%%
S :exp { display(); }
  ; 
exp:exp '+' exp {$$ = addquad('+',$1,$3,returnRes());}
   |exp '-' exp {$$ = addquad('-',$1,$3,returnRes());}
   |exp '*' exp {$$ = addquad('*',$1,$3,returnRes());}
   |exp '/' exp {
   			$$=addquad('/',$1,$3,returnRes());
		}
    
    |exp '=' exp {$$=addquad('=',$3,"",$1);}
    | id {$$ = $1;}
    ;
	
%%
char *addquad(char a,char *b,char *c,char *d)
{
	q[i].op=a;
	q[i].arg1=b;
	q[i].arg2=c;
	q[i++].arg3=d;
	return d;
	
}
char *returnRes()
{
	char *temp;
	temp=(char *)malloc(3*sizeof(char));
	temp[0]='t';
	temp[1]=48+k++;
	temp[2]='\0';
	return temp;
}
void display()
{	printf("| ------------------------ |\n");
	printf("| op   arg1    arg2    res |\n");
	printf("| ------------------------ |\n");
	int j=0;
	for(j=0;j<i;j++)
	{
		printf("|%4c   ",q[j].op);
		printf("%4s   ",q[j].arg1);
		printf("%4s   ",q[j].arg2);
		printf("%4s   |\n",q[j].arg3);			
	}
}
int main()
{
	yyparse();
}
extern int yyerror(char *e)
{
	printf("Error is %s\n",e);

}
