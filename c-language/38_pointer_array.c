//그럼 배열의 크기를 동적으로 지정하려면 어떻게 해야 할까요? 크기를 동적으로 지정하려면 포인터를 선언하고 메모리를 할당한 뒤 메모리를 배열처럼 사용해야 합니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main388() {
    int* arr;  // 정수 배열을 가리키는 포인터
    int length;  // 배열의 크기 (동적으로 지정할 것임)

    printf("Enter the size of the array: ");
    scanf("%d", &length);

    // 메모리 동적 할당. 크기는 사용자가 지정한 값에 int의 크기를 곱한 만큼이다.
    arr = (int*)malloc(length * sizeof(int));

    if (arr == NULL) {  // 메모리 할당 실패 시
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 사용자에게 배열의 각 요소에 대한 값을 입력받음
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 배열 요소 출력
    printf("You entered: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // 동적으로 할당한 메모리는 사용 후 해제해야 함

    return 0;
}
