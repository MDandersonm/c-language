#include <stdio.h>
#include <string.h>    // strlen 함수가 선언된 헤더 파일

int main41()
{
    char* s1 = "Hello";       // 포인터에 문자열 Hello의 주소 저장
    char s2[10] = "Hello";    // 크기가 10인 char형 배열을 선언하고 문자열 할당

    printf("%d\n", strlen(s1));    // 5: strlen 함수로 문자열의 길이를 구함
    printf("%d\n", strlen(s2));    // 5: strlen 함수로 문자열의 길이를 구함

    // 순수하게 문자열의 길이만 구하며 NULL 부분은 포함하지 않습니다. 
    // //특히 배열의 크기는 문자열의 길이와 전혀 상관이 없습니다. 배열의 크기가 크던 작던 문자열의 길이만 구합니다.

    return 0;
}