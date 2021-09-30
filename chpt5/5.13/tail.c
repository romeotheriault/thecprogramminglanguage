#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Write the program tail which prints the last n lines of it's input.
   By default n is 10, by can be changed by an optional argument

   tail -n 20

   The program should behave rationally no matter how unreasonable the input 
   or the value of n.
   Write the program so it makes the best use of available storage. 
   Lines should be stored as in the sorting program of section 5.6. i.e. Not a
   two dimensional array of fixed size.

*/

#define MAXLINES 100000
int main (int argc, char *argv[])
{
    size_t buffsize = 1000;
    char *lines[MAXLINES];
    int printlines = 10;
    if (argc >= 2 && strncmp(argv[1], "-n", 2) == 0)
        printlines = atoi(argv[2]);

    size_t i;
    for (i = 0; getline(&lines[i], &buffsize, stdin) > 0 && i < MAXLINES; i++)
        ; 

    printf("total lines: %ld\n", i);
    printf("lines to print: %d\n", printlines);
    
    while (i >= printlines) 
        printf("%s", lines[i-printlines--]);
}