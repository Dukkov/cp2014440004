#include <stdio.h>

int main()
{
	int i, n;

	do {
		printf("정수 하나를 입력하십시오. (0 : 입력 종료)\n");
		scanf_s("%d", &n);

		if (n == 0) {
			break;
		}
		else {
			for (i = 2;i < n;i++)
			{
				if (n%i == 0) {
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	} while (1);

	return 0;
}