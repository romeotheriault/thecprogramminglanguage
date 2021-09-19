#include <stdio.h>
#include <sys/random.h>

/*
// Array of 20k elements
real    0m0.622s
user    0m0.578s
sys     0m0.000s

// Array of 200k elements
real    2m38.689s
user    2m37.047s
sys     0m0.313s
*/


void bubblesort(int *a, int alen)
{
    for (int i = 0; i < alen; i++) {
        for (int j = 0; j < alen - i; j++) {
            if (a[j] >= a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void printarray (int *a, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main (void)
{
    const int MAXLEN = 200000;
    int a[MAXLEN];
    ssize_t rc = getrandom(a, MAXLEN, 0);
    //printf("unsorted array: ");
    int alen = sizeof(a)/sizeof(*a);
    //printarray(a, alen);
    bubblesort(a, alen);
    printf("sorted array: ");
    //printarray(a, alen);
    printf("last element: %d\n", a[MAXLEN-1]);
}