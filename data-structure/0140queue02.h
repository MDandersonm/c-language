#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 100
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>

typedef char element; // 여기에 타입을 직접 선언

typedef struct QNode {
	element data;
	struct QNode* link;

} QNode;

typedef struct {
	QNode* front;
	QNode* rear;
} LQueueType;



LQueueType* createLinkedQueue();
int isLinkedQueueEmpty(LQueueType* lq);
void enLinkedQueue(LQueueType* lq, element item);
element deLinkedQueue(LQueueType* lq);
element peekLinkedQueue(LQueueType* lq);
void printLQ(LQueueType* lq);
void printLQint(LQueueType* lq);
void freeQueue1(LQueueType* lq);
#endif

