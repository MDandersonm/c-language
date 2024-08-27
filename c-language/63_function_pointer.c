#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int getQuotientAndRemainder(int a, int b, int* rem) {
    *rem = a % b;   // 나머지 계산
    return a / b;  // 몫을 반환
}
int main631()
{
    int num1;
    int num2;
    int quotient;     // 몫
    int remainder;    // 나머지

    scanf("%d %d", &num1, &num2);

    quotient = getQuotientAndRemainder(num1, num2, &remainder);

    printf("%d %d\n", quotient, remainder);

    return 0;
}