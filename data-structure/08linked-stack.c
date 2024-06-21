#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include "090linked-stack.h"

stackNode* topNode;


void push1(element item) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->link = NULL;
	newNode->data = item;
	newNode->link = topNode;
	topNode = newNode;
}


element pop1() {
	if (topNode == NULL) {
		printf("\nSTACK IS EMPTY");
		return 0;
	}
	else {

		stackNode* temp = topNode;
		topNode = topNode->link;
		element result = temp->data;
		free(temp);
		temp = NULL;
		return result;
	}
}


element peek1() {
	if (topNode == NULL) {
		printf("\nSTACK IS EMPTY");
		return 0;
	}
	return topNode->data;
}


void del1() {
	if (topNode == NULL) {
		printf("\nSTACK IS EMPTY");
		return;
	}
	else {
		stackNode* temp = topNode;
		topNode = topNode->link;
		free(temp);
		temp = NULL;
	}

}


void printStack1() {
	printf("\nSTACK = [ ");
	stackNode* temp = topNode;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("]");
}

void clearStack() {
	while (topNode != NULL) {
		pop1(); // 스택의 모든 요소를 제거
	}
}



int main080() {
	topNode = NULL;
	element item;
	printStack1();
	push1(1);
	printStack1();
	
	push1(2);
	printStack1();
	push1(3);
	printStack1();
	
	item = peek1();
	printStack1();
	printf(" peek top => %d", item);
	
	del1();
	printStack1();

	item = pop1();
	printStack1();
	printf(" pop top => %d", item);

	item = pop1();
	printStack1();
	printf(" pop top => %d", item);
	clearStack();

	item = pop1();



	return 0;
}