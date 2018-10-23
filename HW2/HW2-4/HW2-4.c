#include <stdio.h>

int main()
{
	int i; int result = 0;

	for (i = 1;i < 101;i++) {
		if (i % 3 == 0) {
			result += i;
		}
	}

	printf("1부터 100사이의 정수 중 3의 공배수 총합은 %d입니다.", result);

	return 0;
}