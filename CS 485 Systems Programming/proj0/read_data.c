#include <stdio.h>
#include "global.h"

void get_data_line(FILE *data_file, int type, int array_size, char *name)
{
	int var_idx = name[0]-'a';
	variables[var_idx].type = type;
	variables[var_idx].size = array_size;
	
	int array_pos = 0;
	while(array_pos < array_size)
	{
		switch(type)
		{
			case CHAR_type:
				fread(&variables[var_idx].data[array_pos].c, sizeof(char), 1, data_file);
				break;
			case USHORT_type:
				fread(&variables[var_idx].data[array_pos].s, sizeof(unsigned short), 1, data_file);
				break;
			case UINT_type:
				fread(&variables[var_idx].data[array_pos].i, sizeof(unsigned int), 1, data_file);
				break;
			case ULONG_type:
				fread(&variables[var_idx].data[array_pos].l, sizeof(unsigned long), 1, data_file);
				break;
		}
		array_pos++;
	}
}