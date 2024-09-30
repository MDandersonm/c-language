#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    char name[30];
    int age;
    void (*print)(struct Person*);
    //void: �̰��� �Լ� �����Ͱ� ����Ű�� �Լ��� ��ȯ Ÿ���� ��Ÿ���ϴ�. ���⼭�� void Ÿ���� ��ȯ�ϴ� �Լ��� ����Ű�� �Լ� �����͸� �����ϰ� �ֽ��ϴ�.
    //(*): �̰��� ������ �Լ��� ����Ű�� ���������� ��Ÿ���ϴ�. ��ȣ�� ����ϴ� ������ ������ �켱 ���� �����Դϴ�. ��ȣ�� ������, *print�� �Լ��� ��ȯ�ϴ� ��ó�� ���� �� �ֱ� �����Դϴ�.
    //print: �̰��� �Լ� �������� �̸��Դϴ�. ��, print�� �Լ��� ����Ű�� ������ �����Դϴ�.
    //(struct Person)**: �̰��� �Լ� �����Ͱ� ����Ű�� �Լ��� �Ű����� ����� ��Ÿ���ϴ�. ���⼭�� struct Person* Ÿ���� �ϳ��� ���ڸ� �޴� �Լ��� ����Ű�� �ֽ��ϴ�.
};

void print(struct Person* p)
{
    printf("%s %d\n", p->name, p->age);
}

void executer(void (*fp[])(struct Person*), struct Person p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        fp[i](&p[i]);
    }
}

void (*getPrintFunc(struct Person* p))(struct Person*) {
    return p->print;
}

int main69()
{
    struct Person p[3];
    p[0].print = print;
    p[1].print = print;
    p[2].print = print;

    scanf("%s %d %s %d %s %d",
        p[0].name, &p[0].age,
        p[1].name, &p[1].age,
        p[2].name, &p[2].age
    );

    void (*fp[3])(struct Person*);
    /*
void: �Լ� �����Ͱ� ����Ű�� �Լ��� ��ȯ Ÿ���Դϴ�. ���⼭�� void Ÿ���� ��ȯ�ϴ� �Լ��� ����Ű�� �Լ� �����͸� �����ϰ� �ֽ��ϴ�.
(*): �̰��� �Լ� ���������� ��Ÿ���ϴ�.
fp[3]: �Լ� �������� �迭 �̸��� ũ���Դϴ�. fp�� �Լ� �������� �迭�� ����Ű��, �迭�� ũ��� 3�Դϴ�.
*(struct Person)**: �Լ� �����Ͱ� ����Ű�� �Լ��� �Ű����� ����Դϴ�. ���⼭�� struct Person* Ÿ���� ���� �ϳ��� �޴� �Լ��� ����Ű�� �ֽ��ϴ�.
* ���� fp�� struct Person* ���ڸ� �޴� �Լ��� ����Ű�� ������ 3���� ���� �� �ִ� �迭�Դϴ�.
�� �迭�� �Ϲ������� ���� ���� �Լ� �߿��� �������� �����Ͽ� ������ �� ���˴ϴ�. �� ���, struct Person�� ���� �پ��� ó�� �Լ����� fp �迭�� �Ҵ��ϰ�, �ʿ信 ���� �ش� �Լ����� ȣ���� �� �ֽ��ϴ�.
    */

    for (int i = 0; i < sizeof(p) / sizeof(struct Person); i++)
    {
        fp[i] = getPrintFunc(&p[i]);
    }
    /*
    * arr�� 10���� ������ ������ �� �ִ� �迭�̶�� sizeof(arr)�� �迭 arr�� ��ü ũ�⸦ ����Ʈ ������ ��ȯ�մϴ�. 
    ����(int)�� 4����Ʈ(�̴� �÷����� �����Ϸ��� ���� �ٸ� �� ����)�� ǥ���ȴٰ� �����ϸ�, sizeof(arr)�� 10 * 4 = 40����Ʈ�� ��ȯ�ϰ� �˴ϴ�.
  sizeof(int)�� ����(int)�� ũ�⸦ ����Ʈ ������ ��ȯ�ϹǷ�, 4����Ʈ�� ��ȯ�մϴ�.
���� sizeof(arr) / sizeof(int)�� 40 / 4 = 10�� ��ȯ�ϸ�, �̴� �迭 arr�� �ִ� ����� ������ ��ġ�մϴ�.
    */

    executer(fp, p, sizeof(p) / sizeof(struct Person));

    return 0;
}