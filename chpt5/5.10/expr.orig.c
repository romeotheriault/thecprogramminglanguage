#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double pst(void);
int swap(void);
void clear(void);
/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
            push(atof(s));
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
            case 'p':
            if (getop(s) == '\n') {
                printf("\t%.8g\n", pst());
            }
            break;
            case 's':
            if (getop(s) == '\n') {
                if(swap()==0) {
                    printf("top two elements swapped\n");
                } else {
                    printf("not two elements to swap\n");
                }
            }
            case 'c':
            if (getop(s) == '\n') {
                clear();
                printf("stack cleared\n");
            }
            break;
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
            case '\n':
            printf("\t%.8g\n", pop());
            break;
            default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
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

double pst(void)
{
    if(sp>0)
        return val[sp-1];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int swap(void)
{
    double temp;
    if(sp>1) {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp; 
        return 0;
    }
    else
    {
        return -1;
    }
}

void clear(void)
{
    sp = 0;
}