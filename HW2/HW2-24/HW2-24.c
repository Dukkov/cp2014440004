#include <stdio.h>

int main()
{
	int a,i,j;
	printf("���� ���� �Է��Ͻʽÿ�.\n");
	scanf_s("%d",&a);

	for(i=1;i<=a;i++) {
		for(j=0;j<2*i-1;j++) {
				printf("*");
		}
		printf("\n");
	}

	return 0;
}