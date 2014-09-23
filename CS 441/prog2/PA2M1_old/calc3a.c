#include <stdio.h>
#include "calc3.h"
#include "y.tab.h"

int ex(nodeType *p) {
    if (!p) return 0;
    switch(p->type) {
    case typeIntCon:
        printf("Int constant\n");
        return p->conInt.value;
    case typeDoubleCon:
        printf("Double constant\n");
        return p->conDbl.value;
    case typeIntId:
        printf("Int variable\n");
        return sym[p->idInt.i];
    case typeDblId:
        printf("Double variable\n");
        return sym[p->idDbl.i];
    case typeOpr:
        switch(p->opr.oper) {
        case DO:
			printf("DO WHILE\n");
            do {
                ex(p->opr.op[0]);
            } while(ex(p->opr.op[1]));
            return 0;
        case WHILE:
			printf("WHILE\n");
            while(ex(p->opr.op[0])){
                ex(p->opr.op[1]);
            }
            return 0;
/* XXX UNTIL/REPEAT UNUSED FOR NOW */
        case REPEAT:    
		    printf("REPEAT UNTIL\n");
		    do {
                ex(p->opr.op[0]);
            } while(!ex(p->opr.op[1]));
            return 0;
        case IF:        if (ex(p->opr.op[0]))
                            ex(p->opr.op[1]);
                        else if (p->opr.nops > 2)
                            ex(p->opr.op[2]);
                        return 0;
        case PRINT:     printf("%d\n", ex(p->opr.op[0])); return 0;
        case ';':       ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case '=':       return sym[p->opr.op[0]->idInt.i] = ex(p->opr.op[1]);
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
    }
    return 0;
}
