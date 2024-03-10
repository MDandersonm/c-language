#include <stdio.h>
#pragma warning(disable:4996)

int add(int a, int b);//함수의 원형선언

//컴파일러가 번역을할떄는 메인함수부터 번역을해나가게되는데 
//add함수의 원형이 사전에 있어야함.
//즉 add가 main함수 뒤에 있는경우 함수의 원형선언이 필요하다
void main05() {
	int k = add(5, 4);
	printf("값은 %d입니다\n", k);

}

add(int a, int b) {//반환타입을 생략하면 int로 된다.
	return a + b;

}