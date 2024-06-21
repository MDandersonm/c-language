#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#define STACK_SIZE 100
typedef int element;
element stack[STACK_SIZE];
int top = -1;//������������ �ε�������

void push(element item) {
	if (top >= STACK_SIZE - 1) {
		printf("\n\n Stack is Full! \n");
		return ;
	}
	stack[top+1] = item;
	top++;
}


element pop() {
	if (top == -1) {

		return 0;
	}
	return stack[top--];

}

void del() {
	if (top == -1) {
		printf("\n stack is empty");
		exit(1);//���� �������� ���α׷��� ���� ���� 
		return;
	}
	top--;
	
}


element peek() {
	if (top == -1) {
		printf("\n stack is empty");
		exit(1);//���� �������� ���α׷��� ���� ���� 
		return 0;
	}

	return stack[top];
}

void printStack() {
	printf("\nSTACK [ ");
	for (int i = 0; i<=top; i++) {
		printf("%d " ,stack[i]);
	}
	printf("]  ");
}



int main070() {

	int item;
	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	item = peek();
	printStack();
	printf(" peek top => %d", item);

	del();
	printStack();


	item = pop();
	printStack();
	printf(" pop top => %d", item);

	item = pop();
	printStack();
	printf(" pop top => %d", item);
	
	item = pop();
	

	return 0;
}