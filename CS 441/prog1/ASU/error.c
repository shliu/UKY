/***********  error.c **from Aho, Sethi, Ullman***********/

#include "global.h"
#include <stdlib.h>

void error(char *m)    /*generate all error messagese */
{
	fprintf(stderr, "line %d; %s\n", lineno, m);
	exit(1);  /* unsuccessful termination  */
}

