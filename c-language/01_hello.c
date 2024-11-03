#include <stdio.h>//#include�� ��� ������ �����ϴ� �����̸� printf �Լ��� ����Ϸ��� stdio.h ��� ������ �ʿ��մϴ�!!
#include <limits.h>    // �ڷ����� �ִ񰪰� �ּڰ��� ���ǵ� ��� ����
#include <stdint.h>    // ũ�⺰�� ���� �ڷ����� ���ǵ� ��� ����


<<<<<<< Updated upstream
int main01()
=======
int main()
>>>>>>> Stashed changes
{
    printf("Hello, world!\n");
    printf("%s\n", "�ȳ�!");
    printf("Hello, %s\n", "world!");
    printf("Hello, world!\n");
    printf("Hello, world!\n");

    int num1;    // ������ ���� ����
    int num2;
    int num3;
    int num4, num5;//�̷��� �ص��ȴ�.

    num1 = 10;   // ������ �� �Ҵ�(����)
    num2 = 20;
    num3 = 30;
    num4 = 40;
    num5 = 50;


    printf("%d %d %d %d %d\n", num1, num2, num3,num4,num5); // 10 20 30: ������ ����� ���� %d�� ���

    int num6 = 60;               // ������ �����ϸ鼭 �� �Ҵ�(�ʱ�ȭ)
    int num7 = 70, num8 = 80;    // ���� ���� ���� �����ϸ鼭 �� �Ҵ�(�ʱ�ȭ)
    printf("%d %d %d\n", num6, num7, num8);    // 10 20 30: ������ ����� ���� %d�� ���

    char num10 = -10;           // 1����Ʈ ��ȣ �ִ� ���������� ������ �����ϰ� �� �Ҵ�
    short num11 = 30000;        // 2����Ʈ ��ȣ �ִ� ���������� ������ �����ϰ� �� �Ҵ�
    int num12 = -1234567890;    // 4����Ʈ ��ȣ �ִ� ���������� ������ �����ϰ� �� �Ҵ�
    long num13= 1234567890;    // 4����Ʈ ��ȣ �ִ� ���������� ������ �����ϰ� �� �Ҵ�
    long long num14 = -1234567890123456789;     // 8����Ʈ ��ȣ �ִ� ���������� ������ �����ϰ� �� �Ҵ�

// char, short, int�� %d�� ����ϰ� long�� %ld, long long�� %lld�� ���
    printf("%d %d %d %ld %lld\n", num10, num11, num12, num13, num14);
    // -10 30000 -1234567890 1234567890 -1234567890123456789

    unsigned char num21 = 200;                          // 1����Ʈ ��ȣ ���� ����������     // ������ �����ϰ� �� �Ҵ�

    unsigned short num22 = 60000;                       // 2����Ʈ ��ȣ ���� ����������     // ������ �����ϰ� �� �Ҵ�

    unsigned int num23 = 4123456789;                    // 4����Ʈ ��ȣ ���� ����������     // ������ �����ϰ� �� �Ҵ�

    unsigned long num24 = 4123456789;                   // 4����Ʈ ��ȣ ���� ����������     // ������ �����ϰ� �� �Ҵ�

    unsigned long long num25 = 12345678901234567890;    // 8����Ʈ ��ȣ ���� ����������    // ������ �����ϰ� �� �Ҵ�

// unsigned char, unsigned short, unsigned int�� %u�� ����ϰ� 
// unsigned long�� %lu, unsigned long long�� %llu�� ���
    printf("%u %u %u %lu %llu\n", num21, num22, num23, num24, num25);
    // 200 60000 4123456789 4123456789 12345678901234567890


    char num31 = 128;             // char�� ������ �� �ִ� �ִ� 127���� ū ���� �Ҵ�
    // �����÷ο� �߻�

    unsigned char num32 = 256;    // unsigned char�� ������ �� �ִ� �ִ� 255���� ū ���� �Ҵ�
    // �����÷ο� �߻�

    printf("%d %u\n", num31, num32);    // -128 0: ������ �� �ִ� ������ �Ѿ�Ƿ� 
    // �ּڰ����� �ٽ� ����

    /*
    num1�� 128�� �־��µ� ���� ��¿����� -128�� ���͹��Ƚ��ϴ�. char�� ������ �� �ִ� �ִ��� 127�̶� �����÷ο�(overflow)�� �߻��߱� �����Դϴ�.
    ��, 128�� 127���� 1�� ���Ƽ� ������ �� �ִ� ������ �Ѿ�� �ٽ� �ּڰ����� �����ϰ� �ǹǷ� -128�� ���ɴϴ�.
    ���������� num2�� unsigned char�� ������ �� �ִ� �ִ��� 255�ε� 256�� ������ ������ �Ѿ�Ƿ� �ּڰ��� 0���� �ٽ� �����ϰ� �˴ϴ�.

char �̿ܿ��� short, int, long, long long � ������ �� �ִ� ������ �Ѿ�� �ּڰ����� �ٽ� �����ϰ� �˴ϴ�. �ݴ�� �ּڰ����� �۾����� ����÷ο�(underflow)�� �߻��Ͽ� �ִ񰪺��� �ٽ� �����ϰ� �˴ϴ�
(���� ��� ���ٸ� �ִ񰪿��� ���� ��� �۾���).
    
    */


    int num41 = 0;
    int size;

    size = sizeof num41;    // ���� num41�� �ڷ��� ũ�⸦ ����

    printf("num41�� ũ��: %d\n", size);

    int size42;

    size42 = sizeof(int);

    int num43 = 0;
    int size43;

    size43 = sizeof(num43);
    printf("size42: %d size43: %d \n", size42, size43);

    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),        // 1: sizeof�� char �ڷ����� ũ�⸦ ����
        sizeof(short),       // 2: sizeof�� short �ڷ����� ũ�⸦ ����
        sizeof(int),         // 4: sizeof�� int �ڷ����� ũ�⸦ ����
        sizeof(long),        // 4: sizeof�� long �ڷ����� ũ�⸦ ����
        sizeof(long long)    // 8: sizeof�� long long �ڷ����� ũ�⸦ ����
    );

    //#include <limits.h>    // �ڷ����� �ִ񰪰� �ּڰ��� ���ǵ� ��� ������ �����ָ� ����Է°���.
    char num51 = CHAR_MIN;          // char�� �ּڰ�
    short num52 = SHRT_MIN;         // short�� �ּڰ�
    int num53 = INT_MIN;            // int�� �ּڰ�
    long num54 = LONG_MIN;          // long�� �ּڰ�
    long long num55 = LLONG_MIN;    // long long�� �ּڰ�

    // char, short, int�� %d�� ����ϰ� long�� %ld�� ���, long long�� %lld�� ���
    printf("%d %d %d %ld %lld\n", num51, num52, num53, num54, num55);
    // -128 -32768 -2147483648 -2147483648 -9223372036854775808



    char num61 = CHAR_MAX + 1;          // char�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    short num62 = SHRT_MAX + 1;         // short�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    int num63 = INT_MAX + 1;            // int�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�
    long long num64 = LLONG_MAX + 1;    // long long�� �ִ񰪺��� ū ���� �Ҵ�. �����÷ο� �߻�

    // char, short, int�� %d�� ����ϰ� long long�� %lld�� ���
    // ��ȣ �ִ� �������� ������ �� �ִ� ������ �Ѿ�� �ּڰ����� �ٽ� ����
    printf("%d %d %d %lld\n", num61, num62, num63, num64);
    // -128 -32768 -2147483648 -9223372036854775808


    unsigned char num65 = UCHAR_MAX + 1;          // unsigned char�� �ִ񰪺��� ū ���� �Ҵ�
    // �����÷ο� �߻�

    unsigned short num66 = USHRT_MAX + 1;         // unsigned short�� �ִ񰪺��� ū ���� �Ҵ�
    // �����÷ο� �߻�

    unsigned int num67 = UINT_MAX + 1;            // unsigned int�� �ִ񰪺��� ū ���� �Ҵ�
    // �����÷ο� �߻�

    unsigned long long num68 = ULLONG_MAX + 1;    // unsigned long long�� �ִ񰪺��� ū ���� �Ҵ�
    // �����÷ο� �߻�

