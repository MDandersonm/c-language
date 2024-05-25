#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main350()
{
    int num1;
    int num2;

    int* numPtr1 = (int*)malloc(sizeof(int));//
    int* numPtr2 = (int*)malloc(sizeof(int));//

     scanf("%d %d", &num1, &num2); 

    *numPtr1 = num1;
    *numPtr2 = num2;

    printf("%d\n", *numPtr1 + *numPtr2);

    /*
    free 함수는 힙에 할당된 메모리만 해제할 수 있습니다. 스택에 할당된 메모리를 free로 해제하려고 시도하면 실행 시 에러가 발생합니다.
    */
    free(numPtr1);
    free(numPtr2);

    return 0;
}