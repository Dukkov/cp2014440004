#include <stdio.h>

//�Լ� printArray()
//�Է� : �迭
//��� : ����
//�μ�ȿ�� : ȭ�鿡 ��� �迭��� ���
void printArray(int arr[], int len) {
	int count = 0;
	while(count < len) {
		printf("%d\n", arr[count]);
		count++;
	}
}

int main()
{
	int len =4;

	//�迭 ����
	//1. �迭 �̸� : a
	//2. �迭��� �ڷ��� : int
	//3. �迭�� ���� : 4
	int a[4] = {20,200,2000,20000}; //�迭 �ʱ�ȭ
	int arr[3] = {1,2,3};
	/*int count = 0;
	while(count <3) {
		printf("%d\n",arr[count]);
		count++;
	}*/
	int k = sizeof(arr) / sizeof(int);
	printArray(arr,k);
	
	return 0;
}