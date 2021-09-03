#include <stdio.h>


main ()
{
    int c, blanks, tabs, newlines;
    c = blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
           ++newlines; 
        if (c == '\t')
            ++tabs;
        if (c == ' ')
            ++blanks;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
}
