#include <stdio.h>

int main()
{
	int month, days, result;
	printf("���� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &month);
	printf("���� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &days);

	switch (month) 
	{
	case 1:
		result = days;
		break;
	case 2:
		result = 31 + days;
		break;
	case 3:
		result = 31 + 28 + days;
		break;
	case 4:
		result = 31 + 28 + 31 + days;
		break;
	case 5:
		result = 31 + 28 + 31 + 30 + days;
		break;
	case 6:
		result = 31 + 28 + 31 + 30 + 31 + days;
		break;
	case 7:
		result = 31 + 28 + 31 + 30 + 31 + 30 + days;
		break;
	case 8:
		result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + days;
		break;
	case 9 :
		result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + days;
		break;
	case 10:
		result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + days;
		break;
	case 11:
		result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + days;
		break;
	case 12:
		result = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + days;
	}

	printf("�� �ϼ��� %d �Դϴ�.", result);

	return 0;
}