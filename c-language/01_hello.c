#include <stdio.h>//#include는 헤더 파일을 포함하는 문법이며 printf 함수를 사용하려면 stdio.h 헤더 파일이 필요합니다!!
#include <limits.h>    // 자료형의 최댓값과 최솟값이 정의된 헤더 파일
#include <stdint.h>    // 크기별로 정수 자료형이 정의된 헤더 파일


<<<<<<< Updated upstream
int main01()
=======
int main()
>>>>>>> Stashed changes
{
    printf("Hello, world!\n");
    printf("%s\n", "안녕!");
    printf("Hello, %s\n", "world!");
    printf("Hello, world!\n");
    printf("Hello, world!\n");

    int num1;    // 정수형 변수 선언
    int num2;
    int num3;
    int num4, num5;//이렇게 해도된다.

    num1 = 10;   // 변수에 값 할당(저장)
    num2 = 20;
    num3 = 30;
    num4 = 40;
    num5 = 50;


    printf("%d %d %d %d %d\n", num1, num2, num3,num4,num5); // 10 20 30: 변수에 저장된 값을 %d로 출력

    int num6 = 60;               // 변수를 선언하면서 값 할당(초기화)
    int num7 = 70, num8 = 80;    // 변수 여러 개를 선언하면서 값 할당(초기화)
    printf("%d %d %d\n", num6, num7, num8);    // 10 20 30: 변수에 저장된 값을 %d로 출력

    char num10 = -10;           // 1바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    short num11 = 30000;        // 2바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    int num12 = -1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long num13= 1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long long num14 = -1234567890123456789;     // 8바이트 부호 있는 정수형으로 변수를 선언하고 값 할당

// char, short, int는 %d로 출력하고 long은 %ld, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num10, num11, num12, num13, num14);
    // -10 30000 -1234567890 1234567890 -1234567890123456789

    unsigned char num21 = 200;                          // 1바이트 부호 없는 정수형으로     // 변수를 선언하고 값 할당

    unsigned short num22 = 60000;                       // 2바이트 부호 없는 정수형으로     // 변수를 선언하고 값 할당

    unsigned int num23 = 4123456789;                    // 4바이트 부호 없는 정수형으로     // 변수를 선언하고 값 할당

    unsigned long num24 = 4123456789;                   // 4바이트 부호 없는 정수형으로     // 변수를 선언하고 값 할당

    unsigned long long num25 = 12345678901234567890;    // 8바이트 부호 없는 정수형으로    // 변수를 선언하고 값 할당

// unsigned char, unsigned short, unsigned int는 %u로 출력하고 
// unsigned long은 %lu, unsigned long long은 %llu로 출력
    printf("%u %u %u %lu %llu\n", num21, num22, num23, num24, num25);
    // 200 60000 4123456789 4123456789 12345678901234567890


    char num31 = 128;             // char에 저장할 수 있는 최댓값 127보다 큰 수를 할당
    // 오버플로우 발생

    unsigned char num32 = 256;    // unsigned char에 저장할 수 있는 최댓값 255보다 큰 수를 할당
    // 오버플로우 발생

    printf("%d %u\n", num31, num32);    // -128 0: 저장할 수 있는 범위를 넘어서므로 
    // 최솟값부터 다시 시작

    /*
    num1에 128을 넣었는데 실제 출력에서는 -128이 나와버렸습니다. char에 저장할 수 있는 최댓값은 127이라서 오버플로우(overflow)가 발생했기 때문입니다.
    즉, 128이 127보다 1이 많아서 저장할 수 있는 범위를 넘어섰고 다시 최솟값부터 시작하게 되므로 -128이 나옵니다.
    마찬가지로 num2도 unsigned char에 저장할 수 있는 최댓값은 255인데 256을 넣으면 범위를 넘어서므로 최솟값인 0부터 다시 시작하게 됩니다.

char 이외에도 short, int, long, long long 등도 저장할 수 있는 범위를 넘어서면 최솟값부터 다시 시작하게 됩니다. 반대로 최솟값보다 작아지면 언더플로우(underflow)가 발생하여 최댓값부터 다시 시작하게 됩니다
(값을 계속 뺀다면 최댓값에서 값이 계속 작아짐).
    
    */


    int num41 = 0;
    int size;

    size = sizeof num41;    // 변수 num41의 자료형 크기를 구함

    printf("num41의 크기: %d\n", size);

    int size42;

    size42 = sizeof(int);

    int num43 = 0;
    int size43;

    size43 = sizeof(num43);
    printf("size42: %d size43: %d \n", size42, size43);

    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),        // 1: sizeof로 char 자료형의 크기를 구함
        sizeof(short),       // 2: sizeof로 short 자료형의 크기를 구함
        sizeof(int),         // 4: sizeof로 int 자료형의 크기를 구함
        sizeof(long),        // 4: sizeof로 long 자료형의 크기를 구함
        sizeof(long long)    // 8: sizeof로 long long 자료형의 크기를 구함
    );

    //#include <limits.h>    // 자료형의 최댓값과 최솟값이 정의된 헤더 파일을 적어주면 상수입력가능.
    char num51 = CHAR_MIN;          // char의 최솟값
    short num52 = SHRT_MIN;         // short의 최솟값
    int num53 = INT_MIN;            // int의 최솟값
    long num54 = LONG_MIN;          // long의 최솟값
    long long num55 = LLONG_MIN;    // long long의 최솟값

    // char, short, int는 %d로 출력하고 long은 %ld로 출력, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num51, num52, num53, num54, num55);
    // -128 -32768 -2147483648 -2147483648 -9223372036854775808



    char num61 = CHAR_MAX + 1;          // char의 최댓값보다 큰 수를 할당. 오버플로우 발생
    short num62 = SHRT_MAX + 1;         // short의 최댓값보다 큰 수를 할당. 오버플로우 발생
    int num63 = INT_MAX + 1;            // int의 최댓값보다 큰 수를 할당. 오버플로우 발생
    long long num64 = LLONG_MAX + 1;    // long long의 최댓값보다 큰 수를 할당. 오버플로우 발생

    // char, short, int는 %d로 출력하고 long long은 %lld로 출력
    // 부호 있는 정수에서 저장할 수 있는 범위를 넘어서면 최솟값부터 다시 시작
    printf("%d %d %d %lld\n", num61, num62, num63, num64);
    // -128 -32768 -2147483648 -9223372036854775808


    unsigned char num65 = UCHAR_MAX + 1;          // unsigned char의 최댓값보다 큰 수를 할당
    // 오버플로우 발생

    unsigned short num66 = USHRT_MAX + 1;         // unsigned short의 최댓값보다 큰 수를 할당
    // 오버플로우 발생

    unsigned int num67 = UINT_MAX + 1;            // unsigned int의 최댓값보다 큰 수를 할당
    // 오버플로우 발생

    unsigned long long num68 = ULLONG_MAX + 1;    // unsigned long long의 최댓값보다 큰 수를 할당
    // 오버플로우 발생

