#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n);
void main020() {
	int a;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &a);
	int p= factorial(a);
	printf("%d\n", p);
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1) ;
}