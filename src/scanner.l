/* The code is taken from the book `flex & bison` by John Levine. */

%option nounput noinput
%{
#include "parser.h"

void yyerror(char *s, ...);
%}

%%

"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
"|"     { return ABS; }
"("     { return OP; }
")"     { return CP; }
[0-9]+  { yylval = atoi(yytext); return NUMBER; }

\n      { return EOL; }
"//".*
[ \t]   { /* Ignore white space. */ }
.       { yyerror("Unknown character %c\n", *yytext); }

%%
