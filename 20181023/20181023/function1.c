#include <stdio.h>

//�Լ� sum()
//�Է� : �� ����
//��� : �� ������ ��
//�μ�ȿ�� : ����

int sum(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

//�Լ� : goodPrint()
//�Է� : ����
//��� : ����
//�μ�ȿ�� : ȭ�鿡 good ���
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