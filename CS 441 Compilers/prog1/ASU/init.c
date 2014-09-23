/****  init.c  ***from Aho, Sethi, Ullman*********/

#include <stdlib.h> /* for NULL */
#include "global.h"

struct entry keywords[] = {
	{"div", DIV},
	{"mod", MOD},
	{NULL,     0}
};
void init()   /* loads keywords into symtable  */
{
	struct entry *p;
	for (p= keywords; p-> token; p++)
		insert(p->lexptr, p-> token);
}


