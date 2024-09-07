#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int sum(int args, ...)
{
    va_list ap;          // va_list�� �����Ͽ� ���� ���� ��Ͽ� �׼��� �� �� �ְ� �մϴ�.
    int total = 0;

    va_start(ap, args);  // ap�� args ���� ù ��° ���ڷ� �ʱ�ȭ �մϴ�.
    for (int i = 0; i < args; i++) {
        total += va_arg(ap, int);  // va_arg�� ����Ͽ� ���� ���� ����� ���� ���� ���� �����ɴϴ�.
    }
    va_end(ap);          // ���� ���� ����� �����ϰ� ap�� �����մϴ�.

    return total;
}


int main661()
{
    int num1, num2;
    int num3, num4, num5;

    scanf("%d %d", &num1, &num2);
    scanf("%d %d %d", &num3, &num4, &num5);

    printf("%d\n", sum(2, num1, num2));
    printf("%d\n", sum(3, num3, num4, num5));

    return 0;
}