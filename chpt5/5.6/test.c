#include <stdio.h>

void swap (int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void qsort(int *a, int left, int right)
{
	int last, i;

	if (left >= right) // Return if less than two items.
		return;
	// Use the middle item as the partition, swap with first item.
	swap(&a[left], &a[(right+left)/2]);
	last = left;
	// Loop thru all the items, moving any smaller than partition 
	for (i = left+1; i <= right; i++) 
		if (a[i] < a[left])
			swap(&a[i], &a[++last]);
	// Move back the partition item to it's final location.
	swap(&a[left], &a[last]);
	qsort(a, left, last-1);	    // call qsort for left subarray
	qsort(a, last+1, right);	// call qsort for right subarray
}

void printarray(int *a, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(void)
{
	int a[] = {9,8,7,6,5,4,3,2,1};
	int len = sizeof(a)/sizeof(*a);
	printarray(a, len);
	qsort(a, 0, len);
	printarray(a, len);
}