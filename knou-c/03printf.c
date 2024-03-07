#include <stdio.h>
#pragma warning(disable:4996)

void main03() {
	int jsu1,jsu2;
	float ssu1;
	scanf("%d %d", &jsu1, &jsu2);
	printf("입력한 숫자는 %d %d", jsu1,jsu2);

}


void main031() {
	/// 한 문자 입력하기
	char a = getchar();
	printf("a= %c \n", a);


	//한문자를 출력하기
	char var1 = 'k';
	putchar(var1);
	putchar(var1+1);
	putchar('t');
}

void main032 () {
	//문자열 입력 
	char s[50];
	gets(s);
	printf("%s 를 입력하셨습니다\n", s);

	//scanf로 문자열을 받는경우 , 문자열에 공백이있으면 짤린다
	scanf("%s", s);
	printf("scanf로 입력한 문자열 : %s\n", s);

	//문자열 출력
	char s1[50] = "SEOUL";
	char s2[50] = "MANAGER";
	puts(s1);
	puts(s2);//printf 와 차이점은 puts()는  \n가 자동적으로 적용된다
	printf("%s", s1);
	printf("%s", s2);

}