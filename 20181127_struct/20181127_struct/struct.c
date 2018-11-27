#include <stdio.h>
#include <stdlib.h>

//구조체 선언 : 기존의 데이터 타입으로 구성된 새로운 데이터 타입을 선언한다.
typedef struct complex {
	double real;
	double imag;
} Complex;

//데이터 타입의 별명 선언
typedef int myintType;

//함수 printComplex()
//입력 : 복소수
//출력 : 없음
//부수효과 : 없음
void printComplex(Complex *x)
{
	printf("%f + j%f\n", x->real,x->imag);
}

//함수 conjugate()
//입력 : 복소수(포인터)
//출력 : 없음
//부수효과 : 입력된 복소수가 켤레 복소수로 변환됨
void conjugate(Complex *ptr)
{
	ptr->imag = -1 * ptr->imag;
	printf("%f +j%f\n",ptr->real, ptr->imag);
}

Complex* returnConjugate(Complex* ptr) 
{
	Complex temp;
	temp.real = ptr->real;
	temp.imag = -1 * ptr->imag;
	return &temp;
}

int main()
{
	myintType count = 10;

	//구조체 변수의 선언
	Complex a,b; //구조체변수의 멤버 접근방법 ==> 구조체변수이름.멤버변수이름
	//a.real = 10;
	//a.imag = 20;

	//printf("%d %d\n",a.real,a.imag);
	//구조체 포인터 변수 선언
	Complex *ptr = &a;
	ptr->real = 100; //구조체 포인터변수의 멤버 접근방법 ==> 구조체 포인터 변수이름->멤버변수이름
	ptr->imag = 200;

	printComplex(ptr);
	conjugate(ptr);
	//printf("%f %f\n",ptr->real,ptr->imag);

	return 0;
}