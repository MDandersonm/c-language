#include <stdio.h>

int main() {
	// 정수형 변수 선언
	int a = 10;

	// 포인터 변수 선언
	int* p;

	// 포인터 변수에 정수형 변수의 주소 할당
	p = &a;

	// 포인터 변수를 통해 정수형 변수의 값 출력
	printf("p의 값: %d\n", *p);

	// 포인터 변수를 통해 정수형 변수의 값 변경
	*p = 20;

	// 정수형 변수의 값 출력
	printf("a의 값: %d\n", a);

	//int p = 11; 불가능
	//printf("정수형 변수 p의 값: %d\n", p);
	printf(" p의 값: %d\n", p);

	return 0;
}