#include <stdio.h>
int main()
{
	int a, b = 7, result = 0;
	printf("7���� ū ���� �ϳ��� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &a);

	do {
		if (a < 7) {
			printf("Error!\n");
			break;
		}
		result += b;
		b++;
	} while (b <= a);

	printf("7���� �Է¹��� ���������� ��� ������ ���� %d�Դϴ�.", result);

	return 0;
}