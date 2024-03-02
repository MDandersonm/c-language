#include <stdio.h>
#include <float.h>    // �Ǽ� �ڷ����� ��� �ּڰ�, �ִ��� ���ǵ� ��� ����
int main02()
{
    float num1 = 0.1f;               // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
    // float�� ���� �ڿ� f�� ����

    double num2 = 3867.215820;       // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
    // double�� ���� �ڿ� �ƹ��͵� ������ ����

    long double num3 = 9.327513l;    // �����е� �ε��Ҽ��� ������ �����ϰ� ���� �Ҵ�
    // long double�� ���� �ڿ� l�� ����

// float�� double�� %f�� ���, long double�� %Lf�� ���
    printf("%f %f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513


    float num4 = 3.e5f;             // ���� ǥ������� 300000�� ǥ��
    // float�� ���� �ڿ� f�� ����

    double num5 = -1.3827e-2;       // ���� ǥ������� -0.013827�� ǥ��
    // double�� ���� �ڿ� �ƹ��͵� ������ ����

    long double num6 = 5.21e+9l;    // ���� ǥ������� 5210000000�� ǥ��
    // long double�� ���� �ڿ� l�� ����

// float�� double�� %f�� ���, long double�� %Lf�� ���
    printf("%f %f %Lf\n", num4, num5, num6); // 300000.000000 -0.013827 5210000000.000000

    // ���� ǥ������� ����� ���� float�� double�� %e�� ���, long double�� %Le�� ���
    printf("%e %e %Le\n", num4, num5, num6); // 3.000000e+05 -1.382700e-02 5.210000e+09


    float num11 = FLT_MIN;           // float�� ��� �ּڰ�
    float num12 = FLT_MAX;           // float�� ��� �ִ�
    double num13 = DBL_MIN;          // double�� ��� �ּڰ�
    double num14 = DBL_MAX;          // double�� ��� �ִ�
    long double num15 = LDBL_MIN;    // long double�� ��� �ּڰ�
    long double num16 = LDBL_MAX;    // long double�� ��� �ִ�

    printf("%.40f %.2f\n", num11, num12);    // 0.0000000000000000000000000000000000000118
    // 340282346638528859811704183484516925440.00

    printf("%e %e\n", num13, num14);         // 2.225074e-308 1.797693e+308
    printf("%Le %Le\n", num15, num16);       // 2.225074e-308 1.797693e+308

    char c1 = 'a';    // ���� ������ �����ϰ� ���� a�� ����
    char c2 = 'b';    // ���� ������ �����ϰ� ���� b�� ����

    // char�� %c�� ����ϸ� ���ڰ� ��µǰ�, %d�� ����ϸ� �������� ��µ�
    printf("%c, %d\n", c1, c1);    // a, 97: a�� ASCII �ڵ尪�� 97
    printf("%c, %d\n", c2, c2);    // b, 98: b�� ASCII �ڵ尪�� 98

    char c3 = 97;    // a�� ASCII �ڵ尪 97 ����
    char c4 = 98;    // b�� ASCII �ڵ尪 98 ����

    // char�� %c�� ����ϸ� ���ڰ� ��µǰ�, %d�� ����ϸ� �������� ��µ�
    printf("%c, %d\n", c3, c3); // a, 97
    printf("%c, %d\n", c4, c4); // b, 98

    char c5 = 0x61;    // a�� ASCII �ڵ尪 0x61 �Ҵ�
    char c6 = 0x62;    // b�� ASCII �ڵ尪 0x62 �Ҵ�

    // char�� %c�� ����ϸ� ���ڰ� ��µǰ�, %d�� ����ϸ� ���� ���� ��µ�
    // %x�� ����ϸ� 16������ ��µ�
    printf("%c, %d, 0x%x\n", c5, c5, c5);    // a, 97, 0x61
    printf("%c, %d, 0x%x\n", c6, c6, c6);    // b, 98, 0x62

    char c7 = '0';    // ���� 0�� ����
    char c8 = 0;      // ���� 0�� ����

    printf("%c %d\n", c7, c7);    // 0 48: ���� ���·� 0�� ��µ�
    // ���� 0�� ASCII �ڵ� 48�� ��µ�

    printf("%c %d\n", c8, c8);    // 0: ASCII �ڵ� 0�� �ι����̹Ƿ� �ƹ��͵� ��µ��� ����
    // ���� 0�� ��µ�

    printf("%c %d\n", 'a' + 1, 'a' + 1);    // b 98: a�� ASCII �ڵ尪 97�̰�, 
    // 97�� 1�� ���Ͽ� 98�� �Ǿ����Ƿ� b�� ��µ�

    printf("%c %d\n", 97 + 1, 97 + 1);      // b 98: ASCII �ڵ尪 97�� 1�� ���Ͽ� 98�� �Ǿ����Ƿ� 
    // b�� ��µ�

    char c9 = 'a';
    printf("%c %d\n", c9 + 1, c9 + 1);    // b 98

    char c11 = 'a';           // ���� a �Ҵ�
    char c12 = 'b';           // ���� b �Ҵ� 
    char lineFeed = '\n';    // ���� ���� \n �Ҵ�
    printf("%c%c%c%c", c11, lineFeed, c12, lineFeed);    // ���� ���ڵ� %c�� ����� �� ����
    
    printf("%d 0x%x\n", lineFeed, lineFeed);    // 10 0xa: ���� ������ ASCII �ڵ� ���


    //2�� 5�� ���ٿ� ��µǰԸ��弼��
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

    printf("%c\n", c21 + '0');//����
    printf("%c\n", c22 + '0');//����

//A�� ��µǰ� ����ÿ�
    char c31 = 'a';

    printf("%c\n", c31-'a'+'A');

    return 0;
}