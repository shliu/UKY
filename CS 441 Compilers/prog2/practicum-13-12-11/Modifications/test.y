%union {
	int i;
	char* s;
}

%token LPAREN RPAREN PLUS MINUS MULT DIV NEWLINE
%token <s> NUMBER
%token <s> IDEN
%token <s> expr term factor


%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char*);
int yylex(void);
%}

%%

program:
	program expr NEWLINE	{ printf("%s\n", $2); }
	| /*epsilon*/
	;

/*$1 first element, $2 second element, etc*/
expr:
	term			{ $$=$1; } //$$ = left hand side
	| expr PLUS expr	{ sprintf($$, "%s %s + ", $1, $3); }
	| expr MINUS expr	{ sprintf($$, "%s %s - ", $1, $3); }
	;

term:
	factor			{ $$=$1; }
	| term MULT term	{ sprintf($$, "%s %s * ", $1, $3); }
	| term DIV term		{ sprintf($$, "%s %s / ", $1, $3); }
	; 
	
factor:
	LPAREN expr RPAREN	{ sprintf($$, "%s", $2); }
	| NUMBER		{ $$ = $1; }
	| IDEN			{ $$ = $1; }
	;

%%


void yyerror(char *s)
{
	fprintf(stderr, "%s\n", 	
}
