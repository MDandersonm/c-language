#include <stdio.h>

union Data {
    int i;
    int j;
    float f;
    char str[20];
};

int main54() {
    union Data data;

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f); // 이 시점에서 data.i의 값은 더 이상 유효하지 않습니다.

    data.j = 103;
    printf("data.j : %d\n", data.j);
    printf("data.i : %d\n", data.i);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str); // 이 시점에서 data.f와 data.i의 값은 더 이상 유효하지 않습니다.

    return 0;
}
