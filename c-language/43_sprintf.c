#define _CRT_SECURE_NO_WARNINGS    // sprintf ���� ���� ���� ������ ���� ����
#include <stdio.h>     // sprintf �Լ��� ����� ��� ����

int main43()
{
    char s1[20];    // ũ�Ⱑ 20�� char�� �迭�� ����

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"�� ������ �����Ͽ� s1�� ����

    printf("%s\n", s1);    // Hello, world!: ���ڿ� s1 ���




    char s2[10];
    
    //s2 = "nice"; �Ұ���

    /*
    * char �迭�� ���� ���ڿ��� �Ҵ��ϴ� ���� C ���� ������ �ʽ��ϴ�. 
    ��� strcpy �Լ��� ����Ͽ� ���ڿ��� ������ �� �ֽ��ϴ�.
    strcpy �Լ��� ����Ϸ��� string.h ��� ������ �����ؾ� �մϴ�.
    */

    strcpy(s2, "nice");  // ���ڿ� "nice"�� s2�� ����
    printf("%s\n", s2);


    return 0;
}