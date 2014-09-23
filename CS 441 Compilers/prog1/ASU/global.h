/***global.h******from Aho, Sethi, Ullman*************************************/

#include <stdio.h>
#include <ctype.h>

#define BSIZE 128
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID  259
#define DONE 260

#define MULT 261
#define PLUS 262
#define MINUS 263
#define LPAREN 264
#define RPAREN 265
#define NEWLINE 266
#define DIVIDE 267
#define SEMI 268

#define SYMMAX 100   /* size of symtable */
#define NHASH 101

int tokenval;    /* value of token atribute  */
extern int lineno;



struct entry { /* form of symbol table entry */
char *lexptr;
int token;
};
struct entry symtable[SYMMAX]; /* symbol table */



/* hash table symbol table structure */
typedef struct Nameval Nameval;
struct Nameval	/* hash chain node */
{
	char *name;
	int value;
	Nameval *next;
};
Nameval *symtab[NHASH];		/* hash table */






void error(char *m);

Nameval* lookupNameval(char name[]);
int lookup(char name[]);
int insert(char name[], int value);

void parse(void);
void expr(void);

int lexan(void);
void match(int t);
void term(void);
void emit(int t, int tval);
void factor(void);
void init(void);


extern int yylex(void);

union {
	int i;
	char *s;
	} yylval;