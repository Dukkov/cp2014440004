#include <stdio.h>

int main()
{
	int i,result=0;

	for (i = 1;i < 101;i++) {
		result += i;
	}

	printf("1부터 100까지의 합 : %d\n", result);

	return 0;
}