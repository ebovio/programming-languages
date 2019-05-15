
%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE int

// Declaration of errors 
int yylex();
int yyerror(char *s);

%}

%token NUMBER
%token PLUS MINUS TIMES DIVIDE
%token LEFT RIGHT
%token EOL

%start expression
%%

expression : notpol EOL                     { printf(" = %d\n", $1);
                                                 exit(0); }
           |                                   { exit(0); }
           ;


notpol:
        |       LEFT PLUS notpol notpol RIGHT         { $$=$3+$4; }
        |       LEFT MINUS notpol notpol RIGHT        { $$=$3-$4; }
        |       LEFT TIMES notpol notpol RIGHT        { $$=$3*$4; }
        |       LEFT DIVIDE notpol notpol RIGHT       { $$=$3/$4; }
        |       NUMBER                                { $$=$1; }                                         
        ;
%%

int yyerror(char *s) {
  printf("%s\n", s);
}

int main() {
  if (yyparse())
    fprintf(stderr, "Calculator end.\n");
  else
    fprintf(stderr, "error found.\n");
}
