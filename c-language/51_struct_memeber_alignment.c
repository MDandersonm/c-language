#include <stdio.h>

struct Example1 {
    char c;
    int i;
};

struct Example2 {
    int i;
    char c;
};

int main51() {
    printf("Size of Example1: %lu\n", sizeof(struct Example1));
    printf("Size of Example2: %lu\n", sizeof(struct Example2));
    return 0;
}
