#include <stdio.h>

int main()
{
	int a=0,tmp;

	printf("정수를 입력하십시오.\n");
	while (1) {
		scanf_s("%d", &tmp);
		
		if (tmp > a) {
			a = tmp;
		}

		if (tmp == 0) {
			break;
		}
	}

	printf("입력된 정수중 가장 큰 수는 %d입니다.", a);

	return 0;
}