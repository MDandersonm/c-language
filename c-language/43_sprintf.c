#define _CRT_SECURE_NO_WARNINGS    // sprintf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // sprintf 함수가 선언된 헤더 파일

int main43()
{
    char s1[20];    // 크기가 20인 char형 배열을 선언

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"로 서식을 지정하여 s1에 저장

    printf("%s\n", s1);    // Hello, world!: 문자열 s1 출력




    char s2[10];
    
    //s2 = "nice"; 불가능

    /*
    * char 배열에 직접 문자열을 할당하는 것은 C 언어에서 허용되지 않습니다. 
    대신 strcpy 함수를 사용하여 문자열을 복사할 수 있습니다.
    strcpy 함수를 사용하려면 string.h 헤더 파일을 포함해야 합니다.
    */

    strcpy(s2, "nice");  // 문자열 "nice"를 s2에 복사
    printf("%s\n", s2);


    return 0;
}