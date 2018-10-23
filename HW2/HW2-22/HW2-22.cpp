#include <stdio.h>

int main()
{
	int a=1,b=0;

	while(a!=0) {
		printf("숫자를 입력하십시오. (0 : 입력종료) : ");
		scanf_s("%d",&a);

		if(a>b) {
			b=a;
		}
	}

	printf("입력받은 숫자중 최댓값은 %d입니다.",b);

	return 0;
}