#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>


/*
char*: char 포인터는 문자열의 시작 주소를 가리킬 수 있습니다. 즉, char*는 문자열을 가리키는 포인터로 사용되며, 이 때문에 문자열을 인자로 전달하거나 반환 값으로 사용할 때 char* 타입이 자주 사용됩니다.
*/
int getSum(const char* format, ...) {
    int total = 0;
    va_list args;

    va_start(args, format);
    while (*format) {//역참조 *format는 format이 현재 가리키는 문자를 의미합니다.
        switch (*format) {
        case 'i': // 정수 처리
            total += va_arg(args, int);
            break;
        case 's': // 문자열 처리 (문자열은 무시하고 넘어갑니다.)
            va_arg(args, char*);
            break;
        case 'd': // double 처리 (소수점은 버리고 정수 부분만 사용합니다.)
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