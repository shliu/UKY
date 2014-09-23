#include <stdio.h>
#include <string.h>
#include "global.h"

// Get a line from the format file.  Space should have been allocated for the
// parameters before calling this file and the file should have been opened.
// (note: name should be a 2 character array so we can treat it like a string)
//
// get_format_line returns 0 on success and -1 on end of file or error
int get_format_line(FILE *format_file, int *type, int *array_size, char *name) {
    char line[MAXLINE];
    char *var_type;

    // Read a line from the file -- this assumes it has already been opened
    if (fgets(line, MAXLINE, format_file) != NULL) {

        // find the type
        var_type = strtok(line, " ");
        if (!strcmp(var_type, "char")) *type = CHAR_type;
        else if (!strcmp(var_type, "ushort")) *type = USHORT_type;
        else if (!strcmp(var_type, "uint")) *type = UINT_type;
        else if (!strcmp(var_type, "ulong")) *type = ULONG_type;

        // find the size
        *array_size = atoi(strtok(NULL, " "));

        // find the name
        strcpy(name,strtok(NULL, " "));

        if (DEBUG_FORMAT)
            printf("  Debug Format Line: type=%d, size=%d, %%name=%s\n",
                                         *type, *array_size, name);
	return(0);
    }
    else return(-1); // to indicate end of file
}