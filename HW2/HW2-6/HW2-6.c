#include <stdio.h>

int main()
{
	int a,check=0;
	printf("양의 정수 n을 입력하십시오.\n");
	do {
		check = 0;
		
		scanf_s("%d", &a);

		if (a < 1) {
			printf("Error! 양의 정수를 입력하십시오!\n");
			printf("다시입력 : ");
			check++;
		}
		else {
			printf("2n = %d", 2*a);
		}

	} while (check > 0);

	return 0;
}