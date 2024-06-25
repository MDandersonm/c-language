#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc���
#include <string.h>
#include <ctype.h> 
#include "090linked-stack.h"
extern stackNode* topNode;

int evalPostfix(char* exp) {
	int i=0;
	while (exp[i] !='\0') {
		if (isdigit(exp[i])) {
			// ���� ���ڸ� ������ ��ȯ�Ͽ� Ǫ��
			push1(exp[i] - '0');
		}
		else {
			int result;
			element item1;
			element item2;
			switch (exp[i]) {
				case('*'):
					 item1 = pop1();
					 item2 = pop1();
					result = item2 * item1;
					push1(result);
					break;
				case('/'):
					 item1 = pop1();
					 item2 = pop1();
					 // 0���� ������ ���� ����
					 if (item1 != 0) {
						 result = item2 / item1;
						 push1(result);
					 }
					break;
				case('-'):
					 item1 = pop1();
					 item2 = pop1();
					result = item2 - item1;
					push1(result);
					break;
				case('+'):
					 item1 = pop1();
					 item2 = pop1();
					result = item2 + item1;
					push1(result);
					break;
			}
		}
		i++;
	}


	return pop1();
}


int main0100() {
	topNode = NULL;
	//��ȣ ¦�´��� Ȯ��
	char* express = "35*62/-";
	printf("���� ǥ���: %s", express);
	int result = evalPostfix(express);
	printf("\n\n ������ => %d", result);
	void clearStack();

	return 0;
}


