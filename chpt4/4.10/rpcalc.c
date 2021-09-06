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

int getop(char s[])
{
    int i,c;
    static char *linebuf = NULL;
    size_t linebuf_size = 0;
    int strsize = 0;
    static int lbp = -1;
    memset(s, '\0', MAXOP);

    if (lbp == -1) {
        if (getline(&linebuf, &linebuf_size, stdin)==-1) {
            printf("Exiting");
            exit(EXIT_FAILURE);
        } else {
            lbp = 0;
            strsize = strlen(linebuf);
        }
    } else if (linebuf[lbp] == '\n') {
        memset(linebuf, '\0', linebuf_size);
        s[0] = '\0';
        lbp = -1;
        return '\n';
    }

    
    while((linebuf[lbp]) == ' ' || c =='\t')
        lbp++;

    //s[1] = '\0';
    c = linebuf[lbp];
    i = 0;
    if (c == '\n') {
        lbp = -1;
        s[0] = '\0';
        return '\n';
    }
    if(isalpha(c)) {
        while(isalpha(c=linebuf[lbp])) {
            lbp++;
            s[i++] = c;
        }
        if (linebuf[lbp] == '\n' && (strcmp(s, "clear") == 0 || strcmp(s, "print") == 0 || strcmp(s, "swap") == 0 || strcmp(s, "printall") == 0)) {
            s[i] = linebuf[lbp];
        }
        if (strcmp(s, "clear\n") == 0) {
            memset(linebuf, '\0', linebuf_size);
            s[0] = '\0';
            lbp = -1;
            return CLEAR;
        } else if (strcmp(s, "swap\n") == 0)
        {
            memset(linebuf, '\0', linebuf_size);
            s[0] = '\0';
            lbp = -1;
            return SWAP;
        } else if (strcmp(s, "print\n") == 0)
        {
            memset(linebuf, '\0', linebuf_size);
            s[0] = '\0';
            lbp = -1;
            return PRINT;
        } else if (strcmp(s, "printall\n") == 0)
        {
            memset(linebuf, '\0', linebuf_size);
            s[0] = '\0';
            lbp = -1;
            return PRINTALL;
        } else if (strcmp(s, "sin") == 0)
        {
            return SIN;
        } else if (strcmp(s, "exp") == 0)
        {
            return EXP;
        } else if (strcmp(s, "pow") == 0)
        {
            return POW;
        } else if (strcmp(s, "last") == 0)
        {
            return LAST;
        }

    }
    if(!isdigit(c) && !isalpha(c) && c!='.' && c!='-') {
        lbp++;
        return c;
    }

    if(c=='-')
        if(isdigit(c=linebuf[lbp++]) || c == '.')
            s[i++]=c;
        else
        {
            //if(c!=EOF)
            //    ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(c=linebuf[lbp])) {
            lbp++;
            s[i++] = c;
        }

    if(c=='.')
        while(isdigit(s[i++] = c=linebuf[++lbp]))
            ;
    
    //s[i] = '\0';
    //if(c!=EOF)
     //   ungetch(c);
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