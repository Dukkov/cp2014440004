#include <stdio.h>

int main()
{
	int i, result = 0;

	for (i = 1;i < 101;i++) {
		if (i % 5 == 0) {
			result += i;
		}
	}
	
	printf("1���� 100���� 5�� ����� ���� %d�Դϴ�.", result);

	return 0;
}