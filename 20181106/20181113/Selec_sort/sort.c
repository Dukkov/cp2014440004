#include <stdio.h>

//함수 : findMinindex()
//입력 : 배열(배열이름, 배열길이, 시작인덱스)
//출력 : 최소값의 인덱스
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

//함수 : findMin()
//입력 : 배열(배열이름, 배열길이, 시작인덱스)
//출력 : 배열의 최소값
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

//함수 : swap()
//입력 : 배열, 두개의 인덱스
//출력 : 없음
//부수효과 : 입력된 두 인덱스의 위치전환
void swap(int* arr, int i, int j) 
{
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//함수 : selecSort()
//입력 : 배열
//출력 : 없음
//부수효과 : 배열정렬
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