%{
	#include <math.h>
	#include "global.h"
	#include <stdlib.h>

	int lineno = 0;
	int yywrap(void) {return 1;}
%}
/* ********* DEFINITIONS ********* */
delim [\t ]
ws {delim}+
digit [0-9]
num {digit}+
alpha [_a-zA-Z]
identifier {alpha}({alpha}|{digit})*


%%



{ws} {/* skip blanks and tabs */}
{num} {
	yylval.i = atoi(yytext); 
	return NUM;
	}
{identifier} {
	int p = 0;
	p = lookup(yytext);
	if( p == 0 )
	{
		p = insert(yytext, ID);
	}
	
	yylval.s = yytext;
	
	return lookup(yytext);
	}
"*" {return MULT;}
"+" {return PLUS;}
"-" {return MINUS;}
"/" {return DIVIDE;}
"(" {return LPAREN;}
")" {return RPAREN;}
"\n" {lineno++; return DONE;}
";"	{return SEMI;}
. {
	printf ("Unrecognizable token: [%s]\n", yytext);
	}

%%

/*
not needed when this is part of another larger project
int main(void)
{
	return 0;
}
*/