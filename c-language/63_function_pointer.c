#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int getQuotientAndRemainder(int a, int b, int* rem) {
    *rem = a % b;   // ������ ���
    return a / b;  // ���� ��ȯ
}
int main631()
{
    int num1;
    int num2;
    int quotient;     // ��
    int remainder;    // ������

    scanf("%d %d", &num1, &num2);

    quotient = getQuotientAndRemainder(num1, num2, &remainder);

    printf("%d %d\n", quotient, remainder);

    return 0;
}