#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,i=1,cnt=0;

	printf("���� �ϳ��� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &a);

	while (1) {
		if (a / i > 0) {
			i *= 10;
			cnt++;
		}
		else {
			printf("�Է��� ������ �ڸ����� %d�Դϴ�.", cnt);
			break;
		}
	}

	return 0;
}