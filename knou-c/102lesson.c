/*
이 프로그램은 두 수를 키보드로 입력 받아 곱의 결과를 출력하는 프로그램이다.
*/

#include <stdio.h>
/*
컴파일러에게 표준 입력-출력 라이브러리(stdio.h)를 프로그램에 포함시키라고 지시한다.
stdio.h 헤더 파일에는 입력과 출력 작업을 수행하는 데 사용되는 함수의 원형이 선언되어 있다. 아래 main함수에서 사용될 printf,scanf 함수가 이 파일에 선언되어 있다.
*/

#pragma warning(disable:4996)
/*특정 컴파일러 경고를 비활성화한다. 4996번 경고를 비활성화하는데, 
보통 보안에 취약한 함수 사용에 대한 경고인데 main함수에서 사용할  scanf 함수를 사용하면 이러한 경고가 뜬다.*/

int a, b, c; //세 개의 전역 변수 a, b, c를 정수형으로 선언함
int product(int x, int y); //두 정수의 곱을 반환하는 product 함수의 프로토타입을 선언. main 함수보다 product함수의 정의가 뒷부분에 있기때문에 미리 선언함

void main102() {//프로그램의 시작점인 메인 함수를 정의합니다. void는 main 함수가 값을 반환하지 않는다는 것을 의미함. 프로그램을 실행하면 이 함수가 실행된다.
	printf("Enter a number between 1 and 100 :");//  1부터 100 사이의 숫자를 입력하라는 메시지를 출력한다.(첫번쨰 수 입력
	scanf("%d", &a); //표준 입력 함수인 scanf를 사용하여  정수를 입력받아 변수 a에 저장

	printf("Enter another number between 1 and 100 : "); //  1부터 100 사이의 숫자를 입력하라는 메시지를 출력한다.(두번째 수 입력
	scanf("%d", &b);// 표준 입력 함수 scanf를 다시 사용하여 또 다른 정수를 입력받아 변수 b에 저장

	c = product(a, b); //product 함수를 호출하여 위에서 입력받아 저장되어 있는 변수 a와 b의 곱을 계산하고, 결과를 변수 c에 저장함
	printf("%d * %d = %d \n" , a, b, c); //계산된 곱의 결과를 형식에 맞춰서 출력한다. %d는 정수를 출력하는 기호이고 %d %d %d 에 각각, a ,b ,c 가 순서대로 값이 들어가 출력됨 

}

int product(int x, int y) {// product 함수를 정의 반환 타입은 int이고, 두 int형 매개변수 x와 y를 받아서 곱을 계산하고, 결과를 int형으로 반환함
	return (x * y);
}