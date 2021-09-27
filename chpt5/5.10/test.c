#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("argc: %d\n", argc);

    while (argc-- > 1) {
        char *j = *++argv;

        printf("%d\n", atoi(*++argv));
    } 
}