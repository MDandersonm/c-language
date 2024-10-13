/*
자료형에 대한 크기를 나타내는 프로그램
*/

#include <stdio.h>

void main103() {
    /*
    char 자료형은 주로 문자를 저장하는데 사용된다. ASCII 코드 값에 해당하는 문자를 표현하는 데 사용된다.
    char 타입에 저장되는 값은 컴파일러와 시스템에 따라 부호 있는(signed) 값 또는 부호 없는(unsigned) 값일 수 있다 
    */
    ////char 자료형의 크기를 바이트 단위로 출력한다. %d는 출력할 정수 값을 위한 서식 지정자이며, sizeof(char)는 char의 크기를 바이트 단위로 계산하여 정수로 나타내준다.

    printf("char 자료형 크기 : %d byte\n", sizeof(char));// signed char와 같음
    printf("signed char 자료형 크기 : %d byte\n", sizeof(signed char));//signed char: -128에서 127까지의 값을 나타낼 수 있다
    printf("unsigned char 자료형 크기 : %d byte\n", sizeof(unsigned char));//unsigned char: 0에서 255까지의 값을 나타낼 수 있다

    /*
    short 자료형은 정수형의 한 종류
    short 자료형은 short int의 줄임말
    보통 정수형 중에서 비교적 작은 크기의 값을 저장하는 데 사용된다.
    */

    printf("short 자료형 크기 : %d byte\n", sizeof(short)); //short는 2바이트 크기를 가지며, - 32,768에서 32,767까지의 값을 표현할 수 있다
    printf("short int 자료형 크기 : %d byte\n", sizeof(short int));//short과 같다 int가 생략가능
    printf("signed short 자료형 크기 : %d byte\n", sizeof(signed short)); ///short과 같다 int는 생략가능하다.
    printf("signed short int 자료형 크기 : %d byte\n", sizeof(signed short int)); ///short과 같다 int와 signed는 생략이 가능하다
    printf("unsigned short 자료형 크기 : %d byte\n", sizeof(unsigned short));//0 ~65,535까지의 값을 표현할 수 있는 부호 없는 정수
    printf("unsigned short int 자료형 크기 : %d byte\n", sizeof(unsigned short int)); //int는 생략 가능하기에 unsigned short과 같음


    /*
    int 자료형은 가장 기본적인 정수형
    32bit에서 int는 4바이트를 차지하며, -2,147,483,648부터 2,147,483,647까지의 범위를 표현가능
    */
    printf("int 자료형 크기 : %d byte\n", sizeof(int)); //4바이트 signed int와 같다. signed가 생략된 형태 
    printf("signed int 자료형 크기 : %d byte\n", sizeof(signed int));// 4바이트 , 32bit에서 -2,147,483,648부터 2,147,483,647까지의 범위를 표현가능
    printf("unsigned 자료형 크기 : %d byte\n", sizeof(unsigned));//4바이트 unsigned int와 같다. int가 생략된 형태이다
    printf("unsigned int 자료형 크기 : %d byte\n", sizeof(unsigned int));//4바이트 32bit시스템에서는 0~4,294,967,295의 값을 표현 

    /*
    *long 자료형은 int 자료형보다 같거나 더 큰 범위의 정수 값을 저장한다
    *
    */

    printf("long 자료형 크기 : %d byte\n", sizeof(long));//4byte signed long int의 줄임말로 signed와 int는 생략가능하다.
    printf("long int 자료형 크기 : %d byte\n", sizeof(long int));//4byte signed long int의 줄임말로 signed는 생략가능하다.
    printf("signed long 자료형 크기 : %d byte\n", sizeof(signed long));//4byte signed long int의 줄임말로  int는 생략가능하다.
    printf("signed long int 자료형 크기 : %d byte\n", sizeof(signed long int));//4byte  16bit,32bit 모두 -2,147,483,648부터 2,147,483,647까지의 범위를 표현
    printf("unsigned long 자료형 크기 : %d byte\n", sizeof(unsigned long));//4byte unsigned long int의 줄임말로 int는 생략가능하다.
    printf("unsigned long int 자료형 크기 : %d byte\n", sizeof(unsigned long int));//4byte   16it에서는 0~65,535 32bit에서는 0 ~ 42,959,667,295까지의 범위를 표현

    /*
    long long 자료형은  최소 64비트의 크기를 가지며, 이를 통해 매우 큰 범위의 정수 값을 저장할 수 있다.
    */

    printf("long long 자료형 크기 : %d byte\n", sizeof(long long));// 8byte . signed long long int의 축약형. signed와 int는 생략가능
    printf("long long int 자료형 크기 : %d byte\n", sizeof(long long int));// 8byte.  signed long long int의 축약형. signed는 생략가능
    printf("signed long long 자료형 크기 : %d byte\n", sizeof(signed long long));// 8byte  signed long long int의 축약형. int는 생략가능
    printf("signed long long int 자료형 크기 : %d byte\n", sizeof(signed long long int));// 8byte.  -9,223,372,036,854,775,808부터 9,223,372,036,854,775,807까지의 값을 저장
    printf("unsigned long long 자료형 크기 : %d byte\n", sizeof(unsigned long long));// 8byte    unsigned long long int의 축약형. int는 생략가능
    printf("unsigned long long int 자료형 크기 : %d byte\n", sizeof(unsigned long long int));// 8byte. , 0부터 18,446,744,073,709,551,615까지 값을 저장

    /*
    실수형
    기본형은 double형이다.
    */

    printf("float 자료형 크기 : %d byte\n", sizeof(float));//4byte  3.4E-38 ~ 3.4E+38 범위까지 표현
    printf("double 자료형 크기 : %d byte\n", sizeof(double));//8byte   1.7E-308 ~ 1.7E+308 범위 표현
    printf("long double 자료형 크기 : %d byte\n", sizeof(long double)); //8byte 1.7E-308 ~ 1.7E+308 범위 표현
}
