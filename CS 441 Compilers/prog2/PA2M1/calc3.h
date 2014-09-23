typedef enum { typeIntCon, typeDoubleCon, typeIntId, typeDblId, typeOpr } nodeEnum; /* added double */

/* constants */
typedef struct {
    int value;                  /* value of constant */
} conIntNodeType;

/* doubles */
typedef struct {
    double value;                /* value of double */
} conDoubleNodeType;

/* double identifiers */
typedef struct {
    char * i;                      /* subscript to sym array */
} idIntNodeType;

/* integer identifiers */
typedef struct {
    int i;                      /* subscript to sym array */
} idDblNodeType;

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
        conDoubleNodeType conDbl;  /* constant double */
        idIntNodeType idInt;          /* integer identifier */
        idDblNodeType idDbl;       /* double identifier */
        oprNodeType opr;           /* operators */
    };
} nodeType;

/*
typedef struct valueType {
     int Int;
     double Dbl;
};
*/

#define TYPE_INT    1
#define TYPE_DOUBLE 2

extern int sym[26];
/* removed extern int sym[26]; JWJ */
