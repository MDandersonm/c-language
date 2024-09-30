#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    char name[30];
    int age;
    void (*print)(struct Person*);
    //void: 이것은 함수 포인터가 가리키는 함수의 반환 타입을 나타냅니다. 여기서는 void 타입을 반환하는 함수를 가리키는 함수 포인터를 선언하고 있습니다.
    //(*): 이것은 변수가 함수를 가리키는 포인터임을 나타냅니다. 괄호를 사용하는 이유는 연산자 우선 순위 때문입니다. 괄호가 없으면, *print가 함수를 반환하는 것처럼 보일 수 있기 때문입니다.
    //print: 이것은 함수 포인터의 이름입니다. 즉, print는 함수를 가리키는 포인터 변수입니다.
    //(struct Person)**: 이것은 함수 포인터가 가리키는 함수의 매개변수 목록을 나타냅니다. 여기서는 struct Person* 타입의 하나의 인자를 받는 함수를 가리키고 있습니다.
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
void: 함수 포인터가 가리키는 함수의 반환 타입입니다. 여기서는 void 타입을 반환하는 함수를 가리키는 함수 포인터를 선언하고 있습니다.
(*): 이것은 함수 포인터임을 나타냅니다.
fp[3]: 함수 포인터의 배열 이름과 크기입니다. fp는 함수 포인터의 배열을 가리키며, 배열의 크기는 3입니다.
*(struct Person)**: 함수 포인터가 가리키는 함수의 매개변수 목록입니다. 여기서는 struct Person* 타입의 인자 하나를 받는 함수를 가리키고 있습니다.
* 따라서 fp는 struct Person* 인자를 받는 함수를 가리키는 포인터 3개를 담을 수 있는 배열입니다.
이 배열은 일반적으로 여러 개의 함수 중에서 동적으로 선택하여 실행할 때 사용됩니다. 이 경우, struct Person에 대한 다양한 처리 함수들을 fp 배열에 할당하고, 필요에 따라 해당 함수들을 호출할 수 있습니다.
    */

    for (int i = 0; i < sizeof(p) / sizeof(struct Person); i++)
    {
        fp[i] = getPrintFunc(&p[i]);
    }
    /*
    * arr는 10개의 정수를 저장할 수 있는 배열이라면 sizeof(arr)는 배열 arr의 전체 크기를 바이트 단위로 반환합니다. 
    정수(int)가 4바이트(이는 플랫폼과 컴파일러에 따라 다를 수 있음)로 표현된다고 가정하면, sizeof(arr)는 10 * 4 = 40바이트를 반환하게 됩니다.
  sizeof(int)는 정수(int)의 크기를 바이트 단위로 반환하므로, 4바이트를 반환합니다.
따라서 sizeof(arr) / sizeof(int)는 40 / 4 = 10을 반환하며, 이는 배열 arr에 있는 요소의 개수와 일치합니다.
    */

    executer(fp, p, sizeof(p) / sizeof(struct Person));

    return 0;
}