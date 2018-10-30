#include <stdio.h>

//1. 두 정수 사이에 모든 정수들을 순서대로 화면에 출력하는 함수

void printBtw(int a, int b)
{
	int min,max;
	if(a>b) {
		min=b;
		max=a;
	}
	else {
		min = a;
		max = b;
	}

	while(min<=max) {
		printf("%d ",min);
		min++;
	}
}

int main() 
{
	int a=15,b=9;
	printBtw(a,b);

	return 0;
}