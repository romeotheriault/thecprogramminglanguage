#include <stdio.h>

/* Write a program detab that replaces tabs in the input with the proper number of blanks
   to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
   Should n be a variable or a symbolic parameter. */

#define TABSTOP 8

int main (void)
{
    char *j = "\t\tjoe\ty\tjo\tey";
    char *b = j;

    while (*j != '\0')
    {
        printf("%c", *j++);
    }
    printf("\n");

    // Bring pointer back to the beginning of array.
    j = b;

    int count = 0;
    while (*j != '\0')
    {
        if (*j == '\t') {
            int s = TABSTOP - count;
            int i = 0;
            while (i++<s)
                printf(" ");
            j++;
            count = 0;
        }
        else {
            printf("%c", *j++);
            count++;
        }
    }
    printf("\n");
}