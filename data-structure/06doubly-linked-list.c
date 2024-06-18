#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "040linked-list.h"



typedef struct Dnode {//���� ���Ḯ��Ʈ�� ��� ���� ����
	struct Dnode* llink;
	char data[4];
	struct Dnode* rlink;
}dNode;


typedef struct {//����Ʈ�� ����� ���� ����
	dNode* head;
} doublyLinkedList_h;



//���鿬�� ����Ʈ ���� ����
doublyLinkedList_h* createDoublyLinkedList_h() {
	doublyLinkedList_h* L;

	//ù ��° malloc ȣ���� linkedList_h Ÿ���� ��ü�� �ʿ��� �޸𸮸� �Ҵ��ϰ�, 
	// �� �޸��� �ּҸ� ������ L�� �����մϴ� �̴� ���ο� ���� ����Ʈ�� "���"�� �����ϴ� �����Դϴ�. 
	L = (doublyLinkedList_h*)malloc(sizeof(doublyLinkedList_h));
	L->head = NULL; //���鸮��Ʈ�̹Ƿ� NULL�� ����
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

//����Ʈ���

void printDoublyList(doublyLinkedList_h* L) {
	printf("L = <");
	dNode* temp = L->head;
	while (temp != NULL) { //������ ����� �ּҰ� NULL�̸� ����
		printf("%s", temp->data);
		if (temp->rlink != NULL) {
			printf(", ");
		}
		temp = temp->rlink;
	};
	printf(">\n");

}


// �߰��� ������
void addMiddleDnode(doublyLinkedList_h* L, int position, char* x) {//char* x[] �� �̷��� �����ؼ� ǥ������
	dNode* newNode = (dNode*)malloc(sizeof(dNode));


	//newNode->data = x; // ����
	strcpy(newNode->data, x);


	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		L->head = newNode;
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��
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
		if (prev != NULL) { // ���� ��尡 �����ϸ�
			prev->rlink = newNode; // ���� ����� ������ ��ũ�� �� ���� ����
		}
		if (temp != NULL) { // ���� ���(temp)�� �����ϸ�
			temp->llink = newNode; // ���� ����� ���� ��ũ�� �� ���� ����
		}
		*/
	
		printf(" = position cnt: %d\n", cnt);

	}
	else if (temp->rlink == NULL) {//temp�� ���������
		temp->rlink = newNode;
		newNode->llink = temp; // �� ����� ���� ��ũ�� ���� ���(temp)�� ����
		printf("null cnt: %d\n", cnt);
		printf("newNode->link: %p\n", temp->rlink);

	}

}


//�߰���� �����ϱ�
void deleteMiddleDnode(doublyLinkedList_h* L, int position) {

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		return;
	}
	//���鸮��Ʈ�� �ƴѰ��

	if (position == 0) {//ù��� ����
		dNode* firstNode = L->head;
		if (L->head->rlink == NULL) { // ����Ʈ�� ��尡 �ϳ��� �ִ� ���
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
	while (cnt < position && temp->rlink !=NULL ) { // ����Ʈ�� �� �Ǵ� ���ϴ� ��ġ�� ������ ������ ��ȸ
		prev = temp;
		
		temp = temp->rlink;
		cnt++;
	}
	printf("cnt: %d\n", cnt);
	if (cnt == position) {
		if (temp->rlink == NULL) { //�� ������ ����� ���
			prev->rlink = NULL;
		}else{//�Ǹ������尡 �ƴҋ�
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
	printf("<1> ���鸮��Ʈ �����ϱ�\n");
	printDoublyList(L);

	printf("<2> ����Ʈ�� ù��° ��忡 '�ݸ��ȭ�� ������' �߰��ϱ�\n");
	addMiddleDnode(L, 0,"��");
	addMiddleDnode(L, 0,"��");
	addMiddleDnode(L,0, "��");
	addMiddleDnode(L,0, "ȭ");
	addMiddleDnode(L,0, "��");
	printDoublyList(L);
	
	printf("<2> ����Ʈ�� �߰� ��忡  �߰��ϱ�\n");
	addMiddleDnode(L, 3, "3��");
	printDoublyList(L);
	addMiddleDnode(L, 5, "5��");
	printDoublyList(L);
	addMiddleDnode(L, 7, "7��");
	printDoublyList(L);


	printf("<4> �߰� ��� �����ϱ� (3���ε��� ��� ���� ) \n");
	deleteMiddleDnode(L, 3);
	printDoublyList(L);

	printf("<6> ����Ʈ ������ �����Ͽ� ���鸮��Ʈ ���·� �����\n");

	freeDoublyLinkedList_h(L);

	return 0;
}