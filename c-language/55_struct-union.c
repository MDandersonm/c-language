#include <stdio.h>

struct Phone {    // 휴대전화 구조체
    int areacode;                 // 국가번호
    unsigned long long number;    // 휴대전화 번호
};

struct Person {    // 사람 구조체
    char name[20];         // 이름
    int age;               // 나이
    struct Phone phone;    // 휴대전화. 구조체를 멤버로 가짐
};

int main550()
{
    struct Person p1;

    p1.phone.areacode = 82;          // 변수.멤버.멤버 순으로 접근하여 값 할당
    p1.phone.number = 3045671234;    // 변수.멤버.멤버 순으로 접근하여 값 할당

    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);    // 82 3045671234

    return 0;
}

int main551()
{
    // phone의 멤버 areacode에는 82, number에는 3045671234
    struct Person p1 = { .name = "Andrew", .age = 25, {.areacode = 82, .number = 3045671234 } };
    /*
    * 
주어진 코드 조각을 보면 Person 구조체의 정의가 제공되지 않았습니다. 그
러나 코드 내용을 바탕으로 추정하면 Person 구조체는 name, age, 그리고 phone이라는 멤버를 가지고 있으며, phone은 다른 구조체 타입을 가지고 있을 것 같습니다.
.name 앞에 아무것도 없는 이유는 구조체의 초기화 중에 이름으로 멤버를 초기화하는 지정된 초기화자(Designated Initializer)라는 C 언어의 기능을 사용하고 있기 때문입니다. 
이 기능을 사용하면 구조체의 멤버를 이름을 지정하여 순서에 상관없이 초기화할 수 있습니다.

    */

    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);    // 82 3045671234

    // phone의 멤버 areacode에는 82, number에는 3087654321
    struct Person p2 = { "Maria", 19, { 82, 3087654321 } };

    printf("%d %llu\n", p2.phone.areacode, p2.phone.number);    // 82 3087654321

    return 0;
}