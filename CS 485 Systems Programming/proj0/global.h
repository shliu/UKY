#define DEBUG_FORMAT 0
#define MAXLINE 40

#define CHAR_type   0
#define USHORT_type 1
#define UINT_type   2
#define ULONG_type  3

#define MAX_VARIABLES   26
#define MAX_ELEMENTS   10

#define QUIET 0
#define VERBOSE 1


union Data
{
	char c;
	unsigned short s;
	unsigned int i;
	unsigned long l;
};

struct Variable
{
	int type;
	int size;
	union Data data[MAX_ELEMENTS];
};

struct Variable variables[MAX_VARIABLES];