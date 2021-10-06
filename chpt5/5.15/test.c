#include <stdio.h>
#include <ctype.h>


void f (void **v)
{
    char **x = (char **)v;
    printf("%s\n", x[0]);
    if (isalpha(*(x)[0]))
        printf("%c\n", *(x)[0]);
}

int main (void)
{
    char *c = "testing";
    char *lineptr[10];
    lineptr[0] = c;

    /*
    void **v = (void **)lineptr;

    printf("l: %s\n", lineptr[0]);
    printf("v: %s\n", (char *)v[0]);
    */

    //f((void **)lineptr);
    f((void **)lineptr);
}