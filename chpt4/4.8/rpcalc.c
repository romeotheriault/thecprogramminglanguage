#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define CLEAR '1'
#define SWAP '2'
#define PRINT '3'
#define PRINTALL '4'
#define SIN '5'
#define EXP '6'
#define POW '7'
#define LAST '9'

int getop(char []);
void push(double);
double pop(void);
void pst(void);
void psall(void);
int swap(void);
void clear(void);
/* reverse Polish calculator */
double last;
int main()
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
            case PRINT:
            pst();
            break;
            case PRINTALL:
            psall();
            break;
            case SWAP:
            if(swap()==0) {
                printf("top two elements swapped\n");
            } else {
                printf("not two elements to swap\n");
            }
            break;
            case CLEAR:
            clear();
            printf("stack cleared\n");
            break;
            case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
            case SIN:
            push(sin(pop()));
            break;
            case LAST:
            printf("\t%.8g\n", last);
            break;
            case EXP:
            push(exp(pop()));
            break;
            case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
            case '\n':
            last = pop();
            printf("\t%.8g\n", last);
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
        } else if (strcmp(s, "last\n") == 0)
        {
            memset(s, '\0', MAXOP);
            return LAST;
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

int bufp = -1;

int getch(void)
{
    if (bufp != -1)
    {
        int temp = bufp;
        bufp = -1;
        return temp;
    } else {
        return getchar();
    }
}

void ungetch(int c)
{
    if(bufp >= 0)
        printf("ungetch: too many characters\n");
    else
        bufp = c;
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

void pst(void)
{
    if(sp>0) {
        printf("\t%.8g\n", val[sp-1]);
        return; 
    }
    else
    {
        printf("error: stack empty\n");
        return;
    }
}

void psall(void)
{
    char str[1024];
    memset(str, '\0', 1024);
    size_t n = sizeof(val)/sizeof(val[0]);
    if(sp>0) {
        for (int i = 0; i < sp && i < 1024; i++)
        {
            char num[100];
            memset(num, '\0', 100);
            sprintf(num, "%f ", val[i]);
            strcat(str, num);
        }
        printf("\t%s\n", str);
        return;
    }
    else
    {
        printf("error: stack empty\n");
        return;
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