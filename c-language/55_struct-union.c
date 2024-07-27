#include <stdio.h>

struct Phone {    // �޴���ȭ ����ü
    int areacode;                 // ������ȣ
    unsigned long long number;    // �޴���ȭ ��ȣ
};

struct Person {    // ��� ����ü
    char name[20];         // �̸�
    int age;               // ����
    struct Phone phone;    // �޴���ȭ. ����ü�� ����� ����
};

int main550()
{
    struct Person p1;

    p1.phone.areacode = 82;          // ����.���.��� ������ �����Ͽ� �� �Ҵ�
    p1.phone.number = 3045671234;    // ����.���.��� ������ �����Ͽ� �� �Ҵ�

    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);    // 82 3045671234

    return 0;
}

int main551()
{
    // phone�� ��� areacode���� 82, number���� 3045671234
    struct Person p1 = { .name = "Andrew", .age = 25, {.areacode = 82, .number = 3045671234 } };
    /*
    * 
�־��� �ڵ� ������ ���� Person ����ü�� ���ǰ� �������� �ʾҽ��ϴ�. ��
���� �ڵ� ������ �������� �����ϸ� Person ����ü�� name, age, �׸��� phone�̶�� ����� ������ ������, phone�� �ٸ� ����ü Ÿ���� ������ ���� �� �����ϴ�.
.name �տ� �ƹ��͵� ���� ������ ����ü�� �ʱ�ȭ �߿� �̸����� ����� �ʱ�ȭ�ϴ� ������ �ʱ�ȭ��(Designated Initializer)��� C ����� ����� ����ϰ� �ֱ� �����Դϴ�. 
�� ����� ����ϸ� ����ü�� ����� �̸��� �����Ͽ� ������ ������� �ʱ�ȭ�� �� �ֽ��ϴ�.

    */

    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);    // 82 3045671234

    // phone�� ��� areacode���� 82, number���� 3087654321
    struct Person p2 = { "Maria", 19, { 82, 3087654321 } };

    printf("%d %llu\n", p2.phone.areacode, p2.phone.number);    // 82 3087654321

    return 0;
}