#include <stdio.h>


main ()
{
    int c, blanks;
    c = blanks = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            blanks = 0;
        }
        if (c == ' ') {
            if (blanks != 0) {
                ;
            } else {
                putchar(c);
                ++blanks;
            }
        }
    }
}
