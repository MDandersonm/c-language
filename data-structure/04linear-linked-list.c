#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include "040linked-list.h"



//공백연결 리스트 생성 연산
linkedList_h* createLinkedList_h() {
	linkedList_h* L                    ;

	//첫 번째 malloc 호출은 linkedList_h 타입의 객체에 필요한 메모리를 할당하고, 
	// 그 메모리의 주소를 포인터 L에 저장합니다 이는 새로운 연결 리스트의 "헤드"를 생성하는 과정입니다. 
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL; //공백리스트이므로 NULL로 설정
	return L;
}



//공백리스트 메모리 해제
/*
void freeLinkedList_h(linkedList_h* L) {
	listNode* current = L->head;
	while (current != NULL) {
		listNode* next = current->link;
		free(current);
		current = next;
	}
	free(L);
}
*/
void freeLinkedList_h(linkedList_h* L) {
	listNode* temp;
	while (L->head != NULL) {
		temp = L->head;
		L->head = L->head->link;
		free(temp);
		temp = NULL;
	}
	free(L);
}
//리스트의 첫번째 노드 삽입 연산
void addFirstNode(linkedList_h* L, char* x) {//char* x[] 를 이렇게 생략해서 표현가능
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C에서 배열에 다른 배열이나 문자열을 직접 할당하는 것은 허용되지 않습니다.
	대신, 문자열을 복사하려면 strcpy 함수 또는 다른 문자열 복사 방법을 사용해야 합니다.*/
	//newNode->data = x; // 에러
	strcpy(newNode->data, x);


	newNode->link = NULL;

	if (L->head == NULL) {//공백리스트인경우
		L->head = newNode;
		return;
	}

	//공백리스트가 아닌경우
	newNode->link = L->head;
	L->head = newNode;
}


//리스트의 중간에 노드 삽입 연산(position 인덱스에 삽입)
/*
	C에서 배열에 다른 배열이나 문자열을 직접 할당하는 것은 허용되지 않습니다.
	대신, 문자열을 복사하려면 strcpy 함수 또는 다른 문자열 복사 방법을 사용해야 합니다.*/

/*
void addMiddleNode(linkedList_h* L, int position, char* x) {
	// 리스트가 비어 있거나, position이 0 또는 음수인 경우, 첫 번째 노드로 삽입
	if (L->head == NULL || position <= 0) {
		addFirstNode(L, x);
		return;
	}

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	listNode* temp = L->head;
	listNode* prev = NULL;

	// position - 1 위치까지 이동 (즉, 삽입할 위치의 바로 앞 노드를 찾음)
	for (int i = 0; temp != NULL && i < position - 1; i++) {
		prev = temp;
		temp = temp->link;
	}

	// 리스트의 끝에 도달했거나, position이 리스트 길이보다 큰 경우, 마지막 노드로 삽입
	if (temp == NULL) {
		addLastNode(L, x);
	}
	else {
		// 중간에 노드 삽입
		newNode->link = temp->link; // 새 노드의 link를 temp의 다음 노드로 설정
		temp->link = newNode; // temp(삽입할 위치의 바로 앞 노드)의 link를 새 노드로 설정
	}
}
*/

void addMiddleNode(linkedList_h* L, int position, char* x) {//char* x[] 를 이렇게 생략해서 표현가능
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	
	//newNode->data = x; // 에러
	strcpy(newNode->data, x);


	newNode->link = NULL;

	if (L->head == NULL) {//공백리스트인경우
		L->head = newNode;
		return;
	}

	//공백리스트가 아닌경우
	listNode* temp = L->head;
	listNode* prev = NULL;

	int cnt=0;
	if (position == 0) {
		newNode->link = L->head;
		L->head = newNode;
		return;
	}
	while ( cnt !=position && temp->link !=NULL ) {
		prev = temp;//이전노드
		temp = temp->link;
		cnt++;

	}
	printf("cnt: %d\n", cnt);
	if (cnt == position) {
		prev->link = newNode;
		newNode->link = temp;
		printf(" = position cnt: %d\n", cnt);

	}
	else if(temp->link == NULL) {
		temp->link = newNode;
		printf("null cnt: %d\n", cnt);
		printf("newNode->link: %p\n", temp->link);
	
	}

}



