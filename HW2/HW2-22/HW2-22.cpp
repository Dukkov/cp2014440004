#include <stdio.h>

int main()
{
	int a=1,b=0;

	while(a!=0) {
		printf("���ڸ� �Է��Ͻʽÿ�. (0 : �Է�����) : ");
		scanf_s("%d",&a);

		if(a>b) {
			b=a;
		}
	}

	printf("�Է¹��� ������ �ִ��� %d�Դϴ�.",b);

	return 0;
}