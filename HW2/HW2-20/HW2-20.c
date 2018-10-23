#include <stdio.h>

int main()
{
	int a,i,check=0;

	for(a=2;a<=100;a++) {

		check = 0;
		for (i = 2;i < a;i++) {
			if (a%i == 0) {
				check++;
				break;
			}
		}

		if (check == 0) {
			printf("%d \n",a);
		}
	}

	return 0;
}