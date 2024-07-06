#include <stdio.h>
#include <string.h>    // memset 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
struct Point2D {
    int x;
    int y;
};

int main52()
{
    struct Point2D p1;

    memset(&p1, 0, sizeof(struct Point2D));    // p1을 구조체 크기만큼 0으로 설정 // memset(구조체포인터, 설정할값, sizeof(struct 구조체));

    printf("%d %d\n", p1.x, p1.y);    // 0 0: memset을 사용하여 0으로 설정했으므로
    printf("%d\n", sizeof(struct Point2D));
    // x, y 모두 0


    struct Point2D* p2 = malloc(sizeof(struct Point2D));    // 구조체 크기만큼 메모리 할당

    memset(p2, 0, sizeof(struct Point2D));    // p1을 구조체 크기만큼 0으로 설정

    printf("%d %d\n", p2->x, p2->y);    // 0 0: memset을 사용하여 0으로 설정했으므로
    // x, y 모두 0

    free(p2);    // 동적 메모리 해제

    return 0;
}