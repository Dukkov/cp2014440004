#include <stdio.h>

//1. �� ���� ���̿� ��� �������� ������� ȭ�鿡 ����ϴ� �Լ�

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