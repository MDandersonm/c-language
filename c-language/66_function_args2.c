#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>


/*
char*: char �����ʹ� ���ڿ��� ���� �ּҸ� ����ų �� �ֽ��ϴ�. ��, char*�� ���ڿ��� ����Ű�� �����ͷ� ���Ǹ�, �� ������ ���ڿ��� ���ڷ� �����ϰų� ��ȯ ������ ����� �� char* Ÿ���� ���� ���˴ϴ�.
*/
int getSum(const char* format, ...) {
    int total = 0;
    va_list args;

    va_start(args, format);
    while (*format) {//������ *format�� format�� ���� ����Ű�� ���ڸ� �ǹ��մϴ�.
        switch (*format) {
        case 'i': // ���� ó��
            total += va_arg(args, int);
            break;
        case 's': // ���ڿ� ó�� (���ڿ��� �����ϰ� �Ѿ�ϴ�.)
            va_arg(args, char*);
            break;
        case 'd': // double ó�� (�Ҽ����� ������ ���� �κи� ����մϴ�.)
            va_arg(args, double);
            break;
        }
        format++;
    }
    va_end(args);

    return total;
}

int main662()
{
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    printf("%d\n", getSum("isi", num1, "C", 10));
    printf("%d\n", getSum("sdsi", "Hello, world!", 5.3, "A", num2));
    printf("%d\n", getSum("iiss", 25, 38, "k", "R"));
    printf("%d\n", getSum("sidii", "Hello, C", num3, 2.234567, 878, 1291));

    return 0;
}