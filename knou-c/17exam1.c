#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fcn1();
int main171() {
	char s[50];
	gets(s);
	printf("%s",&s);
	

	return 0;
}


int x;
int main172() {
	printf("x=%d\n ", x);
	fcn1();
	printf("x=%d\n ", x);

	return 0;
}
void fcn1() {
	x++;
}

int main() {
	int* p, * q;
	int a[] = { 10,20,30,40,50,60,70,80,90,100 };
	p = &a[4];
	q = p + 3;
	printf("%d %d\n",*p ,*q );
	printf("*(p+3)=%d\n", *(p+3));
	printf("p-q=%d\n",p-q);

	return 0;
}