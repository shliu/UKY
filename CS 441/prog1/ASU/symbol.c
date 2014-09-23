/****    symbol.c   ****from Aho, Sethi, Ullman****/

#include "global.h" /*contains def of symboltable*/
#include <string.h>
#include <stdlib.h>


unsigned int hash( char *str );


enum
{
	MULTIPLIER = 31
};


Nameval* lookupNameval( char name[] )
{
	int h;
	Nameval *sym;
	
	h = hash(name);
	for( sym = symtab[h]; sym != NULL; sym = sym->next )
	{
		if( strcmp( name, sym->name ) == 0 )
		{
			return sym;
		}
	}
	return NULL;
}





int lookup( char name[] )
{
	Nameval *sym = lookupNameval(name);
	
	if( sym != NULL )
		return sym->value;
	return 0;
}



int insert( char name[], int value )
{
	int h;
	Nameval *sym;
	
	h = hash(name);
	sym = symtab[h];
	
	sym = (Nameval *)malloc( sizeof( Nameval ) );
	sym->name = name;
	sym->value = value;
	sym->next = symtab[h];
	symtab[h] = sym;
		
	return sym->value;
}






unsigned int hash( char *str )
{
	unsigned int h;
	unsigned char *p;
	
	h = 0;
	for( p = (unsigned char *)str; *p != '\0'; p++ )
	{
		h = MULTIPLIER * h + *p;
	}
	return h % NHASH;
}