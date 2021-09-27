#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while (argc-- > 1) {
        type = getop(*++argv);
        switch (type) {
            case NUMBER:
              push(atof(*argv));
              break;
            case '+':
              push(pop() + pop());
              break;
            case '*':
              push(pop() * pop());
              break;
            case '%':
              op2 = pop();
              push((int)pop() % (int)op2);
              break;
            case '-':
              op2 = pop();
              push(pop() - op2);
              break;
            case '/':
              op2 = pop();
              if (op2 != 0.0)
                  push(pop() / op2);
              else
                  printf("error: zero divisor\n");
              break;
            default:
              printf("error: unknown command %s\n", *argv);
              break;
        }
    }
    printf("%f\n", pop());
}

#include <ctype.h>

int getop(char s[])
{
    int i,c;

    int j = 0;
    c = s[j++];
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=s[j+1]) || c == '.')
            ;
        else
        {
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(c=s[j++]))
            ;

    if(c=='.')
        while(isdigit(c=s[j++]))
            ;
    
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}