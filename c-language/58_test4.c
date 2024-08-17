#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stats {
    float health;
    float healthRegen;
    unsigned int mana;
    float manaRegen;
    float range;
    float attackDamage;
    float armor;
    float attackSpeed;
    float magicResist;
    unsigned int movementSpeed;
};

int main584()
{
    void* ptr = malloc(sizeof(struct Stats));
    struct Stats st;

    scanf("%u %u", &st.mana, &st.movementSpeed);

    memcpy(ptr, &st, sizeof(struct Stats));
    /*
memcpy(ptr, &st, sizeof(struct Stats)); �ڵ�� st ����ü�� ��� ����� ���� ptr�� ����Ű�� �޸� ����(���⼭�� ptr�� ����Ű�� ����ü)���� �����Ѵٴ� ���� �ǹ��մϴ�.
��Ȯ�� �����ڸ�, memcpy�� �ܼ��� �޸��� �� �������� �ٸ� �������� ����Ʈ ������ �����͸� �����ϴ� �Լ��Դϴ�. ���⼭ sizeof(struct Stats)��ŭ�� ũ��(��, struct Stats ����ü�� ũ��)�� �����ϰ� �˴ϴ�.
����, st�� ��� ��� ������ ptr�� ����Ű�� �޸� ��ġ(�� ��쿡�� �������� �Ҵ�� �޸�)�� ����˴ϴ�. ���������, �� memcpy ȣ�� �Ŀ��� ptr�� ����Ű�� �޸� ������ ����ü�� st�� ���� ������ ���� ���� �˴ϴ�.
����ϸ�, �� memcpy ȣ���� st ����ü�� ��� ��� ���� ptr�� ����Ű�� ����ü�� �����ϴ� ���Դϴ�.

memcpy�� �޸��� �� �������� �ٸ� �������� ����Ʈ ������ �����͸� �����ϴ� �Լ��Դϴ�. memcpy�� �Ű������� ���� ������ ������ �����ϴ�:

dest (ù ��° �Ű�����):
������ ����� ���� �ּҸ� ����ŵ�ϴ�.
��, �����Ͱ� ����� �������� �������Դϴ�.

src (�� ��° �Ű�����):
����� �������� ���� �ּҸ� ����ŵ�ϴ�.
�������� ���� �������Դϴ�.

n (�� ��° �Ű�����):
������ ����Ʈ ���� ��Ÿ���ϴ�.
src���� dest�� ����� ����Ʈ�� ���� �����մϴ�.
memcpy�� ȣ���� ���� ���ǰ� �ʿ��մϴ�. ����Ǵ� ����(src)�� ���(dest)�� �޸� ������ ��ø���� �ʾƾ� �մϴ�. ��ø�� ��쿡�� memmove �Լ��� ����ϴ� ���� �����ϴ�.
    
    */

    st.mana = 0;
    st.movementSpeed = 0;


    memcpy(&st, ptr, sizeof(struct Stats));
    printf("%u\n%u\n", st.mana, st.movementSpeed);


    free(ptr);

    return 0;
}