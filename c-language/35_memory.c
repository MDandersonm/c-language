#include <stdio.h>
#include <stdlib.h>

int main35() {
    int* arr;
    int n = 5;

    /*
    * malloc (Memory Allocation) 함수는 지정된 바이트 수만큼의 메모리를 힙(heap) 영역에 할당하고, 할당된 메모리의 첫 번째 바이트의 주소를 반환합니다.
    */
    // 정수 5개를 저장할 수 있는 메모리를 동적으로 할당

    /*
    
    malloc 함수:

malloc은 memory allocation의 줄임말로, C 언어의 표준 라이브러리 중 하나인 <stdlib.h>에 정의되어 있습니다.
동적 메모리 할당을 위해 사용되며, 지정한 크기의 메모리를 힙(heap) 영역에서 할당하고, 할당된 메모리의 시작 주소를 반환합니다.
sizeof 연산자:

sizeof는 특정 데이터 형식 또는 변수의 크기(바이트 단위)를 반환하는 연산자입니다.
예를 들어, sizeof(int)는 int 타입의 크기를 바이트 단위로 반환합니다. 일반적으로, 대부분의 플랫폼에서 int의 크기는 4 바이트입니다(하지만 항상 4 바이트인 것은 아닙니다).
(int) 캐스팅*:

malloc 함수는 void* 타입의 포인터를 반환합니다. 이는 할당된 메모리의 타입이 무엇인지를 지정하지 않기 때문입니다.
따라서, 반환된 포인터를 우리가 원하는 타입의 포인터로 변환하기 위해 타입 캐스팅을 사용합니다. 이 경우에는 (int*)로 int 포인터로 변환합니다.
arr = ...:

여기서 arr는 int 타입의 포인터 변수로 가정합니다. malloc으로부터 반환된 메모리의 시작 주소는 arr에 저장됩니다.
결론적으로, arr = (int*)malloc(n * sizeof(int));는 힙 영역에서 n개의 int 크기만큼의 메모리를 동적으로 할당하고 그 시작 주소를 arr 포인터에 저장하는 작업을 수행합니다.
    */
    arr = (int*)malloc(n * sizeof(int));//malloc으로부터 반환된 메모리의 시작주소

    // 메모리 할당 확인
    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1; // 메모리 할당 실패 시 프로그램 종료
    }

    // 할당된 메모리에 값 저장
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // 저장된 값을 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 메모리 반환
    /*
free 함수는 이전에 malloc으로 할당된 메모리를 반환합니다.
메모리 누수를 방지하기 위해 할당된 메모리를 사용한 후에는 반드시 free 함수로 반환해야 합니다.
이미 free된 메모리를 다시 free하는 것은 오류를 일으킬 수 있습니다.
    */
    free(arr);

    return 0;
}
