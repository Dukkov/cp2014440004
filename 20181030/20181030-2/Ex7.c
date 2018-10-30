#include <stdio.h>

//7. 정수 배열의 합을 반환하는 함수

int arrSum(int arr[], int len)
{
	int i, result=0;

	for(i=0;i<len;i++) {
		result +=arr[i];
	}

	return result;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int k = sizeof(arr) / sizeof(int);

	printf("%d\n",arrSum(arr,k));

	return 0;
}