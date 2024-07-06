#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "0120queue01.h"
#define QUEUE_SIZE2 4



QueueType* createCircleQueue() {
	QueueType* q = (QueueType*)malloc(sizeof(QueueType));
	q->front = 0;
	q->rear = 0;
	return q;

}



int isFullCircleQueue(QueueType* q) {
	return (q->rear + 1) % QUEUE_SIZE2  == q->front;
}



void enCircleQueue(QueueType* q, element item) {

	if (isFullCircleQueue(q)) {
		printf("�� ��");
		exit(1);
	}
	q->rear = (q->rear + 1)% QUEUE_SIZE2;
	q->queue[q->rear] = item;
}

element deCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		exit(1);
	}

	q->front = (q->front+1) % QUEUE_SIZE2;
	element item = q->queue[q->front];
	q->queue[q->front] = 0;
	return item;
}


void delCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		return;
	}
	q->front = (q->front + 1) % QUEUE_SIZE2;
	q->queue[q->front] = 0;

}




element peekCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" ť�� �����");
		exit(1);
	}
	int temp =( q->front + 1) % QUEUE_SIZE2;
	return q->queue[temp];



}



void printCircleQ(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf("ť�� �����\n");
		return;
	}

	printf("Queue : [ ");
	int i = q->front;
	while ((i = (i + 1) % QUEUE_SIZE2) != q->rear) { 
		printf("%c", q->queue[i]);
		if ((i + 1) % QUEUE_SIZE2 != (q->rear + 1) % QUEUE_SIZE2) {
			printf(", ");
		}
	}
	// rear�� ��ҵ� ���
	printf("%c ]\n", q->queue[q->rear]);
}

int main0130() {
	QueueType* q = createCircleQueue();
	
	printf("����A >>");
	enCircleQueue(q, 'A');
	printCircleQ(q);
	
	printf("����B >>");
	enCircleQueue(q, 'B');
	printCircleQ(q);

	printf("����C >>");
	enCircleQueue(q, 'C');
	printCircleQ(q);

	/*
	printf("����D >>");
	enCircleQueue(q, 'D');
	printCircleQ(q);
	*/
	
	printf("���� >>");
	deCircleQueue(q);
	printCircleQ(q);

	printf("����E >>");
	enCircleQueue(q, 'E');
	printCircleQ(q);
	/*
	printf("����F >>");
	enCircleQueue(q, 'F');
	printCircleQ(q);
	*/


	printf("peek item:");
	element item = peekCircleQueue(q);
	printf("%c \n", item);


	printf("���� >>");
	deCircleQueue(q);
	printCircleQ(q);

	printf("���� >>");
	deCircleQueue(q);
	printCircleQ(q);


	free(q);

	return 0;
}