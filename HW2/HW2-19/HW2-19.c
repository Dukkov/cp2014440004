#include <stdio.h>

int main()
{
	int i,input,check=0;
	printf("���� �ϳ��� �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &input);

		if (input <= 1) {
			printf("Error! 1���� ū ���� �Է��Ͻʽÿ�!\n");
			check--;
		}
		else {
			for (i = 2;i < input;i++) {
				if (input%i == 0) {
					check++;
					break;
				}
			}
		}

		if (check == 0) {
			printf("�Է��� ������ �Ҽ��Դϴ�.\n");
		}
		else if (check < 0) {

		}
		else {
			printf("�Է��� ������ �Ҽ��� �ƴմϴ�.\n");
		}

	return 0;
}