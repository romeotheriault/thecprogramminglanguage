#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
    int i,c;
    static int buf = EOF;

    if (buf == EOF || buf == ' ' || buf == '\t') {
        while((s[0] = c = getch()) == ' ' || c =='\t')
            ;
        s[1] = '\0';
    } else {
        c = buf;
    }
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                buf = c;
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
        buf = c;
    return NUMBER;
}