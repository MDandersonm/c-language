#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include "0140queue02.h"




LQueueType* createLinkedQueue() {
	LQueueType* lq = (LQueueType*)malloc(sizeof(LQueueType));
	lq->front = NULL;
	lq->rear = NULL;

	return lq;

}

int isLinkedQueueEmpty(LQueueType* lq) {
	if (lq->front == NULL && lq->rear == NULL) {
		return 1;//비었음
	}
	return 0;

}

void enLinkedQueue(LQueueType* lq, element item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if (isLinkedQueueEmpty(lq)) {
		lq->rear = newNode;
		lq->front = newNode;
		return;
	}

	lq->rear->link = newNode;
	lq->rear = newNode;


}

element deLinkedQueue(LQueueType* lq) {

	if (isLinkedQueueEmpty(lq)) {
		return '\0'; //
	}
	QNode* temp = lq->front;
	lq->front = lq->front->link;
	element result = temp->data;

	if (lq->front == NULL) {
		lq->rear = NULL; // 모든 요소가 삭제되었을 때 rear도 NULL로 설정
	}
	free(temp);
	return result;
}

element peekLinkedQueue(LQueueType* lq) {

	if (isLinkedQueueEmpty(lq)) {
		return '\0'; // 수정: 유효하지 않은 값 반환
	}

	return lq->front->data;
}


void printLQ(LQueueType* lq) {
	printf("  QUEUE : [ ");
	QNode* temp = lq->front;
	while (temp != lq->rear) {
		printf("%c ,", temp->data);
		temp = temp->link;
	}
	printf("%c ]\n", temp->data);

}

void printLQint(LQueueType* lq) {
	printf("  QUEUE : [ ");
	QNode* temp = lq->front;
	while (temp != lq->rear) {
		printf("%d ,", temp->data);
		temp = temp->link;
	}
	printf("%d ]\n", temp->data);

}


void freeQueue1(LQueueType* lq) {
	QNode* temp;
	while (lq->front != NULL) {  // 큐의 모든 노드를 순회
		temp = lq->front;  // 현재 노드를 임시 변수에 저장
		lq->front = lq->front->link;  // front를 다음 노드로 이동
		free(temp);  // 현재 노드의 메모리 해제
	}
	lq->rear = NULL;  // rear를 NULL로 설정하여 큐가 비어 있음을 표시
}


int main0140() {
	LQueueType* lq1 = createLinkedQueue();
	element data;
	printf("삽입A>>");
	enLinkedQueue(lq1, 'A');
	printLQ(lq1);

	printf("삽입B>>");
	enLinkedQueue(lq1, 'B');
	printLQ(lq1);


	printf("삭제>>");
	deLinkedQueue(lq1);
	printLQ(lq1);


	printf("삽입C>>");
	enLinkedQueue(lq1, 'C');
	printLQ(lq1);

	data = peekLinkedQueue(lq1);
	printf("peek item : %c \n", data);

	printf("삽입D>>");
	enLinkedQueue(lq1, 'D');
	printLQ(lq1);

	printf("삽입E>>");
	enLinkedQueue(lq1, 'E');
	printLQ(lq1);


	free(lq1); // 큐 구조체 메모리 해제


	return 0;
}