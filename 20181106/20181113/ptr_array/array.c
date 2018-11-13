#include <stdio.h>

//printArr()
//입력 : 배열
//출력 : 없음
//부수효과 : 화면에 배열값 출력
//void printArr(int* arr, int len) 이런식으로 함수정의도 가능
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

	//포인터변수 이름을 배열 이름으로 사용할 수 있다.
	printf("%d\n",ptr[0]);
	printf("%d\n",*ptr);

	// arr = ptr; 문장은 에러가 발생하는데, 배열이름(arr)는 값만 가지는 rvalue이기 때문이다.
	// 10 = arr[2]; 위와 같은 이유의 에러.
	

	return 0;
}