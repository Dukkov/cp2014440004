#include <stdio.h>

int main()
{
	int a,i,j,check=0, result=0;

	printf("���� �ϳ��� �Է��Ͻʽÿ�.\n");
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

	printf("�Էµ� ���� ���� �Ҽ����� ���� %d�Դϴ�.",result);

	return 0;
}