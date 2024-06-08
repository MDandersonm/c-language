#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

int main45()
{
    char s1[30] = "The Little Prince";  // 크기가 30인 char형 배열을 선언하고 문자열 할당

    char* ptr = strtok(s1, " ");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환

        /*
        자를 문자열 부분에 NULL을 넣어줍니다. 
        자세히 설명하자면 NULL을 넣었을 때는 직전 strtok 함수에서 처리했던 문자열에서 잘린 문자열만큼 다음 문자로 이동한 뒤 다음 문자열을 자릅니다. 
        만약 ptr = strtok(ptr, " ");처럼 잘린 문자열의 포인터를 다시 넣었을 때는 다음 문자로 이동하지 못하고 처음에 나오는 문자열만 계속 자르게 됩니다

        strtok 함수의 동작 순서입니다. 먼저 처음 호출되는 strtok는 " " (공백 문자)를 찾아서 NULL로 채운 뒤 문자열의 첫 부분인 "The"를 자릅니다.
        */
    }
    //  strtok 함수는 문자열을 새로 생성해서 반환하는 것이 아니라 자르는 부분을 널 문자(NULL)로 채운 뒤 잘린 문자열의 포인터를 반환합니다. 따라서 원본 문자열의 내용을 바꾸므로 사용에 주의해야 합니다.
    printf("%s\n", s1);

    return 0;
}