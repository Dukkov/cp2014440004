#include <stdio.h>

int main()
{
	int i, input, result=0;
	printf("10���� ������ �Է��Ͻʽÿ�.\n");

	for (i = 0;i < 10;i++) {
		scanf_s("%d",&input);
		result += input;
	}

	printf("�Է��� ������ �� ���� %d�Դϴ�.\n", result);

	return 0;
}