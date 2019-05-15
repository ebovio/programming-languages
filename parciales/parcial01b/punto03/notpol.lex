
%{
#define YYSTYPE int
#include "notpolparser.h"
#include <stdlib.h>
%}
%option noyywrap

white [ \t]+
digit [0-9]
integer {digit}+
%%

{white} { }
{integer} { yylval=atoi(yytext);
            return NUMBER;
           }

"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;
"(" return LEFT;
")" return RIGHT;
"\n" return EOL;
<<EOF>> return EOF;
