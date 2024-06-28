#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>

//typedef int element; // 여기에 타입을 직접 선언//char를 써도 int와 호환이되네
typedef int element; // 여기에 타입을 직접 선언


typedef struct stackNode {
	element data;
	struct stackNode* link;

}stackNode;

void push1(element item);
element pop1();
element peek1();
void del1();
void printStack1();
void clearStack();
#endif