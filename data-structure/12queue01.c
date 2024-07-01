#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "0120queue01.h"

//����ť�� �����ϴ� ����
QueueType* createQueue() {
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	q->front = -1;
	q->rear = -1;
	return q;

}


int isEmptyQueue(QueueType* q) {
	if (q->front == q->rear) {
		return 1; // ��������� true (1)
	}
	return 0;
}

int isFullQueue(QueueType* q) {
	return q->rear == QUEUE_SIZE - 1;
}

void delQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		return;
	}
	q->front++;
	q->queue[q->front] = 0;

}


void enQueue(QueueType* q ,element item) {
	
	if (isFullQueue(q)) {
		printf("�� ��");
		exit(1);
	}

	q->rear++;
	q->queue[q->rear] = item;
}
element deQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		exit(1);
	}

	q->front++;
	element item = q->queue[q->front];
	q->queue[q->front] = 0;
	return item;
}

element peekQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		exit(1);
	}
	int temp = q->front + 1;
	return q->queue[temp];



}

void printQ(QueueType* q) {

	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		exit(1);
	}

	printf("Queue : [ ");
	for (int i = q->front + 1; i <= q->rear; i++) {
		
		if (i == q->rear) {
			printf("%c ]\n", q->queue[i]);
		}
		else {
			printf("%c ,", q->queue[i]);

		}
	};
}

int main0120() {
	QueueType * q =createQueue();

	printf("����A >>");
	enQueue(q,'A');
	printQ(q);
	
	printf("����B >>");
	enQueue(q,'B');
	printQ(q);

	printf("���� >>");
	deQueue(q);
	printQ(q);

	printf("����C >>");
	enQueue(q,'C');
	printQ(q);

	printf("peek item:");
	element item = peekQueue(q);
	printf("%c \n", item);


	printf("���� >>");
	deQueue(q);
	printQ(q);

	printf("���� >>");
	deQueue(q);
	printQ(q);

	free(q);



	return 0;
}