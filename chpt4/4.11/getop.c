#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(isalpha(c)) {
        while(isalpha(s[++i] = c=getch()))
            ;
        if (strcmp(s, "clear\n") == 0) {
            memset(s, '\0', MAXOP);
            return CLEAR;
        } else if (strcmp(s, "swap\n") == 0)
        {
            memset(s, '\0', MAXOP);
            return SWAP;
        } else if (strcmp(s, "print\n") == 0)
        {
            memset(s, '\0', MAXOP);
            return PRINT;
        } else if (strcmp(s, "printall\n") == 0)
        {
            memset(s, '\0', MAXOP);
            return PRINTALL;
        } else if (strcmp(s, "sin\n") == 0)
        {
            ungetch(c);
            memset(s, '\0', MAXOP);
            return SIN;
        } else if (strcmp(s, "exp\n") == 0)
        {
            ungetch(c);
            memset(s, '\0', MAXOP);
            return EXP;
        } else if (strcmp(s, "pow\n") == 0)
        {
            ungetch(c);
            memset(s, '\0', MAXOP);
            return POW;
        }

    }
    if(!isdigit(c) && !isalpha(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] = c=getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}