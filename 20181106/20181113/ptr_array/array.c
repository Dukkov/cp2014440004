#include <stdio.h>

//printArr()
//�Է� : �迭
//��� : ����
//�μ�ȿ�� : ȭ�鿡 �迭�� ���
//void printArr(int* arr, int len) �̷������� �Լ����ǵ� ����
void printArr(int arr[], int len)
{
	int index;
	for (index = 0; index<len; index++) {
		printf("%d\n",arr[index]);
	}
}

int main()
{
	int arr[] = {1,2,3};
	int* ptr = arr; //ptr = &arr[0]

	printArr(arr, sizeof(arr)/sizeof(int));

	//�����ͺ��� �̸��� �迭 �̸����� ����� �� �ִ�.
	printf("%d\n",ptr[0]);
	printf("%d\n",*ptr);

	// arr = ptr; ������ ������ �߻��ϴµ�, �迭�̸�(arr)�� ���� ������ rvalue�̱� �����̴�.
	// 10 = arr[2]; ���� ���� ������ ����.
	

	return 0;
}