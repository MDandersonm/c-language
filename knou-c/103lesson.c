/*
�ڷ����� ���� ũ�⸦ ��Ÿ���� ���α׷�
*/

#include <stdio.h>

void main103() {
    /*
    char �ڷ����� �ַ� ���ڸ� �����ϴµ� ���ȴ�. ASCII �ڵ� ���� �ش��ϴ� ���ڸ� ǥ���ϴ� �� ���ȴ�.
    char Ÿ�Կ� ����Ǵ� ���� �����Ϸ��� �ý��ۿ� ���� ��ȣ �ִ�(signed) �� �Ǵ� ��ȣ ����(unsigned) ���� �� �ִ� 
    */
    ////char �ڷ����� ũ�⸦ ����Ʈ ������ ����Ѵ�. %d�� ����� ���� ���� ���� ���� �������̸�, sizeof(char)�� char�� ũ�⸦ ����Ʈ ������ ����Ͽ� ������ ��Ÿ���ش�.

    printf("char �ڷ��� ũ�� : %d byte\n", sizeof(char));// signed char�� ����
    printf("signed char �ڷ��� ũ�� : %d byte\n", sizeof(signed char));//signed char: -128���� 127������ ���� ��Ÿ�� �� �ִ�
    printf("unsigned char �ڷ��� ũ�� : %d byte\n", sizeof(unsigned char));//unsigned char: 0���� 255������ ���� ��Ÿ�� �� �ִ�

    /*
    short �ڷ����� �������� �� ����
    short �ڷ����� short int�� ���Ӹ�
    ���� ������ �߿��� ���� ���� ũ���� ���� �����ϴ� �� ���ȴ�.
    */

    printf("short �ڷ��� ũ�� : %d byte\n", sizeof(short)); //short�� 2����Ʈ ũ�⸦ ������, - 32,768���� 32,767������ ���� ǥ���� �� �ִ�
    printf("short int �ڷ��� ũ�� : %d byte\n", sizeof(short int));//short�� ���� int�� ��������
    printf("signed short �ڷ��� ũ�� : %d byte\n", sizeof(signed short)); ///short�� ���� int�� ���������ϴ�.
    printf("signed short int �ڷ��� ũ�� : %d byte\n", sizeof(signed short int)); ///short�� ���� int�� signed�� ������ �����ϴ�
    printf("unsigned short �ڷ��� ũ�� : %d byte\n", sizeof(unsigned short));//0 ~65,535������ ���� ǥ���� �� �ִ� ��ȣ ���� ����
    printf("unsigned short int �ڷ��� ũ�� : %d byte\n", sizeof(unsigned short int)); //int�� ���� �����ϱ⿡ unsigned short�� ����


    /*
    int �ڷ����� ���� �⺻���� ������
    32bit���� int�� 4����Ʈ�� �����ϸ�, -2,147,483,648���� 2,147,483,647������ ������ ǥ������
    */
    printf("int �ڷ��� ũ�� : %d byte\n", sizeof(int)); //4����Ʈ signed int�� ����. signed�� ������ ���� 
    printf("signed int �ڷ��� ũ�� : %d byte\n", sizeof(signed int));// 4����Ʈ , 32bit���� -2,147,483,648���� 2,147,483,647������ ������ ǥ������
    printf("unsigned �ڷ��� ũ�� : %d byte\n", sizeof(unsigned));//4����Ʈ unsigned int�� ����. int�� ������ �����̴�
    printf("unsigned int �ڷ��� ũ�� : %d byte\n", sizeof(unsigned int));//4����Ʈ 32bit�ý��ۿ����� 0~4,294,967,295�� ���� ǥ�� 

    /*
    *long �ڷ����� int �ڷ������� ���ų� �� ū ������ ���� ���� �����Ѵ�
    *
    */

    printf("long �ڷ��� ũ�� : %d byte\n", sizeof(long));//4byte signed long int�� ���Ӹ��� signed�� int�� ���������ϴ�.
    printf("long int �ڷ��� ũ�� : %d byte\n", sizeof(long int));//4byte signed long int�� ���Ӹ��� signed�� ���������ϴ�.
    printf("signed long �ڷ��� ũ�� : %d byte\n", sizeof(signed long));//4byte signed long int�� ���Ӹ���  int�� ���������ϴ�.
    printf("signed long int �ڷ��� ũ�� : %d byte\n", sizeof(signed long int));//4byte  16bit,32bit ��� -2,147,483,648���� 2,147,483,647������ ������ ǥ��
    printf("unsigned long �ڷ��� ũ�� : %d byte\n", sizeof(unsigned long));//4byte unsigned long int�� ���Ӹ��� int�� ���������ϴ�.
    printf("unsigned long int �ڷ��� ũ�� : %d byte\n", sizeof(unsigned long int));//4byte   16it������ 0~65,535 32bit������ 0 ~ 42,959,667,295������ ������ ǥ��

    /*
    long long �ڷ�����  �ּ� 64��Ʈ�� ũ�⸦ ������, �̸� ���� �ſ� ū ������ ���� ���� ������ �� �ִ�.
    */

    printf("long long �ڷ��� ũ�� : %d byte\n", sizeof(long long));// 8byte . signed long long int�� �����. signed�� int�� ��������
    printf("long long int �ڷ��� ũ�� : %d byte\n", sizeof(long long int));// 8byte.  signed long long int�� �����. signed�� ��������
    printf("signed long long �ڷ��� ũ�� : %d byte\n", sizeof(signed long long));// 8byte  signed long long int�� �����. int�� ��������
    printf("signed long long int �ڷ��� ũ�� : %d byte\n", sizeof(signed long long int));// 8byte.  -9,223,372,036,854,775,808���� 9,223,372,036,854,775,807������ ���� ����
    printf("unsigned long long �ڷ��� ũ�� : %d byte\n", sizeof(unsigned long long));// 8byte    unsigned long long int�� �����. int�� ��������
    printf("unsigned long long int �ڷ��� ũ�� : %d byte\n", sizeof(unsigned long long int));// 8byte. , 0���� 18,446,744,073,709,551,615���� ���� ����

    /*
    �Ǽ���
    �⺻���� double���̴�.
    */

    printf("float �ڷ��� ũ�� : %d byte\n", sizeof(float));//4byte  3.4E-38 ~ 3.4E+38 �������� ǥ��
    printf("double �ڷ��� ũ�� : %d byte\n", sizeof(double));//8byte   1.7E-308 ~ 1.7E+308 ���� ǥ��
    printf("long double �ڷ��� ũ�� : %d byte\n", sizeof(long double)); //8byte 1.7E-308 ~ 1.7E+308 ���� ǥ��
}
