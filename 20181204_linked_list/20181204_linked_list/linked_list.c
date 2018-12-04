#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int score;
	struct node* pNext;
} Node;

//함수 printList()
//입력 : linked list의 헤드노드 포인터
//출력 : 없음
//부수효과 : 없음

void printList(Node* head)
{
	while (head != NULL) {
		printf("score = %d\n", head->score);
		head = head->pNext;
	}
}

//함수 createNode() 
//입력 : 성적
//출력 : 노드 하나를 메모리 동적할당으로 생성해 반환
//부수효과 : 없음
Node* createNode(int input)
{
	Node* ptr;
	ptr = (Node*)malloc(sizeof(Node));
	ptr->score = input;
	ptr->pNext = NULL;
	
	return ptr;
}

//함수 addHead()
//입력 : 연결리스트, 새 노드
//출력 : 없음
//부수효과 : 연결리스트 헤드 바로 다음에 새 노드를 추가
void addHead(Node** head, Node* newNode,int input) //pHead의 값을 바꿔야 하기 때문에 더블포인터를 인자로 받는다.
{
	newNode->score = input;
	newNode->pNext = *head;
	*head = newNode;
}

int main()
{
	Node a, b, c;
	Node* pHead; //헤드노드 포인터변수
	
	a.score = 10;
	b.score = 20;
	a.pNext = &b; 
	b.pNext = NULL;

	pHead = createNode(10);
	pHead->pNext = createNode(20); //(*a).pNext = createNode(20)과 같은 코드
	addHead(&pHead, &c, 5);
	printList(pHead);

	return 0;
}