#include <stdio.h>
#include "global.h"

void bitwise_invert(char *var)
{
	int var_idx = var[0] - 'a';
	int elem_idx = var[1] - '0';
	
	switch(variables[var_idx].type)
	{
		case CHAR_type:
			printf("%c\n", ~variables[var_idx].data[elem_idx].c);
			break;
		case USHORT_type:
			printf("0x%hX\n", ~variables[var_idx].data[elem_idx].s);
			break;
		case UINT_type:
			printf("0x%X\n", ~variables[var_idx].data[elem_idx].i);
			break;
		case ULONG_type:
			printf("0x%lX\n", ~variables[var_idx].data[elem_idx].l);
			break;
	}
}

  
void bitwise_or(char *var1, char *var2)
{
	int var1_idx = var1[0] - 'a';
	int elem1_idx = var1[1] - '0';
	
	int var2_idx = var2[0] - 'a';
	int elem2_idx = var2[1] - '0';
	
	switch(variables[var1_idx].type)
	{
		case CHAR_type:
			printf("%c\n", (char)(variables[var1_idx].data[elem1_idx].c | variables[var2_idx].data[elem2_idx].c));
			break;
		case USHORT_type:
			printf("0x%hX\n", (unsigned short)(variables[var1_idx].data[elem1_idx].s | variables[var2_idx].data[elem2_idx].s));
			break;
		case UINT_type:
			printf("0x%X\n", (unsigned int)(variables[var1_idx].data[elem1_idx].i | variables[var2_idx].data[elem2_idx].i));
			break;
		case ULONG_type:
			printf("0x%lX\n", (unsigned long)(variables[var1_idx].data[elem1_idx].l | variables[var2_idx].data[elem2_idx].l));
			break;
	}
}


void bitwise_and(char *var1, char *var2)
{
	int var1_idx = var1[0] - 'a';
	int elem1_idx = var1[1] - '0';
	
	int var2_idx = var2[0] - 'a';
	int elem2_idx = var2[1] - '0';
	
	switch(variables[var1_idx].type)
	{
		case CHAR_type:
			printf("%c\n", (char)(variables[var1_idx].data[elem1_idx].c & variables[var2_idx].data[elem2_idx].c));
			break;
		case USHORT_type:
			printf("0x%hX\n", (unsigned short)(variables[var1_idx].data[elem1_idx].s & variables[var2_idx].data[elem2_idx].s));
			break;
		case UINT_type:
			printf("0x%X\n", (unsigned int)(variables[var1_idx].data[elem1_idx].i & variables[var2_idx].data[elem2_idx].i));
			break;
		case ULONG_type:
			printf("0x%lX\n", (unsigned long)(variables[var1_idx].data[elem1_idx].l & variables[var2_idx].data[elem2_idx].l));
			break;
	}
}


void bitwise_xor(char *var1, char *var2)
{
	int var1_idx = var1[0] - 'a';
	int elem1_idx = var1[1] - '0';
	
	int var2_idx = var2[0] - 'a';
	int elem2_idx = var2[1] - '0';
	
	switch(variables[var1_idx].type)
	{
		case CHAR_type:
			printf("%c\n", (char)(variables[var1_idx].data[elem1_idx].c ^ variables[var2_idx].data[elem2_idx].c));
			break;
		case USHORT_type:
			printf("0x%hX\n", (unsigned short)(variables[var1_idx].data[elem1_idx].s ^ variables[var2_idx].data[elem2_idx].s));
			break;
		case UINT_type:
			printf("0x%X\n", (unsigned int)(variables[var1_idx].data[elem1_idx].i ^ variables[var2_idx].data[elem2_idx].i));
			break;
		case ULONG_type:
			printf("0x%lX\n", (unsigned long)(variables[var1_idx].data[elem1_idx].l ^ variables[var2_idx].data[elem2_idx].l));
			break;
	}
}


void bitwise_shift_right(char *var1, char *var2)
{
	int var1_idx = var1[0] - 'a';
	int elem1_idx = var1[1] - '0';
	
	int var2_idx = var2[0] - 'a';
	int elem2_idx = var2[1] - '0';
	
	switch(variables[var1_idx].type)
	{
		case CHAR_type:
			printf("%c\n", (char)(variables[var1_idx].data[elem1_idx].c >> variables[var2_idx].data[elem2_idx].c));
			break;
		case USHORT_type:
			printf("0x%hX\n", (unsigned short)(variables[var1_idx].data[elem1_idx].s >> variables[var2_idx].data[elem2_idx].s));
			break;
		case UINT_type:
			printf("0x%X\n", (unsigned int)(variables[var1_idx].data[elem1_idx].i >> variables[var2_idx].data[elem2_idx].i));
			break;
		case ULONG_type:
			printf("0x%lX\n", (unsigned long)(variables[var1_idx].data[elem1_idx].l >> variables[var2_idx].data[elem2_idx].l));
			break;
	}
}


void bitwise_shift_left(char *var1, char *var2)
{
	int var1_idx = var1[0] - 'a';
	int elem1_idx = var1[1] - '0';
	
	int var2_idx = var2[0] - 'a';
	int elem2_idx = var2[1] - '0';
	
	switch(variables[var1_idx].type)
	{
		case CHAR_type:
			printf("%c\n", (char)(variables[var1_idx].data[elem1_idx].c << variables[var2_idx].data[elem2_idx].c));
			break;
		case USHORT_type:
			printf("0x%hX\n", (unsigned short)(variables[var1_idx].data[elem1_idx].s << variables[var2_idx].data[elem2_idx].s));
			break;
		case UINT_type:
			printf("0x%X\n", (unsigned int)(variables[var1_idx].data[elem1_idx].i << variables[var2_idx].data[elem2_idx].i));
			break;
		case ULONG_type:
			printf("0x%lX\n", (unsigned long)(variables[var1_idx].data[elem1_idx].l << variables[var2_idx].data[elem2_idx].l));
			break;
	}
}