#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
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
		printf("꽉 참");
		exit(1);
	}
	q->rear = (q->rear + 1)% QUEUE_SIZE2;
	q->queue[q->rear] = item;
}

element deCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" 큐가 비었음");
		exit(1);
	}

	q->front = (q->front+1) % QUEUE_SIZE2;
	element item = q->queue[q->front];
	q->queue[q->front] = 0;
	return item;
}


void delCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" 큐가 비었음");
		return;
	}
	q->front = (q->front + 1) % QUEUE_SIZE2;
	q->queue[q->front] = 0;

}




element peekCircleQueue(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf(" 큐가 비었음");
		exit(1);
	}
	int temp =( q->front + 1) % QUEUE_SIZE2;
	return q->queue[temp];



}



void printCircleQ(QueueType* q) {
	if (isEmptyQueue(q)) {
		printf("큐가 비었음\n");
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
	// rear의 요소도 출력
	printf("%c ]\n", q->queue[q->rear]);
}

int main0130() {
	QueueType* q = createCircleQueue();
	
	printf("삽입A >>");
	enCircleQueue(q, 'A');
	printCircleQ(q);
	
	printf("삽입B >>");
	enCircleQueue(q, 'B');
	printCircleQ(q);

	printf("삽입C >>");
	enCircleQueue(q, 'C');
	printCircleQ(q);

	/*
	printf("삽입D >>");
	enCircleQueue(q, 'D');
	printCircleQ(q);
	*/
	
	printf("삭제 >>");
	deCircleQueue(q);
	printCircleQ(q);

	printf("삽입E >>");
	enCircleQueue(q, 'E');
	printCircleQ(q);
	/*
	printf("삽입F >>");
	enCircleQueue(q, 'F');
	printCircleQ(q);
	*/


	printf("peek item:");
	element item = peekCircleQueue(q);
	printf("%c \n", item);


	printf("삭제 >>");
	deCircleQueue(q);
	printCircleQ(q);

	printf("삭제 >>");
	deCircleQueue(q);
	printCircleQ(q);


	free(q);

	return 0;
}