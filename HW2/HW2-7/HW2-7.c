#include <stdio.h>

int main()
{
	int a,result = 0,check = 1;

	printf("������ �Է��Ͻʽÿ�. (0 : �Է�����)\n");

	while (check != 0) {
		scanf_s("%d", &a);
		result += a;

		if (a == 0) {
			check = 0;
		}
	}

	printf("�Էµ� ������ ������ %d�Դϴ�.",result);

	return 0;
}