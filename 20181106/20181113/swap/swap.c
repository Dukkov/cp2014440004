#include <stdio.h>

void swap(int* a, int*b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;

}

int main()
{
	int a = 10, b = 20;

	swap(&a, &b);
	printf("a = %d, b = %d\n",a,b);

	return 0;
}