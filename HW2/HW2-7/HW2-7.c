#include <stdio.h>

int main()
{
	int a,result = 0,check = 1;

	printf("정수를 입력하십시오. (0 : 입력종료)\n");

	while (check != 0) {
		scanf_s("%d", &a);
		result += a;

		if (a == 0) {
			check = 0;
		}
	}

	printf("입력된 정수의 총합은 %d입니다.",result);

	return 0;
}