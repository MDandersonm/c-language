#define _CRT_SECURE_NO_WARNINGS    // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

int main11()
{
    int num1;

    printf("������ �Է��ϼ���: ");
    scanf("%d", &num1);    // ǥ�� �Է��� �޾Ƽ� ������ ����

    printf("%d\n", num1);    // ������ ������ ���

    int num3, num2;

    printf("������ �� �� �Է��ϼ���: ");
    scanf("%d %d", &num3, &num2);    // ���� �� �� �Է¹޾Ƽ� ���� �� ���� ����

    printf("%d %d\n", num3, num2);    // ������ ������ ���

    return 0;
}