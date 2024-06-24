#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>

//typedef int element; // ���⿡ Ÿ���� ���� ����//char�� �ᵵ int�� ȣȯ�̵ǳ�
typedef int element; // ���⿡ Ÿ���� ���� ����


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