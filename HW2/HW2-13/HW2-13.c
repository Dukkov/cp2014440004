#include <stdio.h>

int main()
{
	int month, days, result;
	printf("달을 입력하십시오.\n");
	scanf_s("%d", &month);
	printf("일을 입력하십시오.\n");
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

	printf("총 일수는 %d 입니다.", result);

	return 0;
}