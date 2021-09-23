#include <stdio.h>

void swap (int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void qsort (int *a, int left, int right)
{
	int last, i;

	if (left >= right)
		return;
	
	swap(&a[left], &a[(right+left)/2]);
	last = left;

	for (i = left+1; i <= right; i++)
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
	int a[] = {9,8,7,6,5,4,3,2,1};
	printarray(a, 9);
	qsort(a, 0, 9);
	printarray(a, 9);
}