#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>


typedef struct ListNode {//�ܼ� ���Ḯ��Ʈ�� ��� ���� ����
	char data[4];
	struct ListNode* link;
}listNode;


typedef struct {//����Ʈ�� ����� ���� ����
	listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h();



#endif