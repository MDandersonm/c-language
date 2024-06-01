#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>

int main390()
{
    char* s31 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

    printf("문자열을 입력하세요: ");
    scanf("%s", s31);    // 표준 입력을 받아서 배열 형태의 문자열에 저장
    printf("%s\n", s31);
    free(s31);    // 동적 메모리 해제

    //메모리 해제 후 접근: free(s31); 뒤에 printf("%s\n", s31);로 메모리에 접근하고 있습니다. 
    // 메모리를 해제한 후 그 메모리 영역에 접근하면 정의되지 않은 동작이 발생할 수 있습니다.
    //  따라서 메모리를 해제한 후에는 그 메모리 영역에 접근하면 안 됩니다.
    //printf("%s\n", s31);//메모리 해제 후 쓰면 안됨

    return 0;
}