
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

/* Added JWJ */
#ifdef __cplusplus
extern "C" {
#endif

struct symbol_entry {
	int 	addr;
	int 	blk_level;
	int 	type;
	int 	size;
	int 	offset;
   union { /* Added */
     int iVal;
     double fVal;
   };
	const char *name; /* changed JWJ */
};

extern void printSymbolTable(void);
extern void popSymbolTable(void);
extern void pushSymbolTable(void); // once
extern void addSymbol(struct symbol_entry*, int lineno); // need this
extern struct symbol_entry* getSymbolEntryByRelAddr(int, int);
extern struct symbol_entry* getSymbolEntry(const char *); // need this
extern int getTotalSymbolTableSize(void);
extern int getCurrentSymbolTableSize(void);
extern int getSymbolTableSize(int);
extern int getCurrentLevel(void);

/* Added JWJ */
#ifdef __cplusplus
}
#endif

#endif /* SYMBOL_TABLE_H */

