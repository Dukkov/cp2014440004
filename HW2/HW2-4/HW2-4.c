#include <stdio.h>

int main()
{
	int i; int result = 0;

	for (i = 1;i < 101;i++) {
		if (i % 3 == 0) {
			result += i;
		}
	}

	printf("1���� 100������ ���� �� 3�� ����� ������ %d�Դϴ�.", result);

	return 0;
}