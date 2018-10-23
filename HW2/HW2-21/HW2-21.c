#include <stdio.h>

int main()
{
	int a,i,j,check=0, result=0;

	printf("정수 하나를 입력하십시오.\n");
	scanf_s("%d",&a);

	for(i=2;i<=a;i++) {

		check = 0;
		for (j = 2;j < i;j++) {
			if (i%j== 0) {
				check++;
				break;
			}
		}

		if (check == 0) {
			result += i;
		}
	}

	printf("입력된 숫자 이하 소수들의 합은 %d입니다.",result);

	return 0;
}