#include <stdio.h>

int main()
{
	int i, n;

	do {
		printf("���� �ϳ��� �Է��Ͻʽÿ�. (0 : �Է� ����)\n");
		scanf_s("%d", &n);

		if (n == 0) {
			break;
		}
		else {
			for (i = 2;i < n;i++)
			{
				if (n%i == 0) {
					printf("%d ", i);
				}
			}
			printf("\n");
		}
	} while (1);

	return 0;
}