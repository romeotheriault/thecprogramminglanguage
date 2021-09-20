#include <stdio.h>
#include <sys/random.h>

/* 
Timing for 200k elements. (vs over 2 1/2 minutes for bubblesort)
real    0m24.451s
user    0m23.375s
sys     0m0.203s
*/

void swap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void qsort (int *a, int left, int right)
{
    int i, last;

    if (left > right)
        return;
    swap(&a[left], &a[(right+left)/2]);
    last = left;
    for (i = left + 1; i < right; i++)
        if (a[i] < a[left])
            swap(&a[i], &a[++last]);
    swap(&a[left], &a[last]);
    qsort(a, left, last-1);
    qsort(a, last+1, right);
}

void printarray (int *a, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main (void)
{
    /* 
    int a[] = {3,7,8,5,2,1,9,5,4};
    int len = sizeof(a)/sizeof(*a);
    printf("len of array: %d\n", len);
    */
    const int MAXLEN = 200000;
    int a[MAXLEN];
    ssize_t rc = getrandom(a, MAXLEN, 0);
    printf("unsorted array: ");
    printarray(a, MAXLEN);
    qsort(a, 0, MAXLEN);
    printf("sorted array: ");
    printarray(a, MAXLEN);
}