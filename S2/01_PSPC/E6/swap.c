#include <stdio.h>

void swap(int *, int *);

int main() {
	int a = 5, b = 6;
	swap(&a, &b);
	printf("5=%d 6=%d\n", a, b);
	return 0;
}

void swap(int * x, int * y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
