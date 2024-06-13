#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "040linked-list.h"



//���鿬�� ����Ʈ ���� ����
linkedList_h* createLinkedList_h() {
	linkedList_h* L                    ;

	//ù ��° malloc ȣ���� linkedList_h Ÿ���� ��ü�� �ʿ��� �޸𸮸� �Ҵ��ϰ�, 
	// �� �޸��� �ּҸ� ������ L�� �����մϴ� �̴� ���ο� ���� ����Ʈ�� "���"�� �����ϴ� �����Դϴ�. 
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL; //���鸮��Ʈ�̹Ƿ� NULL�� ����
	return L;
}



//���鸮��Ʈ �޸� ����
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
//����Ʈ�� ù��° ��� ���� ����
void addFirstNode(linkedList_h* L, char* x) {//char* x[] �� �̷��� �����ؼ� ǥ������
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C���� �迭�� �ٸ� �迭�̳� ���ڿ��� ���� �Ҵ��ϴ� ���� ������ �ʽ��ϴ�.
	���, ���ڿ��� �����Ϸ��� strcpy �Լ� �Ǵ� �ٸ� ���ڿ� ���� ����� ����ؾ� �մϴ�.*/
	//newNode->data = x; // ����
	strcpy(newNode->data, x);


	newNode->link = NULL;

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		L->head = newNode;
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��
	newNode->link = L->head;
	L->head = newNode;
}


//����Ʈ�� �߰��� ��� ���� ����(position �ε����� ����)
/*
	C���� �迭�� �ٸ� �迭�̳� ���ڿ��� ���� �Ҵ��ϴ� ���� ������ �ʽ��ϴ�.
	���, ���ڿ��� �����Ϸ��� strcpy �Լ� �Ǵ� �ٸ� ���ڿ� ���� ����� ����ؾ� �մϴ�.*/

/*
void addMiddleNode(linkedList_h* L, int position, char* x) {
	// ����Ʈ�� ��� �ְų�, position�� 0 �Ǵ� ������ ���, ù ��° ���� ����
	if (L->head == NULL || position <= 0) {
		addFirstNode(L, x);
		return;
	}

	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	listNode* temp = L->head;
	listNode* prev = NULL;

	// position - 1 ��ġ���� �̵� (��, ������ ��ġ�� �ٷ� �� ��带 ã��)
	for (int i = 0; temp != NULL && i < position - 1; i++) {
		prev = temp;
		temp = temp->link;
	}

	// ����Ʈ�� ���� �����߰ų�, position�� ����Ʈ ���̺��� ū ���, ������ ���� ����
	if (temp == NULL) {
		addLastNode(L, x);
	}
	else {
		// �߰��� ��� ����
		newNode->link = temp->link; // �� ����� link�� temp�� ���� ���� ����
		temp->link = newNode; // temp(������ ��ġ�� �ٷ� �� ���)�� link�� �� ���� ����
	}
}
*/

void addMiddleNode(linkedList_h* L, int position, char* x) {//char* x[] �� �̷��� �����ؼ� ǥ������
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	
	//newNode->data = x; // ����
	strcpy(newNode->data, x);


	newNode->link = NULL;

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		L->head = newNode;
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��
	listNode* temp = L->head;
	listNode* prev = NULL;

	int cnt=0;
	if (position == 0) {
		newNode->link = L->head;
		L->head = newNode;
		return;
	}
	while ( cnt !=position && temp->link !=NULL ) {
		prev = temp;//�������
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



//����Ʈ�� ������ ��� ���� ����
void addLastNode(linkedList_h* L, char* x) {//char* x[] �� �̷��� �����ؼ� ǥ������
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C���� �迭�� �ٸ� �迭�̳� ���ڿ��� ���� �Ҵ��ϴ� ���� ������ �ʽ��ϴ�.
	���, ���ڿ��� �����Ϸ��� strcpy �Լ� �Ǵ� �ٸ� ���ڿ� ���� ����� ����ؾ� �մϴ�.*/
	//newNode->data = x; // ����
	strcpy(newNode->data, x);

	/*
C ���� malloc���� �Ҵ�� �޸𸮴� �ʱ�ȭ���� �ʽ��ϴ�. 
��, �޸𸮿��� ������ ���Ǿ��� ������ ���� ���� ���� �� �ֽ��ϴ�.
���� newNode->link = NULL;ó�� ��������� �ʱ�ȭ�ϴ� ���� �߿��մϴ�.
�ʱ�ȭ���� ������, newNode->link�� ������ �� ���� ���� ������ �Ǿ�, 
����Ʈ�� ��ȸ�ϰų� �ٷ�� �������� ������ �߻��� �� �ֽ��ϴ�.
	*/

	newNode->link = NULL;

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		L->head = newNode;
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��
	listNode* temp= L->head;
	while (temp->link != NULL) {
		temp = temp->link;
	};
	temp->link = newNode;//newNode�� link�� null�� �����ؾ� ������ ��尡��
}



//����Ʈ���

void printList(linkedList_h* L) {
	printf("L = <");
	listNode* temp= L->head;
	while (temp != NULL) { //������ ����� �ּҰ� NULL�̸� ����
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

	// ����Ʈ�� ��尡 �ϳ��� �ִ� ���
	if (temp->link == NULL) {
		free(temp); // �� ��带 ����
		temp = NULL; // ��带 NULL�� ����
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
		// ����Ʈ�� ��� �ְų� ��尡 �ϳ����� ���, �������� ��ȯ�� �ʿ䰡 ����
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
	printf("<1> ���鸮��Ʈ �����ϱ�\n");
	printList(L);

	printf("<2> ����Ʈ�� ù��° ��忡 '�ݸ��ȭ�� ������' �߰��ϱ�\n");
	addFirstNode(L, "��");
	addFirstNode(L, "��");
	addFirstNode(L, "��");
	addFirstNode(L, "ȭ");
	addFirstNode(L, "��");
	printList(L);
	
	printf("<2> ����Ʈ�� �߰� ��忡  �߰��ϱ�\n");
	addMiddleNode(L, 0, "0��");
	addMiddleNode(L, 4, "4��");
	printList(L);

	printf("<3> ����Ʈ �������� ��� '��' �Ѱ� �߰��ϱ�\n");
	addLastNode(L,"��");
	printList(L);
	printf("<4> ������ ��� �����ϱ�\n");
	deleteLastNode(L);
	printList(L);
	printf("<4> ù���� ��� �����ϱ�\n");
	deleteFirstNode(L);
	printList(L);
	printf("<4> �߰� ��� �����ϱ�\n");


	printf("<5> ����Ʈ ���Ҹ� �������� ��ȯ�ϱ�!\n");
	reverse(L);
	printList(L);
	printf("<6> ����Ʈ ������ �����Ͽ� ���鸮��Ʈ ���·� �����\n");

	freeLinkedList_h(L);

	return 0;
}