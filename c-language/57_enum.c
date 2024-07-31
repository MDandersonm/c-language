#include <stdio.h>

enum DayOfWeek {    // 열거형 정의
    Sunday = 0,         // 초깃값 할당
    Monday,// 1...씩 자동할당
    Tuesday,//2
    Wednesday,//3
    Thursday,//4
    Friday,//5
    Saturday//6
};

int main57()
{
    enum DayOfWeek week;    // 열거형 변수 선언

    week = Tuesday;    // 열거형 값 할당

    printf("%d\n", week);   // 2: Tuesday의 값 출력

    return 0;
}