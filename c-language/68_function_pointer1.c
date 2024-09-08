#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int* a, int* b)
{
    return *a + *b;
}

int sub(int* a, int* b)
{
    return *a - *b;
}

int mul(int* a, int* b)
{
    return *a * *b;
}

int div(int* a, int* b)
{
    return *a / *b;
}

int main681()
{
    char funcName[10];
    int num1, num2;

    scanf("%s %d %d", funcName, &num1, &num2);

    /*
    함수 포인터
함수 포인터는 이름에서 알 수 있듯이 함수를 가리키는 포인터입니다. 이를 사용하여 다른 함수를 호출하거나 함수의 주소를 저장할 수 있습니다.
    int (*fp)(int*, int*)에서 fp는 함수 포인터의 이름입니다.
    */
    int (*fp)(int*, int*) = NULL;
    //(*fp)는 fp가 함수를 가리키는 것임을 명시하기 위한 괄호와 별표 조합입니다. 별표는 "포인터"를 의미하고, 괄호는 우선순위를 명시합니다. 
    //int (*fp)(int*, int*) = NULL;은 반환 타입이 int이며 두 개의 int* 타입 인자를 받는 함수를 가리키는 포인터 fp를 선언하고, 이 포인터를 NULL로 초기화하는 코드입니다.


    /*stcmp
    s1과 s2가 같으면 0을 반환합니다.
s1이 s2보다 사전 순으로 앞에 오면 음수를 반환합니다.
s1이 s2보다 사전 순으로 뒤에 오면 양수를 반환합니다.
    
    */
    if (strcmp(funcName, "add") == 0)
    {
        fp = add;
    }
    else if (strcmp(funcName, "sub") == 0)
    {
        fp = sub;
    }
    else if (strcmp(funcName, "mul") == 0)
    {
        fp = mul;
    }
    else if (strcmp(funcName, "div") == 0)
    {
        fp = div;
    }

    if (fp == NULL)
    {
        printf("Invalid function name.\n");
        return 1; // 종료
    }

    printf("%d\n", fp(&num1, &num2));


    return 0;
}