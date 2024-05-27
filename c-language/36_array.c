#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main36()
{
    int numArr[5];
    int smallestNumber;
    smallestNumber = 2147483647;
    for (int i=0; i < 5; i++) {
        scanf("%d", &numArr[i]);
    };

    for (int i = 0; i < 5; i++) {
        if (smallestNumber > numArr[i]) {
            smallestNumber = numArr[i];
        }
    };
    

    printf("%d %d %d %d %d\n", numArr[0], numArr[1], numArr[2],numArr[3], numArr[4]);
    printf("%d\n", smallestNumber);

    return 0;
}