#include <stdio.h>

int main()
{
	int a=0,tmp;

	printf("������ �Է��Ͻʽÿ�.\n");
	while (1) {
		scanf_s("%d", &tmp);
		
		if (tmp > a) {
			a = tmp;
		}

		if (tmp == 0) {
			break;
		}
	}

	printf("�Էµ� ������ ���� ū ���� %d�Դϴ�.", a);

	return 0;
}