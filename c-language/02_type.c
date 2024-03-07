#include <stdio.h>
#include <float.h>    // 실수 자료형의 양수 최솟값, 최댓값이 정의된 헤더 파일
int main02()
{
    float num1 = 0.1f;               // 단정밀도 부동소수점 변수를 선언하고 값을 할당
    // float는 숫자 뒤에 f를 붙임

    double num2 = 3867.215820;       // 배정밀도 부동소수점 변수를 선언하고 값을 할당
    // double은 숫자 뒤에 아무것도 붙이지 않음

    long double num3 = 9.327513l;    // 배정밀도 부동소수점 변수를 선언하고 값을 할당
    // long double은 숫자 뒤에 l을 붙임

// float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513


    float num4 = 3.e5f;             // 지수 표기법으로 300000을 표기
    // float는 숫자 뒤에 f를 붙임

    double num5 = -1.3827e-2;       // 지수 표기법으로 -0.013827을 표기
    // double은 숫자 뒤에 아무것도 붙이지 않음

    long double num6 = 5.21e+9l;    // 지수 표기법으로 5210000000을 표기
    // long double은 숫자 뒤에 l을 붙임

// float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num4, num5, num6); // 300000.000000 -0.013827 5210000000.000000

    // 지수 표기법으로 출력할 때는 float와 double은 %e로 출력, long double은 %Le로 출력
    printf("%e %e %Le\n", num4, num5, num6); // 3.000000e+05 -1.382700e-02 5.210000e+09


    float num11 = FLT_MIN;           // float의 양수 최솟값
    float num12 = FLT_MAX;           // float의 양수 최댓값
    double num13 = DBL_MIN;          // double의 양수 최솟값
    double num14 = DBL_MAX;          // double의 양수 최댓값
    long double num15 = LDBL_MIN;    // long double의 양수 최솟값
    long double num16 = LDBL_MAX;    // long double의 양수 최댓값

    printf("%.40f %.2f\n", num11, num12);    // 0.0000000000000000000000000000000000000118
    // 340282346638528859811704183484516925440.00

    printf("%e %e\n", num13, num14);         // 2.225074e-308 1.797693e+308
    printf("%Le %Le\n", num15, num16);       // 2.225074e-308 1.797693e+308

    char c1 = 'a';    // 문자 변수를 선언하고 문자 a를 저장
    char c2 = 'b';    // 문자 변수를 선언하고 문자 b를 저장

    // char를 %c로 출력하면 문자가 출력되고, %d로 출력하면 정숫값이 출력됨
    printf("%c, %d\n", c1, c1);    // a, 97: a의 ASCII 코드값은 97
    printf("%c, %d\n", c2, c2);    // b, 98: b의 ASCII 코드값은 98

    char c3 = 97;    // a의 ASCII 코드값 97 저장
    char c4 = 98;    // b의 ASCII 코드값 98 저장

    // char를 %c로 출력하면 문자가 출력되고, %d로 출력하면 정숫값이 출력됨
    printf("%c, %d\n", c3, c3); // a, 97
    printf("%c, %d\n", c4, c4); // b, 98

    char c5 = 0x61;    // a의 ASCII 코드값 0x61 할당
    char c6 = 0x62;    // b의 ASCII 코드값 0x62 할당

    // char를 %c로 출력하면 문자가 출력되고, %d로 출력하면 정수 값이 출력됨
    // %x로 출력하면 16진수로 출력됨
    printf("%c, %d, 0x%x\n", c5, c5, c5);    // a, 97, 0x61
    printf("%c, %d, 0x%x\n", c6, c6, c6);    // b, 98, 0x62

    char c7 = '0';    // 문자 0을 저장
    char c8 = 0;      // 숫자 0을 저장

    printf("%c %d\n", c7, c7);    // 0 48: 문자 상태로 0이 출력됨
    // 문자 0의 ASCII 코드 48이 출력됨

    printf("%c %d\n", c8, c8);    // 0: ASCII 코드 0은 널문자이므로 아무것도 출력되지 않음
    // 정수 0이 출력됨

    printf("%c %d\n", 'a' + 1, 'a' + 1);    // b 98: a는 ASCII 코드값 97이고, 
    // 97에 1을 더하여 98이 되었으므로 b가 출력됨

    printf("%c %d\n", 97 + 1, 97 + 1);      // b 98: ASCII 코드값 97에 1을 더하여 98이 되었으므로 
    // b가 출력됨

    char c9 = 'a';
    printf("%c %d\n", c9 + 1, c9 + 1);    // b 98

    char c11 = 'a';           // 문자 a 할당
    char c12 = 'b';           // 문자 b 할당 
    char lineFeed = '\n';    // 제어 문자 \n 할당
    printf("%c%c%c%c", c11, lineFeed, c12, lineFeed);    // 제어 문자도 %c로 출력할 수 있음
    
    printf("%d 0x%x\n", lineFeed, lineFeed);    // 10 0xa: 제어 문자의 ASCII 코드 출력


    //2와 5가 각줄에 출력되게만드세요
    char c21 = 2;
    char c22 = 5;
    char c23 = '2';
    printf("%c\n", c21 );
    printf("%c\n", c22 );
    printf("%c\n", c23);
    printf("%c\n", c21+'0');
    printf("%c\n", c21+0);
    printf("%d\n", c21 + 0);
    printf("%d\n", c21 + '0');

    printf("%c\n", c21 + '0');//정답
    printf("%c\n", c22 + '0');//정답

//A가 출력되게 만드시오
    char c31 = 'a';

    printf("%c\n", c31-'a'+'A');

    return 0;
}