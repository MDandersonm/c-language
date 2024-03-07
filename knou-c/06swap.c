#include <stdio.h>
#pragma warning(disable:4996)

//값에 의한 자료전달
void swap(int a, int b);

//참조에 의한 자료전달
void swap1(int* x, int* y);
void main06() {

	int a = 5;
	int b = 4;
	swap(a, b);
	printf("a는 %d b는 %d \n", a, b);  

	//a,b가 교환되지않았다 swap(5,4)할떄 5,4 를 메
	//함수호출시 a,b 값이 x,y로 복제됨.

	//& 주소연산자 
	//*  주소의 내용을 다루는 내용 연산자
	// *x : x가 주소를 다루고있으면 *x는 그 주소의 내용
	swap1(&a, &b);//a의 주소을 보냄
	printf("주소연산자를 사용했을 경우 a는 %d b는 %d \n", a, b);


}

void swap(int x,int y) {
	int temp = x;
	x = y;
	y = temp;
}


//주소값을 전달받기 위해 포인터변수 int *x를 선언
void swap1(int *x, int *y) {//x는 a의 주소 *x는 a의 주소의 내용값
	int temp = *x;
	*x = *y;
	*y = temp;
}


