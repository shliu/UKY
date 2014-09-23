#include <stdio.h>
#include "global.h"


int main(int argc, char *argv[])
{
	FILE *data_file = fopen(argv[1], "r");
	if(data_file == NULL)
	{
		printf("error opening DATA file\n");
		return(-1);
	}
	
	FILE *format_file = fopen(argv[2], "r");
	if(format_file == NULL)
	{
		printf("error opening FORMAT file\n");
		return(-1);
	}
	
	//set default data structure array size
	int i = 0;
	while(i < MAX_VARIABLES)
	{
		variables[i].size = 0;
		i++;
	}
	
	//read *.format file and populate data structure with content from *.data file
	int type; 
	int array_size;
	char name[2];
	while(get_format_line(format_file, &type, &array_size, name) == 0)
	{
		get_data_line(data_file, type, array_size, name);
	}
	
	fclose(format_file);
	fclose(data_file);
	
	//print data stored
	print_all_elements();
	
	printf("--------------\n");
	
	//take user input and perform printing/operations
	char op[1];
	char var1[2];
	char var2[2];
	while(scanf("%1s %2s", op, var1) >= 0)
	{
		printf("-----> ");
		if(op[0] == '!' || op[0] == '=')
		{
			switch(op[0])
			{
				case '=':
					print_element(var1, QUIET);
					break;
				case '!':
					bitwise_invert(var1);
					break;
			}
		}
		else //|, &, ^, <, >
		{
			scanf("%2s", var2);
			switch(op[0])
			{
				case '|':
					bitwise_or(var1, var2);
					break;
				case '&':
					bitwise_and(var1, var2);
					break;
				case '^':
					bitwise_xor(var1, var2);
					break;
				case '>':
					bitwise_shift_right(var1, var2);
					break;
				case '<':
					bitwise_shift_left(var1, var2);
					break;
			}
		}
	}
	
	
	return 0;
}



