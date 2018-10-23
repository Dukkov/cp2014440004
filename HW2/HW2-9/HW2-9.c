#include <stdio.h>

int main()
{
	int a, i,check=0;
	printf("구구단 몇단을 출력할까요?\n");

	do {
		check = 0;
		scanf_s("%d", &a);

		if (a < 1 || a>9) {
			printf("Error! 입력범위는 1~9입니다.\n");
			printf("다시 입력 : ");
			check++;
		}
	} while (check>0);

	for (i = 1;i < 10;i++) {
		printf("%d x %d = %d\n", a, i, a*i);
	}

	return 0;
}