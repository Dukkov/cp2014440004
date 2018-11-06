#include <stdio.h>

//포인터는 메모리주소, 가르키는 변수의 자료형을 내포한다.
int main()
{
	int a = 10;
	int* ptr; //ptr 포인터가 가르키는 변수는 int형
	ptr = &a; //ptr은 이제 a를 가르킨다
	*ptr = 20; //*ptr은 ptr 포인터변수가 가르키는 변수의 데이터
	printf("a=%d\n",a);

	return 0;
}