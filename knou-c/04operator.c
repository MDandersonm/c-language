#include <stdio.h>
#pragma warning(disable:4996)


void main04() {
	int i = 5;
	printf("나머지는 %d 입니다\n", i % 2);
	printf("몫은 %d 입니다\n", i / 2);

	int x = 5, a, b;
	a = ++x* x--;
	b = x * 10;
	printf("a=%d , b=%d, x=%d \n", a,b,x);
}