#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
#include "symbol_table.h"

extern int yylineno; /* added JWJ */

int ex(nodeType *p) 
{
    if (!p) return 0;	
	
	pushSymbolTable();
	
    switch(p->type) 
	{
		case typeIntCon:
			//printf("Int constant\n");
			return p->conInt.value;
		case typeDoubleCon:
			//printf("Double constant %f\n", p->conDbl.value);
			return p->conDbl.value;
		case typeIntId:
		{
			struct symbol_entry *entry = getSymbolEntry(p->idInt.i);
			if(!entry)
			{
				printf("Undefined variable.\n");
				return 0;
			}
			return entry->iVal;
		}
		case typeDblId:
			//printf("Double variable\n");
			return sym[p->idDbl.i];
		case typeOpr:
			switch(p->opr.oper) 
			{
				case DECLAREINT:
				{
					const char *name = p->opr.op[0]->idInt.i;	
					int value = ex(p->opr.op[1]);
					
					struct symbol_entry *entry = getSymbolEntry(name);
					if(!entry)	//make sure this variable name doesn't already exists
					{
						//entry = calloc(1, sizeof(struct symbol_entry)+300);
						entry = malloc(sizeof(struct symbol_entry));
						entry->name = name;
						entry->iVal = value;
						addSymbol(entry, yylineno);
						free(entry);
					}
					else
					{
						printf("This int variable has already been declared.\n");
					}
				
					break;
				}
				case DO:
					do 
					{
						ex(p->opr.op[0]);
					} while(ex(p->opr.op[1]));
					break;
				case WHILE:
					while(ex(p->opr.op[0]))
					{
						ex(p->opr.op[1]);
					}
					break;
				case REPEAT:
					do 
					{
						ex(p->opr.op[0]);
					} while(!ex(p->opr.op[1]));
					break;
				case IF:        
					if (ex(p->opr.op[0]))
						ex(p->opr.op[1]);
					else if (p->opr.nops > 2)
						ex(p->opr.op[2]);
					return 0;
				case PRINT:  
				{
					printf("%d\n", ex(p->opr.op[0])); 
					return 0;
				}
				case ';':       
					ex(p->opr.op[0]); 
					return ex(p->opr.op[1]);
				case '=':       
				{
					const char *name = p->opr.op[0]->idInt.i;
					int value = ex(p->opr.op[1]);
					
					struct symbol_entry *entry = getSymbolEntry(name);
					
					if(!entry)
					{
						printf("No variable by that name found\n");
					}
					else
					{
						entry->iVal = value;
					}
					
					return value;//sym[p->opr.op[0]->idInt.i] = ex(p->opr.op[1]);
				}
				case UMINUS:    return -ex(p->opr.op[0]);
				case '+':       return ex(p->opr.op[0]) + ex(p->opr.op[1]);
				case '-':       return ex(p->opr.op[0]) - ex(p->opr.op[1]);
				case '*':       return ex(p->opr.op[0]) * ex(p->opr.op[1]);
				case '/':       return ex(p->opr.op[0]) / ex(p->opr.op[1]);
				case '<':       return ex(p->opr.op[0]) < ex(p->opr.op[1]);
				case '>':       return ex(p->opr.op[0]) > ex(p->opr.op[1]);
				case GE:        return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
				case LE:        return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
				case NE:        return ex(p->opr.op[0]) != ex(p->opr.op[1]);
				case EQ:        return ex(p->opr.op[0]) == ex(p->opr.op[1]);
			}
		break; //case typeOpr
    }
    return 0;
}
