#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
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
		return 1;//�����
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
		lq->rear = NULL; // ��� ��Ұ� �����Ǿ��� �� rear�� NULL�� ����
	}
	free(temp);
	return result;
}

element peekLinkedQueue(LQueueType* lq) {

	if (isLinkedQueueEmpty(lq)) {
		return '\0'; // ����: ��ȿ���� ���� �� ��ȯ
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
	while (lq->front != NULL) {  // ť�� ��� ��带 ��ȸ
		temp = lq->front;  // ���� ��带 �ӽ� ������ ����
		lq->front = lq->front->link;  // front�� ���� ���� �̵�
		free(temp);  // ���� ����� �޸� ����
	}
	lq->rear = NULL;  // rear�� NULL�� �����Ͽ� ť�� ��� ������ ǥ��
}


int main0140() {
	LQueueType* lq1 = createLinkedQueue();
	element data;
	printf("����A>>");
	enLinkedQueue(lq1, 'A');
	printLQ(lq1);

	printf("����B>>");
	enLinkedQueue(lq1, 'B');
	printLQ(lq1);


	printf("����>>");
	deLinkedQueue(lq1);
	printLQ(lq1);


	printf("����C>>");
	enLinkedQueue(lq1, 'C');
	printLQ(lq1);

	data = peekLinkedQueue(lq1);
	printf("peek item : %c \n", data);

	printf("����D>>");
	enLinkedQueue(lq1, 'D');
	printLQ(lq1);

	printf("����E>>");
	enLinkedQueue(lq1, 'E');
	printLQ(lq1);


	free(lq1); // ť ����ü �޸� ����


	return 0;
}