#include <stdio.h>

int main()
{
	int i, input, result=0;
	printf("10개의 정수를 입력하십시오.\n");

	for (i = 0;i < 10;i++) {
		scanf_s("%d",&input);
		result += input;
	}

	printf("입력한 정수의 총 합은 %d입니다.\n", result);

	return 0;
}