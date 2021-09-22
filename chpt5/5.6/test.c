#include <stdio.h>

void swap(int *s, int *t)
{
	int tmp = *s;
	*s = *t;
	*t = tmp;
}

void qsort(int *v, int left, int right)
{
	int last, i;
	if (left >= right)
		return;

	swap(&v[left], &v[(left+right)/2]);
	last = left;	

	for (i = left+1; i <= right; i++)
		if (v[i] < v[left])
			swap(&v[i], &v[++last]);	

	swap(&v[left], &v[last]);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void printarray(int *v, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main (void)
{
	int n[] = {9,8,7,6,5,4,3,2,1};
	printarray(n, 9);
	qsort(n, 0, 9);
	printarray(n, 9);
}