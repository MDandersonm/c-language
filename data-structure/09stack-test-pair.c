#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include "090linked-stack.h"
extern stackNode* topNode;


int testPair(char* exp) {
	topNode = NULL;
	int i = 0;
	while (exp[i] != '\0') {
		switch (exp[i]) {
		case '[':
		case '{':
		case '(':
			push1(exp[i]);
			break;
		case ']':
			if ('[' != pop1()) {
				return 0;
			}
			break;
		case '}':
			if ('{' != pop1()) {
		
				return 0;
			}
			break;
		case ')':
			if ('(' != pop1() ) {
				return 0;
			}
			break;
		default:
			;
		}
		i++;
	};

	if (topNode == NULL) {
		printf("\n����Գ�? ");
		return 1;
	}
	else {
		return 0;
	}
}

int main090() {


	//��ȣ ¦�´��� Ȯ��
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);
	if (testPair(express) == 1)
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�");
	else
		printf("\n\n������ ��ȣ�� Ʋ�Ƚ��ϴ�");
	void clearStack();

	return 0;
}


