#include <stdio.h>
#define swap(x,y) { int tmp = x; x = y; y = tmp; }

int main (void)
{
	int a[] = {1,2};
	printf("a[0]: %d - a[1]: %d\n", a[0], a[1]);
	swap(a[0], a[1]);
	printf("a[0]: %d - a[1]: %d\n", a[0], a[1]);
	printf("%d\n", 5/2);
}
