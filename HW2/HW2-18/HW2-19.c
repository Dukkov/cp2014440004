#include <stdio.h>

int main()
{
	int i, result = 0;

	for (i = 1;i < 101;i++) {
		if (i % 5 == 0) {
			result += i;
		}
	}
	
	printf("1부터 100까지 5의 배수들 합은 %d입니다.", result);

	return 0;
}