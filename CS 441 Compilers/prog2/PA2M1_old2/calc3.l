%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
%}

%%

[a-z]       {
                yylval.sIndex = *yytext - 'a';
                return VARIABLE;
            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }
[0-9][0-9]*"."[0-9][0-9]* {
                yylval.dValue = atoi(yytext);
                return DOUBLE;
            }
[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }
[-()<>=+*/;{}.] {
                return *yytext;
             }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"while"         return WHILE;
"do"            return DO;
"until"         return UNTIL;
"repeat"        return REPEAT;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
