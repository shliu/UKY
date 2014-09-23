/*** parser.c  *****from Aho, Sethi, Ullman**************/

#include "global.h"

int lookahead;
void parse(void)   /*parses and translates expression list  */
{
	lookahead = yylex();
	while(lookahead != DONE) {
		expr(); match(SEMI);
	}
}

void expr(void)
{
	int t;
	term();
	while(1)
		switch (lookahead) {
		case PLUS: case MINUS:
			t=lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
	}
}
void term(void)
{
	int t;
	factor();
	while(1)
		switch(lookahead) {
		case MULT: case DIVIDE : case DIV: case MOD:
			t=lookahead;
			match(lookahead); factor(); emit (t, NONE);
			continue;
		default:
			return;
		}
}

void factor(void)
{
		switch(lookahead) {
			case LPAREN:
				match(LPAREN); expr(); match(RPAREN); break;
			case NUM:
				emit(NUM, yylval.i); match(NUM); break;
			case ID:
				emit(ID, yylval.i); match(ID); break;
			default:
				/* error("syntax error"); */
				printf(" | %d | ", lookahead);
				error("syntax error in factor()");
	}
}

void match(int t)
{
	if (lookahead == t)
		lookahead = yylex();
	else 
	{
		/* error("syntax error"); */
		error("syntax error in match()");
	}
}

