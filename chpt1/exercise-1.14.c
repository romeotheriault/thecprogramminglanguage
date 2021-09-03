#include <stdio.h>

// Write a program to print a histogram of the frequencies of the different characters in its input.
// Horizontal histogram and Vertical histogram

#define LENGTH 127

main ()
{
    int characters[LENGTH];
    int c, i, j, k;
    c = i = j = k = 0;

    for (i = 0; i < LENGTH; ++i)
        characters[i] = 0;

    while ((c = getchar()) != EOF) {
            //printf("%c\n", c);
            ++characters[c];
    }

    // Horizontal
    for (j = 0; j < LENGTH; ++j) {
        if (characters[j] == 0)
            ;
        else {
            printf("%c: ", j);
            for (k = 0; k < characters[j]; ++k)
                printf("#");
    
            printf("\n");
        }
    }

    // Vertical
    // Think of the vertical histogram like a matrix.
    // Strategy:
    // * Find the x,y position of the highest point.
    //      * hx is the index of the largest number.
    //      * hy is the largest number.

    // Find the longest word so we have a starting point.
//    int hx, hy, l, y;
//    hx = hy = 0;
//    for (l = 0; l <= word_index; ++l) {
//        if (word_length[l] > hy) {
//            hx = l + 1;
//            hy = word_length[l];
//        }
//    }
    
//    printf("hy: %d\n", hy);
//    for (y = hy; y > 0; --y) {
//    for (y = 0; y <= hy; ++y) {
//        for (l = 0; l <= LENGTH; ++l) { 
//            //if (word_length[l] >= ((LENGTH - 1) - y))
//            if (word_length[l] > (hy  - y))
//                printf("#");
//            else
//                printf(" ");
//        } 
//        printf("\n");
//    }

}
