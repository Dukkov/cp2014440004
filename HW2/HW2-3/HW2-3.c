#include <stdio.h>

int main()
{
	int i = 1, result=0;
	while (i <= 100) {
		if (i % 3 == 0) {
			result += i;
		}
		i++;
	}

	printf("1���� 100������ ���� �� 3�� ����� ������ %d�Դϴ�.", result);

	return 0;
}