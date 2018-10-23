#include <stdio.h>

//함수 sum()
//입력 : 두 정수
//출력 : 두 정수의 합
//부수효과 : 없음

int sum(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

//함수 : goodPrint()
//입력 : 없음
//출력 : 없음
//부수효과 : 화면에 good 출력
void goodPrint() 
{
	printf("good!\n");
}

int main()
{
	int x = 10, y = 20, z;
	z = sum(x,y);
	printf("z = %d\n",z);

	goodPrint();

	return 0;
}