#include <stdio.h>

int main()
{
	int a=0,b=4,c;
	while(a<3) {
		for(c=0;c<6;c++) {
			printf("*");
			if(c==b) {
				printf(" ");
				b -= 2;
			}
		}
		printf("\n");
		a++;
	}
}