#include <stdio.h>
int main () 
{
	// ctrl+k, ctrl+f : Format (소스코드 줄맞춤)
	// ctrl+k ,ctrl+c : Comment out (주석처리)
	// ctrl+k, ctrl+u : Undo comment out (주석처리 취소)

	int count = 1;
	/*while (count <=10) {
	printf("count = %d\n", count++);*/

	//1에서 100까지 3의 배수만 출력
	/*count = 1;
	while(count <= 100)
	{
	if(count%3 == 0) {
	printf("%d\n",count);
	}
	count++;
	}*/

	//1에서 100까지 3의 배수를 제외한 정수만 출력
	/*while(count <=100)
	{
	if(count%3 !=0) {
	printf("%d\n",count);
	}
	count++;
	}*/

	//정수를 입력받아 3의 배수 여부를 알려주는 프로그램. 100을 입력하면 종료한다.
	int input;
	while(1) {
		printf("정수를 입력하십시오 : ");
		scanf_s("%d",&input);
		if(input == 100) {
			break;
		}
		if(input%3 == 0) {
			printf("3의 배수입니다.\n");
		}
		else {
			printf("3의 배수가 아닙니다.\n");
		}
	}
	return 0;
}


