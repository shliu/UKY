#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include "calc3.h"
#include "y.tab.h"
#include "symbol_table.h"

#include "pstcode.h"
#include "apm.h"


extern "C" {
int ex(nodeType *p);
void pstack_begin(void);
void pstack_end(void);
}


extern int yylineno; /* added JWJ */

PstackCode * pstack = 0;

std::stack<int> myJpStack;
std::stack<int> myProcStack;

void pstack_begin(void)
{
    pushSymbolTable();
	pstack = new PstackCode();
	pstack->begin_prog();
}


void pstack_end(void)
{
    //popSymbolTable();
	pstack->end_prog(getCurrentSymbolTableSize());
	pstack->write("calc3.out.apm", true); //true = binary, false = human readable
}


int ex(nodeType *p) 
{
    if (!p) return 0;	
	
    switch(p->type) 
	{
		case typeIntCon:
		{
			//printf("Int constant\n");
			pstack->add(I_CONSTANT);
			pstack->add(p->conInt.value);
			return p->conInt.value;
		}
		case typeDoubleCon:
		{
			//printf("Double constant %f\n", p->conDbl.value);
			//I think this is where we need to add things to the pstack
			return p->conDbl.value;
		}
		case typeIntId:
		{
			struct symbol_entry *entry = getSymbolEntry(p->idInt.i);
			if(!entry)
			{
				printf("Undefined variable.\n");
				return 0;
			}
			pstack->add(I_VARIABLE);
			pstack->add(getCurrentLevel() - entry->blk_level);
			//pstack->add(0);		//WHY IS THIS ZERO?!	relative block level - current block level - variable block level
			pstack->add(entry->offset);
			pstack->add(I_VALUE);
			return entry->iVal;
		}
		case typeDblId:
			//printf("Double variable\n");
			return sym[p->idDbl.i];
		case typeOpr:
			switch(p->opr.oper) 
			{
				case BEGINSCOPE:
				{
					pushSymbolTable();
					pstack->add(I_CALL);
					pstack->add(0);		//MUST BE HERE: this sets the "call lev"
					pstack->add(pstack->pos()+3);	//MUST BE HERE: this sets the "address of proc"
					
					pstack->add(I_JR);
					myJpStack.push(pstack->pos());
					pstack->add(0);		//THIS VALUE WILL BE OVERRIDDEN LATER via pstack->at()
					//pstack->add(19);	//WE DON'T UNDERSTAND THIS MAGIC NUMBER
					
					pstack->begin_proc();
					break;
				}
				case ENDSCOPE:
				{
					
					pstack->at(myJpStack.top()) = pstack->pos() - myJpStack.top() + 2; //this overrides the above I_JP 
					//printf("difference: %d\n", pstack->pos() - myJpStack.top() + 1);
					
					pstack->end_proc(myJpStack.top() + 2, getCurrentSymbolTableSize());	//this overrides the 
					
					popSymbolTable();
					myJpStack.pop();
					break;
				}
				case DECLAREINT:
				{
					const char *name = p->opr.op[0]->idInt.i;
					
					struct symbol_entry *entry = getSymbolEntry(name);
					//create new symbol entry only if:
						//1) if there's no entry at all both locally and in scopes above local
						//2) OR if there exist an entry, but its scope is above local
					if(!entry	//no entry at all both locally and in scopes above local
						|| entry->blk_level < getCurrentLevel())	//there exist an entry, but its scope is above local
					{
						
						pstack->add(I_VARIABLE);
						pstack->add(0);	//always 0 here because we declare + assign here
						pstack->add(42);//dummy for offset
						
						
						int value = ex(p->opr.op[1]);
						entry = new symbol_entry();	
						entry->name = name;
						entry->iVal = value;
						entry->size = 1;
						addSymbol(entry, yylineno);
						
						pstack->at(pstack->pos() - 3) = entry->offset;
						
						pstack->add(I_ASSIGN);
						pstack->add(1);  //# words assigned
					
						//printf("currentLEVEL: %d", getCurrentLevel());
						
						free(entry);
					}
					else
					{
						printf("This int variable has already been declared.\n");
					}
					break;
				}
				case DO:
				{
					/*
					do 
					{
						ex(p->opr.op[0]);
					} while(ex(p->opr.op[1]));
					*/
					
					ex(p->opr.op[0]);
					
					
					int loop_start = pstack->pos();
				  /* Evaluate the while condition. */
				  ex(p->opr.op[1]);
				  /* If false, go to the end.  We will patch in the offset
				   * once we know the size of the loop body.
				   */
				  pstack->add(I_JR_IF_FALSE);
				  int patch_loc = pstack->pos();
				  pstack->add(0); /* placeholder */

				  /* Evaluate the body. */
				  ex(p->opr.op[0]);
				  /* Jump back to the beginning; this is a relative jump
				   * by the size of the loop's code, not including the
				   * jump instruction itself.
				   */
				  pstack->add(I_JR);
				  pstack->add(loop_start - (pstack->pos() - 1));

				  /* Now code->pos() is the end of the loop; patch the difference
				   * between that address and the I_JR_IF_FALSE instruction's into
				   * that instruction's operand.  patch_loc - 1 is the address of
				   * the instruction, patch_loc its operand.
				   */
				  pstack->at(patch_loc) = pstack->pos() - (patch_loc - 1);
				  
					break;
				}
				case WHILE:
				{
					/*					
					while(ex(p->opr.op[0]))
					{
						ex(p->opr.op[1]);
					}
					*/
					
					/* Remember the loop's starting address. */
				  int loop_start = pstack->pos();
				  /* Evaluate the while condition. */
				  ex(p->opr.op[0]);
				  /* If false, go to the end.  We will patch in the offset
				   * once we know the size of the loop body.
				   */
				  pstack->add(I_JR_IF_FALSE);
				  int patch_loc = pstack->pos();
				  pstack->add(0); /* placeholder */

				  /* Evaluate the body. */
				  ex(p->opr.op[1]);
				  /* Jump back to the beginning; this is a relative jump
				   * by the size of the loop's code, not including the
				   * jump instruction itself.
				   */
				  pstack->add(I_JR);
				  pstack->add(loop_start - (pstack->pos() - 1));

				  /* Now code->pos() is the end of the loop; patch the difference
				   * between that address and the I_JR_IF_FALSE instruction's into
				   * that instruction's operand.  patch_loc - 1 is the address of
				   * the instruction, patch_loc its operand.
				   */
				  pstack->at(patch_loc) = pstack->pos() - (patch_loc - 1);
				  
				  
				  
					break;
				}
				case REPEAT:
				{
					/*
					do 
					{
						ex(p->opr.op[0]);
					} while(!ex(p->opr.op[1]));
					*/
					
					
					ex(p->opr.op[0]);
					
					
					int loop_start = pstack->pos();
				  /* Evaluate the while condition. */
				  ex(p->opr.op[1]);
				  /* If false, go to the end.  We will patch in the offset
				   * once we know the size of the loop body.
				   */
				  pstack->add(I_JR_IF_TRUE);
				  int patch_loc = pstack->pos();
				  pstack->add(0); /* placeholder */

				  /* Evaluate the body. */
				  ex(p->opr.op[0]);
				  /* Jump back to the beginning; this is a relative jump
				   * by the size of the loop's code, not including the
				   * jump instruction itself.
				   */
				  pstack->add(I_JR);
				  pstack->add(loop_start - (pstack->pos() - 1));

				  /* Now code->pos() is the end of the loop; patch the difference
				   * between that address and the I_JR_IF_FALSE instruction's into
				   * that instruction's operand.  patch_loc - 1 is the address of
				   * the instruction, patch_loc its operand.
				   */
				  pstack->at(patch_loc) = pstack->pos() - (patch_loc - 1);
				  
					break;
				}
				case IF:       
				{				
				/*
					if (ex(p->opr.op[0]))
						ex(p->opr.op[1]);
					else if (p->opr.nops > 2)
						ex(p->opr.op[2]);
						*/
						
						
					ex(p->opr.op[0]);
					
					pstack->add(I_JR_IF_FALSE);
				  int patch_loc = pstack->pos();
				  pstack->add(0); /* placeholder */

				  
				  //Body of if(TRUE)
				  ex(p->opr.op[1]);
				  pstack->at(patch_loc) = pstack->pos() - (patch_loc - 1);
				  
				  pstack->add(I_JR);
				  pstack->add(0);	//patch placeholder to jump past else body
				  patch_loc = pstack->pos();
				  
				  //Body of if(FALSE) / else
				  ex(p->opr.op[2]);
					pstack->at(patch_loc) = pstack->pos() - (patch_loc - 1);
				
				  
				  
					
						
					return 0;
				}
				case PRINT:  
				{
					int expression = ex(p->opr.op[0]);
					printf("%d\n", expression); 
					pstack->add(I_WRITE);
					pstack->add(1);
					return 0;
				}
				case ';':     
				{
					ex(p->opr.op[0]); 
					return ex(p->opr.op[1]);
				}
				case '=':       
				{
					const char *name = p->opr.op[0]->idInt.i;
					
					int value = 0;
					
					struct symbol_entry *entry = getSymbolEntry(name);
					
					if(!entry)
					{
						printf("No variable by that name found\n");
					}
					else
					{
						entry->iVal = value;
						pstack->add(I_VARIABLE);
						pstack->add(getCurrentLevel() - entry->blk_level);
						pstack->add(entry->offset);
						
						ex(p->opr.op[1]);
						
						pstack->add(I_ASSIGN);
						pstack->add(1);  //# words assigned
					}
					
					
					return value;//sym[p->opr.op[0]->idInt.i] = ex(p->opr.op[1]);
				}
				case UMINUS:    return -ex(p->opr.op[0]);
				case '+':     
				{ 
					int sum = ex(p->opr.op[0]) + ex(p->opr.op[1]);  
					pstack->add(I_ADD);
					return sum;
				}
				case '-':      
				{
					int difference = ex(p->opr.op[0]) - ex(p->opr.op[1]);
					pstack->add(I_SUBTRACT);	
					return difference;
				}
				case '*':       
				{
					int product = ex(p->opr.op[0]) * ex(p->opr.op[1]);
					pstack->add(I_MULTIPLY);	
					return product;
				}
				case '/':    
				{
					int quotient = ex(p->opr.op[0]) / ex(p->opr.op[1]);
					pstack->add(I_DIVIDE);	
					return quotient;
				}
				case '<':     
				{
					int less = ex(p->opr.op[0]) < ex(p->opr.op[1]);
					pstack->add(I_LESS);	
					return less;
				}
				case '>':       
				{
					int greater = ex(p->opr.op[0]) > ex(p->opr.op[1]);
					pstack->add(I_GREATER);	
					return greater;
				}
				case GE:        return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
				case LE:        return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
				case NE:        
				{
					int ne = ex(p->opr.op[0]) != ex(p->opr.op[1]);
					pstack->add(I_NOT);
					return ne;
				}
				case EQ:    
				{				
					int eq = ex(p->opr.op[0]) == ex(p->opr.op[1]);
					pstack->add(I_EQUAL);	
					return eq;
				}
			}
		break; //case typeOpr
    }
    return 0;
}
