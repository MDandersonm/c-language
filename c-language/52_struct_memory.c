#include <stdio.h>
#include <string.h>    // memset �Լ��� ����� ��� ����
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
struct Point2D {
    int x;
    int y;
};

int main52()
{
    struct Point2D p1;

    memset(&p1, 0, sizeof(struct Point2D));    // p1�� ����ü ũ�⸸ŭ 0���� ���� // memset(����ü������, �����Ұ�, sizeof(struct ����ü));

    printf("%d %d\n", p1.x, p1.y);    // 0 0: memset�� ����Ͽ� 0���� ���������Ƿ�
    printf("%d\n", sizeof(struct Point2D));
    // x, y ��� 0


    struct Point2D* p2 = malloc(sizeof(struct Point2D));    // ����ü ũ�⸸ŭ �޸� �Ҵ�

    memset(p2, 0, sizeof(struct Point2D));    // p1�� ����ü ũ�⸸ŭ 0���� ����

    printf("%d %d\n", p2->x, p2->y);    // 0 0: memset�� ����Ͽ� 0���� ���������Ƿ�
    // x, y ��� 0

    free(p2);    // ���� �޸� ����

    return 0;
}