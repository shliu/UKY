#include <stdio.h>
#include "global.h"


void print_element(char *var, int verbose)
{
	int var_idx = var[0] - 'a';
	int elem_idx = var[1] - '0';
	
	if(verbose)
	{
		printf("%c%c = ", var[0], var[1]);
	}
	switch(variables[var_idx].type)
	{
		case CHAR_type:
			printf("%c\n", variables[var_idx].data[elem_idx].c);
			break;
		case USHORT_type:
			printf("0x%hX\n", variables[var_idx].data[elem_idx].s);
			break;
		case UINT_type:
			printf("0x%X\n", variables[var_idx].data[elem_idx].i);
			break;
		case ULONG_type:
			printf("0x%lX\n", variables[var_idx].data[elem_idx].l);
			break;
	}
}


void print_all_elements()
{
	int i = 0;
	while(i < MAX_VARIABLES)
	{
		int j = 0;
		while(j < variables[i].size)
		{
			char var[2] = {i+'a', j+'0'};
			print_element(var, VERBOSE);
			j++;
		}
		i++;
	}
}