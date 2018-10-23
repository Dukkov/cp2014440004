#include <stdio.h>
int main()
{
	int a, b = 7, result = 0;
	printf("7보다 큰 정수 하나를 입력하십시오.\n");
	scanf_s("%d", &a);

	do {
		if (a < 7) {
			printf("Error!\n");
			break;
		}
		result += b;
		b++;
	} while (b <= a);

	printf("7부터 입력받은 정수까지의 모든 정수의 합은 %d입니다.", result);

	return 0;
}