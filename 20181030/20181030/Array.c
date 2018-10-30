#include <stdio.h>

//함수 printArray()
//입력 : 배열
//출력 : 없음
//부수효과 : 화면에 모든 배열요소 출력
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

	//배열 선언
	//1. 배열 이름 : a
	//2. 배열요소 자료형 : int
	//3. 배열의 길이 : 4
	int a[4] = {20,200,2000,20000}; //배열 초기화
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