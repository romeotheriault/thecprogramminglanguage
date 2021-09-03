#include <stdio.h>

// Write a program to print a histogram of the lengths of words in its input.
// Horizontal histogram and Vertical histogram

#define LENGTH 10

main ()
{
    int word_length[LENGTH];
    int c, i, j, k, word_index;
    c = i = j = k = word_index = 0;

    for (i = 0; i < LENGTH; ++i)
        word_length[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n')
            ++word_length[word_index];
        else if (c == '\n')
            ;
        else
            ++word_index;
    }

    // Horizontal
    //for (j = 0; j <= word_index; ++j) {
    //        for (k = 0; k < word_length[j]; ++k)
    //            printf("#");
    //
    //  printf("\n");
    //}

    // Vertical
    // Think of the vertical histogram like a matrix.
    // Strategy:
    // * Find the x,y position of the highest point.
    //      * hx is the index of the largest number.
    //      * hy is the largest number.

    // Find the longest word so we have a starting point.
    int hx, hy, l, y;
    hx = hy = 0;
    for (l = 0; l <= word_index; ++l) {
        if (word_length[l] > hy) {
            hx = l + 1;
            hy = word_length[l];
        }
    }
    
//    printf("hy: %d\n", hy);
//    for (y = hy; y > 0; --y) {
    for (y = 0; y <= hy; ++y) {
        for (l = 0; l <= LENGTH; ++l) { 
            //if (word_length[l] >= ((LENGTH - 1) - y))
            if (word_length[l] > (hy  - y))
                printf("#");
            else
                printf(" ");
        } 
        printf("\n");
    }

}
