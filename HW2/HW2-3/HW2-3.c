#include <stdio.h>

int main()
{
	int i = 1, result=0;
	while (i <= 100) {
		if (i % 3 == 0) {
			result += i;
		}
		i++;
	}

	printf("1부터 100사이의 정수 중 3의 공배수 총합은 %d입니다.", result);

	return 0;
}