#include <stdio.h>

int main()
{
	int i,input,check=0;
	printf("정수 하나를 입력하십시오.\n");
	scanf_s("%d", &input);

		if (input <= 1) {
			printf("Error! 1보다 큰 수를 입력하십시오!\n");
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
			printf("입력한 정수는 소수입니다.\n");
		}
		else if (check < 0) {

		}
		else {
			printf("입력한 정수는 소수가 아닙니다.\n");
		}

	return 0;
}