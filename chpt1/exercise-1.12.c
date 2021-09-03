#include <stdio.h>

// Write a program that prints it's input one word per line.

#define IN  1
#define OUT 0

main ()
{
    int c, blanks, state;
    c = blanks = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') {
            if (state == OUT && blanks != 0) {
                printf("\n");
            }
            state = IN;
            blanks = 0;
            putchar(c);
        }
        if (c == ' ' || c == '\t') {
            state = OUT; 
            ++blanks;
        }
    }
}
