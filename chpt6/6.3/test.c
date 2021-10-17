#include <stdio.h>
#include <string.h>

int main()
{
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
}