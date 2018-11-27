#include <stdio.h>
#include <stdlib.h>

//����ü ���� : ������ ������ Ÿ������ ������ ���ο� ������ Ÿ���� �����Ѵ�.
typedef struct complex {
	double real;
	double imag;
} Complex;

//������ Ÿ���� ���� ����
typedef int myintType;

//�Լ� printComplex()
//�Է� : ���Ҽ�
//��� : ����
//�μ�ȿ�� : ����
void printComplex(Complex *x)
{
	printf("%f + j%f\n", x->real,x->imag);
}

//�Լ� conjugate()
//�Է� : ���Ҽ�(������)
//��� : ����
//�μ�ȿ�� : �Էµ� ���Ҽ��� �ӷ� ���Ҽ��� ��ȯ��
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

	//����ü ������ ����
	Complex a,b; //����ü������ ��� ���ٹ�� ==> ����ü�����̸�.��������̸�
	//a.real = 10;
	//a.imag = 20;

	//printf("%d %d\n",a.real,a.imag);
	//����ü ������ ���� ����
	Complex *ptr = &a;
	ptr->real = 100; //����ü �����ͺ����� ��� ���ٹ�� ==> ����ü ������ �����̸�->��������̸�
	ptr->imag = 200;

	printComplex(ptr);
	conjugate(ptr);
	//printf("%f %f\n",ptr->real,ptr->imag);

	return 0;
}