#include <stdio.h>

int main()
{
	int a, i,check=0;
	printf("������ ����� ����ұ��?\n");

	do {
		check = 0;
		scanf_s("%d", &a);

		if (a < 1 || a>9) {
			printf("Error! �Է¹����� 1~9�Դϴ�.\n");
			printf("�ٽ� �Է� : ");
			check++;
		}
	} while (check>0);

	for (i = 1;i < 10;i++) {
		printf("%d x %d = %d\n", a, i, a*i);
	}

	return 0;
}