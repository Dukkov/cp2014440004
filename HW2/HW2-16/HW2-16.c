#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,i=1,cnt=0;

	printf("정수 하나를 입력하십시오.\n");
	scanf_s("%d", &a);

	while (1) {
		if (a / i > 0) {
			i *= 10;
			cnt++;
		}
		else {
			printf("입력한 정수의 자릿수는 %d입니다.", cnt);
			break;
		}
	}

	return 0;
}