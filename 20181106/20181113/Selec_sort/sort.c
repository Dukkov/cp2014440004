#include <stdio.h>

//�Լ� : findMinindex()
//�Է� : �迭(�迭�̸�, �迭����, �����ε���)
//��� : �ּҰ��� �ε���
int findMinindex(int* arr, int len, int index) 
{
	int cnt;
	for(cnt=index; cnt<len; cnt++) {
		if(arr[index] > arr[cnt]) {
			index = cnt;
		}
	}
	return index;
}

//�Լ� : findMin()
//�Է� : �迭(�迭�̸�, �迭����, �����ε���)
//��� : �迭�� �ּҰ�
int findMin(int arr[], int len, int index)
{
	int min = arr[index];
	while(index<len) {
		if(min > arr[index]) {
			min = arr[index];
		}
		index++;
	}

	return min;
}

void printArr(int arr[], int len)
{
	int index;
	for(index =0; index<len; index++) {
		printf("< %d > ",arr[index]);
	}
}

//�Լ� : swap()
//�Է� : �迭, �ΰ��� �ε���
//��� : ����
//�μ�ȿ�� : �Էµ� �� �ε����� ��ġ��ȯ
void swap(int* arr, int i, int j) 
{
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//�Լ� : selecSort()
//�Է� : �迭
//��� : ����
//�μ�ȿ�� : �迭����
void selecSort(int* arr, int len)
{
	int index;
	for(index=0; index<len; index++) {
		swap(arr, index, findMinindex(arr,len,index));
	}
}

int main()
{
	int a[] = {30, 35, 15, 27, 40, 59, 4};

	//printf("%d",findMin(a, 5));
	//printf("%d",findMinindex(a, 5));
	//swap(a, 0, 3);
	selecSort(a, 7);
	printArr(a, 7);

	return 0;
}