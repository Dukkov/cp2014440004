#include <stdio.h>

int main()
{
	int i,n;

	printf("���� �ϳ��� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &n);

	for (i = 2;i < n;i++)
	{
		if (n%i == 0) {
			printf("%d ", i);
		}
	}

	return 0;
}