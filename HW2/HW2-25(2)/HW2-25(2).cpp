#include <stdio.h>

int main() 
{
	int i,j,k,l;

	for(i=1;i<7;i++) {
		for(j=0;j<13-2*i;j++) {
			printf("*");
		}
		printf("\n");
	}

	for(k=1;k<6;k++) {
		for(j=0;j<2*k+1;j++) {
			printf("*");
		}
		printf("\n");
	}
}