#include <stdio.h>
int main () 
{
	// ctrl+k, ctrl+f : Format (�ҽ��ڵ� �ٸ���)
	// ctrl+k ,ctrl+c : Comment out (�ּ�ó��)
	// ctrl+k, ctrl+u : Undo comment out (�ּ�ó�� ���)

	int count = 1;
	/*while (count <=10) {
	printf("count = %d\n", count++);*/

	//1���� 100���� 3�� ����� ���
	/*count = 1;
	while(count <= 100)
	{
	if(count%3 == 0) {
	printf("%d\n",count);
	}
	count++;
	}*/

	//1���� 100���� 3�� ����� ������ ������ ���
	/*while(count <=100)
	{
	if(count%3 !=0) {
	printf("%d\n",count);
	}
	count++;
	}*/

	//������ �Է¹޾� 3�� ��� ���θ� �˷��ִ� ���α׷�. 100�� �Է��ϸ� �����Ѵ�.
	int input;
	while(1) {
		printf("������ �Է��Ͻʽÿ� : ");
		scanf_s("%d",&input);
		if(input == 100) {
			break;
		}
		if(input%3 == 0) {
			printf("3�� ����Դϴ�.\n");
		}
		else {
			printf("3�� ����� �ƴմϴ�.\n");
		}
	}
	return 0;
}


