#include <stdio.h>

int main()
{
	int i = 1, result = 0;
	do {
		if (i % 3 == 0) {
			result += i;
		}
		i++;
	} while (i <= 100);

	printf("1���� 100������ ���� �� 3�� ����� ������ %d�Դϴ�.", result);

	return 0;
}
