#include <stdio.h>
#define TEL "1577-2255"
#define width(x)(3.14*x*x)
#define CONDITION 1
void main02() {
	printf("hello world!!\n");
	//숫자대신 단어를 사용
	//enum 태그명 {열거자1,열거자2...};
	enum day1 {SUN,MON,TUE,WED,THU,FRI,SAT} d1;//열거형 변수 d1

	d1 = WED;
	printf("%d\n", d1);//3출력
	//printf("%s\n", TEL);

#if CONDITION //조건부 컴파일
	printf("%f\n", width(5));
#else
	printf("%s\n", TEL);
#endif
};