//리스트의 마지막 노드 삽입 연산
void addLastNode(linkedList_h* L, char* x) {//char* x[] 를 이렇게 생략해서 표현가능
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C에서 배열에 다른 배열이나 문자열을 직접 할당하는 것은 허용되지 않습니다.
	대신, 문자열을 복사하려면 strcpy 함수 또는 다른 문자열 복사 방법을 사용해야 합니다.*/
	//newNode->data = x; // 에러
	strcpy(newNode->data, x);

	/*
C 언어에서 malloc으로 할당된 메모리는 초기화되지 않습니다. 
즉, 메모리에는 이전에 사용되었던 임의의 값이 남아 있을 수 있습니다.
따라서 newNode->link = NULL;처럼 명시적으로 초기화하는 것은 중요합니다.
초기화하지 않으면, newNode->link에 예측할 수 없는 값을 가지게 되어, 
리스트를 순회하거나 다루는 과정에서 오류가 발생할 수 있습니다.
	*/

	newNode->link = NULL;

	if (L->head == NULL) {//공백리스트인경우
		L->head = newNode;
		return;
	}

	//공백리스트가 아닌경우
	listNode* temp= L->head;
	while (temp->link != NULL) {
		temp = temp->link;
	};
	temp->link = newNode;//newNode의 link는 null로 유지해야 마지막 노드가됨
}



//리스트출력

void printList(linkedList_h* L) {
	printf("L = <");
	listNode* temp= L->head;
	while (temp != NULL) { //마지막 노드의 주소가 NULL이면 멈춤
		printf("%s", temp->data);
		if (temp->link != NULL) {
			printf(", ");
		}
		temp = temp->link;
	};
	printf(">\n");

}


void deleteLastNode(linkedList_h* L) {
	if (L->head == NULL) {
		return;
	}
	listNode* temp = L->head;
	listNode* prev = NULL;

	// 리스트에 노드가 하나만 있는 경우
	if (temp->link == NULL) {
		free(temp); // 그 노드를 해제
		temp = NULL; // 헤드를 NULL로 설정
		return;
	}
	while (temp->link !=NULL) {
		prev = temp;
		temp = temp->link;
	}
	free(temp);
	prev->link = NULL;

}


void deleteFirstNode(linkedList_h* L) {
	if (L->head == NULL) {
		return;
	}
	listNode* temp = L->head;
	L->head = temp->link;
	free(temp);
	temp = NULL;
}


void reverse(linkedList_h* L) {
	if (L->head == NULL || L->head->link == NULL) {
		// 리스트가 비어 있거나 노드가 하나뿐인 경우, 역순으로 변환할 필요가 없음
		return;
	}

	listNode* current = L->head;
	listNode* prev = NULL;
	listNode* next = NULL;
	while(current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	L->head = prev;

}


int main040() {

	

	linkedList_h* L;
	L = createLinkedList_h();
	printf("<1> 공백리스트 생성하기\n");
	printList(L);

	printf("<2> 리스트에 첫번째 노드에 '금목수화월 순서로' 추가하기\n");
	addFirstNode(L, "금");
	addFirstNode(L, "목");
	addFirstNode(L, "수");
	addFirstNode(L, "화");
	addFirstNode(L, "월");
	printList(L);
	
	printf("<2> 리스트에 중간 노드에  추가하기\n");
	addMiddleNode(L, 0, "0번");
	addMiddleNode(L, 4, "4번");
	printList(L);

	printf("<3> 리스트 마지막에 노드 '일' 한개 추가하기\n");
	addLastNode(L,"일");
	printList(L);
	printf("<4> 마지막 노드 삭제하기\n");
	deleteLastNode(L);
	printList(L);
	printf("<4> 첫번쨰 노드 삭제하기\n");
	deleteFirstNode(L);
	printList(L);
	printf("<4> 중간 노드 삭제하기\n");


	printf("<5> 리스트 원소를 역순으로 변환하기!\n");
	reverse(L);
	printList(L);
	printf("<6> 리스트 공간을 해제하여 공백리스트 상태로 만들기\n");

	freeLinkedList_h(L);

	return 0;
}