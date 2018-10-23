#include <stdio.h>

int main()
{
	int i,n;

	printf("정수 하나를 입력하십시오.\n");
	scanf_s("%d", &n);

	for (i = 2;i < n;i++)
	{
		if (n%i == 0) {
			printf("%d ", i);
		}
	}

	return 0;
}