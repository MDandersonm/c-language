#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int* a, int* b)
{
    return *a + *b;
}

int sub(int* a, int* b)
{
    return *a - *b;
}

int mul(int* a, int* b)
{
    return *a * *b;
}

int div(int* a, int* b)
{
    return *a / *b;
}

int main681()
{
    char funcName[10];
    int num1, num2;

    scanf("%s %d %d", funcName, &num1, &num2);

    /*
    �Լ� ������
�Լ� �����ʹ� �̸����� �� �� �ֵ��� �Լ��� ����Ű�� �������Դϴ�. �̸� ����Ͽ� �ٸ� �Լ��� ȣ���ϰų� �Լ��� �ּҸ� ������ �� �ֽ��ϴ�.
    int (*fp)(int*, int*)���� fp�� �Լ� �������� �̸��Դϴ�.
    */
    int (*fp)(int*, int*) = NULL;
    //(*fp)�� fp�� �Լ��� ����Ű�� ������ ����ϱ� ���� ��ȣ�� ��ǥ �����Դϴ�. ��ǥ�� "������"�� �ǹ��ϰ�, ��ȣ�� �켱������ ����մϴ�. 
    //int (*fp)(int*, int*) = NULL;�� ��ȯ Ÿ���� int�̸� �� ���� int* Ÿ�� ���ڸ� �޴� �Լ��� ����Ű�� ������ fp�� �����ϰ�, �� �����͸� NULL�� �ʱ�ȭ�ϴ� �ڵ��Դϴ�.


    /*stcmp
    s1�� s2�� ������ 0�� ��ȯ�մϴ�.
s1�� s2���� ���� ������ �տ� ���� ������ ��ȯ�մϴ�.
s1�� s2���� ���� ������ �ڿ� ���� ����� ��ȯ�մϴ�.
    
    */
    if (strcmp(funcName, "add") == 0)
    {
        fp = add;
    }
    else if (strcmp(funcName, "sub") == 0)
    {
        fp = sub;
    }
    else if (strcmp(funcName, "mul") == 0)
    {
        fp = mul;
    }
    else if (strcmp(funcName, "div") == 0)
    {
        fp = div;
    }

    if (fp == NULL)
    {
        printf("Invalid function name.\n");
        return 1; // ����
    }

    printf("%d\n", fp(&num1, &num2));


    return 0;
}