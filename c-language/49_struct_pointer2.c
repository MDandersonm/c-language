#include <stdio.h>
#include <stdlib.h>

struct Data {
    char c1;
    int* numPtr;    // 포인터
};

int main492()
{
    int num1 = 10;
    struct Data d1;    // 구조체 변수
    struct Data* d2 = malloc(sizeof(struct Data));    // 구조체 포인터에 메모리 할당

    d1.numPtr = &num1;
    d2->numPtr = &num1;

    printf("%p\n", d1.numPtr); //num1의 주소
    printf("%p\n", d2->numPtr); //num1의 주소  
    printf("%d\n", *d1.numPtr);     // 10: 구조체의 멤버를 역참조
    printf("%d\n", *(d1.numPtr));     // 위와 같음.
     //printf("%d\n", (*d1).numPtr); //에러 d1은 이미 구조체 변수이므로 *로 역참조할 필요가 없습니다 d1은 이미 구조체 변수이기 때문에 d1.numPtr와 같이 직접 멤버에 접근할 수 있습니다.
    printf("--\n");
    printf("%p\n", (*d2).numPtr); //d2를 역참조하면 d2구조체인데 여기서numPtr값은 num1의주소

    printf("%d\n", *d2->numPtr);    // 10: 구조체 포인터의 멤버를 역참조
    printf("%d\n", *(d2->numPtr));//위와같음

    d2->c1 = 'a';
    printf("%c\n", (*d2).c1);      //  a: 구조체 포인터를 역참조하여 c1에 접근
    // d2->c1과 같음
    printf("%d\n", *(*d2).numPtr); // 10: 구조체 포인터를 역참조하여 numPtr에 접근한 뒤 다시 역참조
    // *d2->numPtr과 같음

    free(d2);

    return 0;
}