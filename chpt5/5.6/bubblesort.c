#include <stdio.h>
#include <string.h>

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
    int a[] = {9,8,10,4,3,7,6,5,1};
    printf("unsorted array: ");
    int alen = sizeof(a)/sizeof(*a);
    printarray(a, alen);
    bubblesort(a, alen);
    printf("sorted array: ");
    printarray(a, alen);
}