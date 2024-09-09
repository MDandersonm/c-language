#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int sum(int args, ...)
{
    va_list ap;          // va_list를 선언하여 가변 인자 목록에 액세스 할 수 있게 합니다.
    int total = 0;

    va_start(ap, args);  // ap를 args 뒤의 첫 번째 인자로 초기화 합니다.
    for (int i = 0; i < args; i++) {
        total += va_arg(ap, int);  // va_arg를 사용하여 가변 인자 목록의 다음 인자 값을 가져옵니다.
    }
    va_end(ap);          // 가변 인자 목록을 종료하고 ap를 정리합니다.

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