#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>


typedef struct ListNode {//단순 연결리스트의 노드 구조 정의
	char data[4];
	struct ListNode* link;
}listNode;


typedef struct {//리스트의 헤드노드 구조 정의
	listNode* head;
} linkedList_h;


linkedList_h* createLinkedList_h();



#endif