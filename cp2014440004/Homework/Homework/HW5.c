#include <stdio.h>

//�޴��� ����ϰ� ����ڷκ��� �Է¹޾� ���õ� �޴��� ����ϴ� ���α׷�

int main() {

	char str[30];

	printf("choose one of the following.\n");
	printf("apple\norange\nbanana\npeach\n");
	printf("enter your choice here : ");
	gets_s(str);

	printf("Your choice is %s\n",str);
	return 0;
}
