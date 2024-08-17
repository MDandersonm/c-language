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
memcpy(ptr, &st, sizeof(struct Stats)); 코드는 st 구조체의 모든 멤버의 값을 ptr가 가리키는 메모리 영역(여기서는 ptr가 가리키는 구조체)으로 복사한다는 것을 의미합니다.
정확히 말하자면, memcpy는 단순히 메모리의 한 영역에서 다른 영역으로 바이트 단위로 데이터를 복사하는 함수입니다. 여기서 sizeof(struct Stats)만큼의 크기(즉, struct Stats 구조체의 크기)를 복사하게 됩니다.
따라서, st의 모든 멤버 값들이 ptr가 가리키는 메모리 위치(이 경우에는 동적으로 할당된 메모리)로 복사됩니다. 결과적으로, 이 memcpy 호출 후에는 ptr가 가리키는 메모리 영역의 구조체는 st의 값과 동일한 값을 갖게 됩니다.
요약하면, 이 memcpy 호출은 st 구조체의 모든 멤버 값을 ptr가 가리키는 구조체로 복사하는 것입니다.

memcpy는 메모리의 한 영역에서 다른 영역으로 바이트 단위로 데이터를 복사하는 함수입니다. memcpy의 매개변수에 대한 설명은 다음과 같습니다:

dest (첫 번째 매개변수):
복사할 대상의 시작 주소를 가리킵니다.
즉, 데이터가 복사될 목적지의 포인터입니다.

src (두 번째 매개변수):
복사될 데이터의 시작 주소를 가리킵니다.
데이터의 원본 포인터입니다.

n (세 번째 매개변수):
복사할 바이트 수를 나타냅니다.
src에서 dest로 복사될 바이트의 수를 지정합니다.
memcpy를 호출할 때는 주의가 필요합니다. 복사되는 원본(src)과 대상(dest)의 메모리 영역이 중첩되지 않아야 합니다. 중첩될 경우에는 memmove 함수를 사용하는 것이 좋습니다.
    
    */

    st.mana = 0;
    st.movementSpeed = 0;


    memcpy(&st, ptr, sizeof(struct Stats));
    printf("%u\n%u\n", st.mana, st.movementSpeed);


    free(ptr);

    return 0;
}