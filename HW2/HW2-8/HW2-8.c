#include <stdio.h>

int main()
{
	int a,i;
	printf("구구단 몇단을 출력할까요?\n");
	scanf_s("%d", &a);

	for (i = 1;i < 10;i++) {
		printf("%d x %d = %d\n", a, i, a*i);
	}

	return 0;
}