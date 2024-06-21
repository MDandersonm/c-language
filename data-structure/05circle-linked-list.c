#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "040linked-list.h"



//����Ʈ�� ù��° ��� ���� ����
void addCircleFirstNode(linkedList_h* L, char* x) {//char* x[] �� �̷��� �����ؼ� ǥ������
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	/*
	C���� �迭�� �ٸ� �迭�̳� ���ڿ��� ���� �Ҵ��ϴ� ���� ������ �ʽ��ϴ�.
	���, ���ڿ��� �����Ϸ��� strcpy �Լ� �Ǵ� �ٸ� ���ڿ� ���� ����� ����ؾ� �մϴ�.*/
	//newNode->data = x; // ����
	strcpy(newNode->data, x);
	//strncpy(newNode->data, x, sizeof(newNode->data) - 1);  // ������ �ִ� ���� ���� �迭 ũ�� - 1
	//newNode->data[sizeof(newNode->data) - 1] = '\0';  // ��������� �� ���� ���� �߰�


	//newNode->link = NULL; //�������� ����Ʈ������ NULL��������ȵ�

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		L->head = newNode;
		newNode->link = newNode;
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��
	listNode* temp= L->head;
	while (L->head !=temp->link) { //������ ��� ã��
		temp = temp->link;
	}
	temp->link = newNode;
	newNode->link = L->head;
	L->head = newNode;
	
}



//����Ʈ���

void printCircleList(linkedList_h* L) {
	if (L->head == NULL) {
		printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
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


//�޸�����

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
	free(L->head); // ù ��° ��带 �������� ����
	free(L); // ����Ʈ ����ü �޸� ����
}

//�߰���� �����ϱ�
void deleteCircleMiddleNode(linkedList_h* L, int position) {

	if (L->head == NULL) {//���鸮��Ʈ�ΰ��
		return;
	}

	//���鸮��Ʈ�� �ƴѰ��



	if (position == 0) {//ù��� ����
		listNode* lastNode = L->head;
		do{
			lastNode = lastNode->link;

		}while (lastNode->link != L->head);
		//lastNode�� ���������

		listNode* toDelete = L->head;

		if (L->head->link == L->head) { // ����Ʈ�� ��尡 �ϳ��� �ִ� ���
			L->head = NULL;
		}
		else {
			lastNode->link = L->head->link; // ������ ����� link�� ù ��° ����� ���� ���� ������Ʈ
			L->head = L->head->link; // ���ο� head ����
		}

		free(toDelete); // ������ ù ��° ��� ����
		return;
	}
	
	listNode* temp = L->head;
	listNode* prev = NULL;
	int cnt = 0;
	while (cnt < position && temp->link != L->head) { // ����Ʈ�� �� �Ǵ� ���ϴ� ��ġ�� ������ ������ ��ȸ
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
	printf("<1> ���鸮��Ʈ �����ϱ�\n");
	printCircleList(L);

	printf("<2> ����Ʈ�� ù��° ��忡 '�ݸ��ȭ�� ������' �߰��ϱ�\n");
	addCircleFirstNode(L, "��");
	addCircleFirstNode(L, "��");
	addCircleFirstNode(L, "��");
	addCircleFirstNode(L, "ȭ");
	addCircleFirstNode(L, "��");
	printCircleList(L);
	/*
	printf("<2> ����Ʈ�� �߰� ��忡  �߰��ϱ�\n");
	addMiddleNode(L, 0, "0��");
	addMiddleNode(L, 4, "4��");
	printList(L);

	printf("<3> ����Ʈ �������� ��� '��' �Ѱ� �߰��ϱ�\n");
	addLastNode(L, "��");
	printList(L);
	*/
	printf("<4> �߰� ��� �����ϱ� (3���ε��� ��� ���� ) \n");
	deleteCircleMiddleNode(L, 3);
	printCircleList(L);
	
	printf("<6> ����Ʈ ������ �����Ͽ� ���鸮��Ʈ ���·� �����\n");

	freeCircleLinkedList_h(L);

	return 0;
}