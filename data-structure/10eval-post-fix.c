#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#include <ctype.h> 
#include "090linked-stack.h"
extern stackNode* topNode;

int evalPostfix(char* exp) {
	int i=0;
	while (exp[i] !='\0') {
		if (isdigit(exp[i])) {
			// 숫자 문자를 정수로 변환하여 푸시
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
					 // 0으로 나누는 것을 방지
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
	//괄호 짝맞는지 확인
	char* express = "35*62/-";
	printf("후위 표기식: %s", express);
	int result = evalPostfix(express);
	printf("\n\n 연산결과 => %d", result);
	void clearStack();

	return 0;
}


