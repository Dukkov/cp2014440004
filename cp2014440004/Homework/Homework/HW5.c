#include <stdio.h>

//메뉴를 출력하고 사용자로부터 입력받아 선택된 메뉴를 출력하는 프로그램

int main() {

	char str[30];

	printf("choose one of the following.\n");
	printf("apple\norange\nbanana\npeach\n");
	printf("enter your choice here : ");
	gets_s(str);

	printf("Your choice is %s\n",str);
	return 0;
}
