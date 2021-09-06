#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "calc.h"
/* reverse Polish calculator */
int main()
{
    int type;
    double op1;
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
            op1 = pop();
            push((int)pop() % (int)op1);
            break;
            case '-':
            op1 = pop();
            push(pop() - op1);
            break;
            case PRINT:
            pst();
            break;
            case PRINTALL:
            psall();
            break;
            case SWAP:
            if(swap()==-1) {
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
            op1 = pop();
            push(pow(pop(), op1));
            break;
            case SIN:
            push(sin(pop()));
            break;
            case EXP:
            push(exp(pop()));
            break;
            case '/':
            op1 = pop();
            if (op1 != 0.0)
                push(pop() / op1);
            else
                printf("error: zero divisor\n");
            break;
            case '\n':
            printf("\t%.7g\n", pop());
            break;
            default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}