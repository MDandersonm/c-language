#include <stdio.h>
struct num {
	int x;
	int y;
	int sum;
	int mul;
};

/// 값에 의한 자료전달

struct num calc(struct num); //구조체 변수 선언

void main130() {
	struct num number1;
	number1.x = 10;
	number1.y = 20;
	number1 = calc(number1); // 피호출함수 calc()에 struct num형 구조체를 매개변수로 넘겨줌   calc는 구조체를 리턴하는 함수이다.
	printf("%d %d %d %d\n ", number1.x, number1.y, number1.sum, number1.mul);
	//getchar();
}


struct num calc(struct num number2) {   // 넘겨받은  struct num형 구조체의 멤버끼리 계산한다.
	number2.sum=number2.x+number2.y;
	number2.mul = number2.x * number2.y;
	return number2;//구조체를 리턴
}

////////////////////// 구조체 포인터를 함수의 매개변수로 사용(참조에 의한 자료전달)

struct num calc2(struct num*);

void main131() {
	struct num number3;
	number3.x = 10;
	number3.y = 20;
	calc2(&number3);
	printf("%d %d %d %d\n ", number3.x, number3.y, number3.sum, number3.mul);
	//getchar();
}

struct num calc2(struct num* number2) {   // 넘겨받은  struct num형 구조체의 멤버끼리 계산한다.
	number2->sum = number2->x + number2->y;
	number2->mul = number2->x * number2->y;
}