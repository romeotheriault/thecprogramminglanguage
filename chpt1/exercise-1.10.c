#include <stdio.h>


main ()
{
    int c, blanks;
    c = blanks = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\t' && c != '\b' && c != '\\')
            putchar(c);
        else {
            if (c == '\t')
                printf("\\t");
            if (c == '\b') 
                printf("\\b");
            if (c == '\\')
                printf("\\\\");
        }
    }
}
