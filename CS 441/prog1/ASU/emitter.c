/******    emitter.c   **from Aho, Sethi, Ullman****/

#include "global.h"
#include <stdlib.h>

void emit(int t, int tval)  /* generates output  ********/
{
	switch(t){
		case MULT:
			printf("*\n"); break;
		case PLUS: 
			printf("+\n"); break;
		case MINUS: 
			printf("-\n"); break;
		case DIVIDE: 
			printf("/\n"); break;
			
		case DIV:
			printf("DIV\n"); break;
		case MOD:
			printf("MOD\n"); break;
		case NUM:
			printf("%d\n", tval); break;
		case ID:
			printf("%s\n", lookupNameval(yylval.s)->name); break;
		default:
			printf("token %d, tokenval %d\n",t, tval);
	}
}

