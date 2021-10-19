#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    /*
    char *p = "ta";
    char *t = "tc";

    //int k = strcmp(p, t);
    //printf("%d\n", k);
    int j;

    if ((j = strcmp(p, t)) < 0)
        printf("less than\n");
    else if (j == 0)
        printf("same\n");
    else
        printf("greater than\n");
    */

    /*
    char newline = '\n';
    if (isalpha(newline))
        printf("is alpha\n");
    else
        printf("not alpha\n");
    */

    int i = 10;
    char *t;
    t = (char *) malloc(sizeof(int)* 1024);
    t = strdup((const char *)(i+'0'));

}