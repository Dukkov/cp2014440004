#include <stdio.h>

//�����ʹ� �޸��ּ�, ����Ű�� ������ �ڷ����� �����Ѵ�.
int main()
{
	int a = 10;
	int* ptr; //ptr �����Ͱ� ����Ű�� ������ int��
	ptr = &a; //ptr�� ���� a�� ����Ų��
	*ptr = 20; //*ptr�� ptr �����ͺ����� ����Ű�� ������ ������
	printf("a=%d\n",a);

	return 0;
}