#include <stdio.h>

/* Define a macro swap(t,x,y) that interchanges two arguments of type t . (Block structure will help.) */

#define swap(t,x,y) { t temp = x; x = y; y = temp; }

/*
void swap(int i, int j)
{
    int temp = i;
    i = j;
    j = temp;
}
*/

int main(void)
{
    //int j[] = {1,2};
    int i = 1;
    int j = 2;
    swap(int, i, j);
    swap(int, j, i);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
}