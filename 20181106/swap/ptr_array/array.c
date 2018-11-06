#include <stdio.h>

//printArr()
//입력 : 배열
//출력 : 없음
//부수효과 : 화면에 배열값 출력
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

	//printArr(arr, sizeof(arr)/sizeof(int));

	//포인터변수 이름을 배열 이름으로 사용할 수 있다.
	printf("%d\n",ptr[0]);
	printf("%d\n",*ptr);
	

	return 0;
}