#include <stdio.h>

enum DayOfWeek {    // ������ ����
    Sunday = 0,         // �ʱ갪 �Ҵ�
    Monday,// 1...�� �ڵ��Ҵ�
    Tuesday,//2
    Wednesday,//3
    Thursday,//4
    Friday,//5
    Saturday//6
};

int main57()
{
    enum DayOfWeek week;    // ������ ���� ����

    week = Tuesday;    // ������ �� �Ҵ�

    printf("%d\n", week);   // 2: Tuesday�� �� ���

    return 0;
}