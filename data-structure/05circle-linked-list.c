#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include "040linked-list.h"



//리스트의 첫번째 노드 삽입 연산
void addCircleFirstNode(linkedList_h* L, char* x) {//char* x[] 를 이렇게 생략해서 표현가능
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C에서 배열에 다른 배열이나 문자열을 직접 할당하는 것은 허용되지 않습니다.
	대신, 문자열을 복사하려면 strcpy 함수 또는 다른 문자열 복사 방법을 사용해야 합니다.*/
	//newNode->data = x; // 에러
	strcpy(newNode->data, x);
	//strncpy(newNode->data, x, sizeof(newNode->data) - 1);  // 복사할 최대 문자 수는 배열 크기 - 1
	//newNode->data[sizeof(newNode->data) - 1] = '\0';  // 명시적으로 널 종료 문자 추가


	//newNode->link = NULL; //원형연결 리스트에서는 NULL이있으면안됨

	if (L->head == NULL) {//공백리스트인경우
		L->head = newNode;
		newNode->link = newNode;
		return;
	}

	//공백리스트가 아닌경우
	listNode* temp= L->head;
	while (L->head !=temp->link) { //마지막 노드 찾기
		temp = temp->link;
	}
	temp->link = newNode;
	newNode->link = L->head;
	L->head = newNode;
	
}



//리스트출력

void printCircleList(linkedList_h* L) {
	if (L->head == NULL) {
		printf("리스트가 비어 있습니다.\n");
		return;
	}

	printf("L = <");
	listNode* temp = L->head;
	do {
		printf("%s", temp->data);
		temp = temp->link;
		if (temp != L->head) {
			printf(", ");
		}
	} while (temp != L->head);
	printf(">\n");
}


//메모리해제

void freeCircleLinkedList_h(linkedList_h* L) {
	if (L->head == NULL) {
		free(L);
		return;
	}

	listNode* temp = L->head->link;
	while (temp != L->head) {
		listNode* toDelete = temp;
		temp = temp->link;
		free(toDelete);
	}
	free(L->head); // 첫 번째 노드를 마지막에 해제
	free(L); // 리스트 구조체 메모리 해제
}

//중간노드 삭제하기
void deleteCircleMiddleNode(linkedList_h* L, int position) {

	if (L->head == NULL) {//공백리스트인경우
		return;
	}

	//공백리스트가 아닌경우



	if (position == 0) {//첫노드 삭제
		listNode* lastNode = L->head;
		do{
			lastNode = lastNode->link;

		}while (lastNode->link != L->head);
		//lastNode는 마지막노드

		listNode* toDelete = L->head;

		if (L->head->link == L->head) { // 리스트에 노드가 하나만 있는 경우
			L->head = NULL;
		}
		else {
			lastNode->link = L->head->link; // 마지막 노드의 link를 첫 번째 노드의 다음 노드로 업데이트
			L->head = L->head->link; // 새로운 head 설정
		}

		free(toDelete); // 원래의 첫 번째 노드 해제
		return;
	}
	
	listNode* temp = L->head;
	listNode* prev = NULL;
	int cnt = 0;
	while (cnt < position && temp->link != L->head) { // 리스트의 끝 또는 원하는 위치에 도달할 때까지 순회
		prev = temp;
		temp = temp->link;
		cnt++;
	}


	printf("cnt: %d\n", cnt);
	if (cnt == position) {
		prev->link = temp->link;
		free(temp);
		temp = NULL;

	}

}

int main050() {



	linkedList_h* L;
	L = createLinkedList_h();
	printf("<1> 공백리스트 생성하기\n");
	printCircleList(L);

	printf("<2> 리스트에 첫번째 노드에 '금목수화월 순서로' 추가하기\n");
	addCircleFirstNode(L, "금");
	addCircleFirstNode(L, "목");
	addCircleFirstNode(L, "수");
	addCircleFirstNode(L, "화");
	addCircleFirstNode(L, "월");
	printCircleList(L);
	/*
	printf("<2> 리스트에 중간 노드에  추가하기\n");
	addMiddleNode(L, 0, "0번");
	addMiddleNode(L, 4, "4번");
	printList(L);

	printf("<3> 리스트 마지막에 노드 '일' 한개 추가하기\n");
	addLastNode(L, "일");
	printList(L);
	*/
	printf("<4> 중간 노드 삭제하기 (3번인덱스 노드 삭제 ) \n");
	deleteCircleMiddleNode(L, 3);
	printCircleList(L);
	
	printf("<6> 리스트 공간을 해제하여 공백리스트 상태로 만들기\n");

	freeCircleLinkedList_h(L);

	return 0;
}