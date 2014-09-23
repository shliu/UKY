typedef enum { typeIntCon, typeDoubleCon, typeId, typeOpr } nodeEnum; /* added double - THS */

/* constants */
typedef struct {
    int value;                  /* value of constant */
} conIntNodeType;

/* doubles - added THS*/
typedef struct {
    double value;                /* value of double */
} conDoubleNodeType;

/* identifiers */
typedef struct {
    int i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union {
        conIntNodeType conInt;     /* constant integer */
        conDoubleNodeType conDbl;  /* constant double - Added THS */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;

extern int sym[26];
