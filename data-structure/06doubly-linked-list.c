#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include "040linked-list.h"



typedef struct Dnode {//이중 연결리스트의 노드 구조 정의
	struct Dnode* llink;
	char data[4];
	struct Dnode* rlink;
}dNode;


typedef struct {//리스트의 헤드노드 구조 정의
	dNode* head;
} doublyLinkedList_h;



//공백연결 리스트 생성 연산
doublyLinkedList_h* createDoublyLinkedList_h() {
	doublyLinkedList_h* L;

	//첫 번째 malloc 호출은 linkedList_h 타입의 객체에 필요한 메모리를 할당하고, 
	// 그 메모리의 주소를 포인터 L에 저장합니다 이는 새로운 연결 리스트의 "헤드"를 생성하는 과정입니다. 
	L = (doublyLinkedList_h*)malloc(sizeof(doublyLinkedList_h));
	L->head = NULL; //공백리스트이므로 NULL로 설정
	return L;
}



void freeDoublyLinkedList_h(doublyLinkedList_h* L) {
	dNode * temp;
	while (L->head != NULL) {
		temp = L->head;
		L->head = L->head->llink;
		free(temp);
		temp = NULL;
	}
	free(L);
}

//리스트출력

void printDoublyList(doublyLinkedList_h* L) {
	printf("L = <");
	dNode* temp = L->head;
	while (temp != NULL) { //마지막 노드의 주소가 NULL이면 멈춤
		printf("%s", temp->data);
		if (temp->rlink != NULL) {
			printf(", ");
		}
		temp = temp->rlink;
	};
	printf(">\n");

}


// 중간에 노드삽입
void addMiddleDnode(doublyLinkedList_h* L, int position, char* x) {//char* x[] 를 이렇게 생략해서 표현가능
	dNode* newNode = (dNode*)malloc(sizeof(dNode));


	//newNode->data = x; // 에러
	strcpy(newNode->data, x);


	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (L->head == NULL) {//공백리스트인경우
		L->head = newNode;
		return;
	}

	//공백리스트가 아닌경우
	dNode* temp = L->head;
	dNode* prev = NULL;

	int cnt = 0;
	if (position == 0) {
		newNode->rlink = L->head;
		newNode->llink = NULL;
		L->head->llink = newNode;
		L->head = newNode;
		return;
	}
	while (cnt != position && temp->rlink != NULL) {
		prev = temp;
		temp = temp->rlink;
		cnt++;
	}
	printf("cnt: %d\n", cnt);
	if (cnt == position) {
		prev->rlink = newNode;
		newNode->llink = prev;
		temp->llink = newNode;
		newNode->rlink = temp;
		/*
		if (prev != NULL) { // 이전 노드가 존재하면
			prev->rlink = newNode; // 이전 노드의 오른쪽 링크를 새 노드로 설정
		}
		if (temp != NULL) { // 현재 노드(temp)가 존재하면
			temp->llink = newNode; // 현재 노드의 왼쪽 링크를 새 노드로 설정
		}
		*/
	
		printf(" = position cnt: %d\n", cnt);

	}
	else if (temp->rlink == NULL) {//temp는 마지막노드
		temp->rlink = newNode;
		newNode->llink = temp; // 새 노드의 왼쪽 링크를 현재 노드(temp)로 설정
		printf("null cnt: %d\n", cnt);
		printf("newNode->link: %p\n", temp->rlink);

	}

}


//중간노드 삭제하기
void deleteMiddleDnode(doublyLinkedList_h* L, int position) {

	if (L->head == NULL) {//공백리스트인경우
		return;
	}
	//공백리스트가 아닌경우

	if (position == 0) {//첫노드 삭제
		dNode* firstNode = L->head;
		if (L->head->rlink == NULL) { // 리스트에 노드가 하나만 있는 경우
			L->head = NULL;
		}
		else {

			dNode* next = L->head->rlink;
			next->llink = NULL;
			L->head = next;
		}
		free(firstNode);
		return;
	}

	dNode* temp = L->head;
	dNode* prev = NULL;

	int cnt = 0;
	while (cnt < position && temp->rlink !=NULL ) { // 리스트의 끝 또는 원하는 위치에 도달할 때까지 순회
		prev = temp;
		
		temp = temp->rlink;
		cnt++;
	}
	printf("cnt: %d\n", cnt);
	if (cnt == position) {
		if (temp->rlink == NULL) { //맨 마지막 노드인 경우
			prev->rlink = NULL;
		}else{//맨마지목노드가 아닐떄
			dNode* next = NULL;
			next = temp->rlink;
			prev->rlink = temp->rlink;
			next->llink=prev;

		}
		free(temp);
		temp = NULL;
	}

}



int main060() {

	doublyLinkedList_h* L;
	L = createDoublyLinkedList_h();
	printf("<1> 공백리스트 생성하기\n");
	printDoublyList(L);

	printf("<2> 리스트에 첫번째 노드에 '금목수화월 순서로' 추가하기\n");
	addMiddleDnode(L, 0,"금");
	addMiddleDnode(L, 0,"목");
	addMiddleDnode(L,0, "수");
	addMiddleDnode(L,0, "화");
	addMiddleDnode(L,0, "월");
	printDoublyList(L);
	
	printf("<2> 리스트에 중간 노드에  추가하기\n");
	addMiddleDnode(L, 3, "3번");
	printDoublyList(L);
	addMiddleDnode(L, 5, "5번");
	printDoublyList(L);
	addMiddleDnode(L, 7, "7번");
	printDoublyList(L);


	printf("<4> 중간 노드 삭제하기 (3번인덱스 노드 삭제 ) \n");
	deleteMiddleDnode(L, 3);
	printDoublyList(L);

	printf("<6> 리스트 공간을 해제하여 공백리스트 상태로 만들기\n");

	freeDoublyLinkedList_h(L);

	return 0;
}