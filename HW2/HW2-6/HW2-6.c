#include <stdio.h>

int main()
{
	int a,check=0;
	printf("���� ���� n�� �Է��Ͻʽÿ�.\n");
	do {
		check = 0;
		
		scanf_s("%d", &a);

		if (a < 1) {
			printf("Error! ���� ������ �Է��Ͻʽÿ�!\n");
			printf("�ٽ��Է� : ");
			check++;
		}
		else {
			printf("2n = %d", 2*a);
		}

	} while (check > 0);

	return 0;
}