#include <stdio.h>
#include <string.h>
#include "calc.h"
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