// unsigned char, unsigned short, unsigned int는 %u로 출력하고 
// unsigned long long은 %llu로 출력
// 부호 없는 정수에서 저장할 수 있는 범위를 넘어서면 최솟값 0부터 다시 시작
    printf("%u %u %u %llu\n", num65, num66, num67, num68); // 0 0 0 0


    int8_t num71 = -128;                    // 8비트(1바이트) 크기의 부호 있는 정수형 변수 선언
    int16_t num72 = 32767;                  // 16비트(2바이트) 크기의 부호 있는 정수형 변수 선언 
    int32_t num73 = 2147483647;             // 32비트(4바이트) 크기의 부호 있는 정수형 변수 선언
    int64_t num74 = 9223372036854775807;    // 64비트(8바이트) 크기의 부호 있는 정수형 변수 선언

    // int8_t, int16_t, int32_t는 %d로 출력하고 int64_t는 %lld로 출력
    printf("%d %d %d %lld\n", num71, num72, num73, num74); // -128 32767 2147483647 9223372036854775807

    uint8_t num75 = 255;                      // 8비트(1바이트) 크기의 부호 없는 정수형 변수 선언
    uint16_t num76 = 65535;                   // 16비트(2바이트) 크기의 부호 없는 정수형 변수 선언
    uint32_t num77 = 4294967295;              // 32비트(4바이트) 크기의 부호 없는 정수형 변수 선언
    uint64_t num78 = 18446744073709551615;    // 64비트(8바이트) 크기의 부호 없는 정수형 변수 선언

    // uint8_t, uint16_t, uint32_t는 %u로 출력하고 uint64_t는 %llu로 출력
    printf("%u %u %u %llu\n", num75, num76, num77, num78); // 255 65535 4294967295 18446744073709551615







    return 0;
}