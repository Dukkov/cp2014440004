#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = rand() % 100;
	int a,i;

	for (i = 0;i < 11;i++) {
		if (i == 10) {
			printf("Game over!\n");
			break;
		}
		printf("���ڸ� �Է��Ͻʽÿ� : ");
		scanf_s("%d", &a);
		if (num > a) {
			printf("���� �Է��Ͻ� ���ں��� Ů�ϴ�.\n");
		}
		else if (num < a) {
			printf("���� �Է��Ͻ� ���ں��� �۽��ϴ�.\n");
		}
		else {
			printf("�����Դϴ�!\n");
			break;
		}
	}

	return 0;
}