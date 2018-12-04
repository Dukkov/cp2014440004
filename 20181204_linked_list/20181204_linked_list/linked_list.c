#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int score;
	struct node* pNext;
} Node;

//�Լ� printList()
//�Է� : linked list�� ����� ������
//��� : ����
//�μ�ȿ�� : ����

void printList(Node* head)
{
	while (head != NULL) {
		printf("score = %d\n", head->score);
		head = head->pNext;
	}
}

//�Լ� createNode() 
//�Է� : ����
//��� : ��� �ϳ��� �޸� �����Ҵ����� ������ ��ȯ
//�μ�ȿ�� : ����
Node* createNode(int input)
{
	Node* ptr;
	ptr = (Node*)malloc(sizeof(Node));
	ptr->score = input;
	ptr->pNext = NULL;
	
	return ptr;
}

//�Լ� addHead()
//�Է� : ���Ḯ��Ʈ, �� ���
//��� : ����
//�μ�ȿ�� : ���Ḯ��Ʈ ��� �ٷ� ������ �� ��带 �߰�
void addHead(Node** head, Node* newNode,int input) //pHead�� ���� �ٲ�� �ϱ� ������ ���������͸� ���ڷ� �޴´�.
{
	newNode->score = input;
	newNode->pNext = *head;
	*head = newNode;
}

int main()
{
	Node a, b, c;
	Node* pHead; //����� �����ͺ���
	
	a.score = 10;
	b.score = 20;
	a.pNext = &b; 
	b.pNext = NULL;

	pHead = createNode(10);
	pHead->pNext = createNode(20); //(*a).pNext = createNode(20)�� ���� �ڵ�
	addHead(&pHead, &c, 5);
	printList(pHead);

	return 0;
}