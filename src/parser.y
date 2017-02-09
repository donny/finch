/* The code is taken from the book `flex & bison` by John Levine. */

%{
#include <stdio.h>
#include <stdarg.h>
#include <libfinch.h>

void yyerror(char *s, ...);
int yylex();
%}

/* Declare tokens. */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token OP CP
%token EOL

%%

calclist: /* Nothing. */
 | calclist exp EOL { printf("= %d\n> ", $2); }
 | calclist EOL { printf("> "); } /* Blank line or a comment. */
 ;

exp: factor
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 | exp ABS factor { $$ = $1 | $3; }
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: NUMBER
 | ABS term { $$ = $2 >= 0? $2 : - $2; }
 | OP exp CP { $$ = $2; }
 ;

%%

int main()
{
  printf("> ");
  yyparse();
  finch_print_color(RED, "DONE");
  return 0;
}

void yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);
  fprintf(stderr, "Error: ");
  vfprintf(stderr, s, ap);
  va_end(ap);
}
