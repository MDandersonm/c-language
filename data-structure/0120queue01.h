#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 100
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>



typedef char element;


typedef struct {
	element queue[QUEUE_SIZE];
	int front, rear;

}QueueType;

int isEmptyQueue(QueueType* q);

#endif

