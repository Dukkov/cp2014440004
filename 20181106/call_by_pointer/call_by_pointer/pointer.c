#include <stdio.h>

void test(int a)
{
	a= 100;
}

void testPtr(int* ptr)
{
	*ptr = 100;
}

int main()
{
	int a = 10;
	//int* ptr = &a;
	testPtr(&a);
	printf("a = %d\n",a);

	return 0;
}