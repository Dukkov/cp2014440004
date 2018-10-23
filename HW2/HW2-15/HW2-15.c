#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = rand() % 100;
	int a,i;

	for (i = 0;i < 11;i++) {
		if (i == 10) {
			printf("Game over!\n");
			break;
		}
		printf("숫자를 입력하십시오 : ");
		scanf_s("%d", &a);
		if (num > a) {
			printf("답은 입력하신 숫자보다 큽니다.\n");
		}
		else if (num < a) {
			printf("답은 입력하신 숫자보다 작습니다.\n");
		}
		else {
			printf("정답입니다!\n");
			break;
		}
	}

	return 0;
}