// unsigned char, unsigned short, unsigned int�� %u�� ����ϰ� 
// unsigned long long�� %llu�� ���
// ��ȣ ���� �������� ������ �� �ִ� ������ �Ѿ�� �ּڰ� 0���� �ٽ� ����
    printf("%u %u %u %llu\n", num65, num66, num67, num68); // 0 0 0 0


    int8_t num71 = -128;                    // 8��Ʈ(1����Ʈ) ũ���� ��ȣ �ִ� ������ ���� ����
    int16_t num72 = 32767;                  // 16��Ʈ(2����Ʈ) ũ���� ��ȣ �ִ� ������ ���� ���� 
    int32_t num73 = 2147483647;             // 32��Ʈ(4����Ʈ) ũ���� ��ȣ �ִ� ������ ���� ����
    int64_t num74 = 9223372036854775807;    // 64��Ʈ(8����Ʈ) ũ���� ��ȣ �ִ� ������ ���� ����

    // int8_t, int16_t, int32_t�� %d�� ����ϰ� int64_t�� %lld�� ���
    printf("%d %d %d %lld\n", num71, num72, num73, num74); // -128 32767 2147483647 9223372036854775807

    uint8_t num75 = 255;                      // 8��Ʈ(1����Ʈ) ũ���� ��ȣ ���� ������ ���� ����
    uint16_t num76 = 65535;                   // 16��Ʈ(2����Ʈ) ũ���� ��ȣ ���� ������ ���� ����
    uint32_t num77 = 4294967295;              // 32��Ʈ(4����Ʈ) ũ���� ��ȣ ���� ������ ���� ����
    uint64_t num78 = 18446744073709551615;    // 64��Ʈ(8����Ʈ) ũ���� ��ȣ ���� ������ ���� ����

    // uint8_t, uint16_t, uint32_t�� %u�� ����ϰ� uint64_t�� %llu�� ���
    printf("%u %u %u %llu\n", num75, num76, num77, num78); // 255 65535 4294967295 18446744073709551615







    return 0;
}