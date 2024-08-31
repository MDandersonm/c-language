#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
size_t는 C 및 C++ 언어의 표준 라이브러리에서 정의된 데이터 타입으로, 객체의 크기를 나타내는 데 사용됩니다. 즉, 주로 메모리 관련 연산이나 배열의 크기를 나타낼 때 사용합니다.
size_t의 정확한 크기는 플랫폼과 컴파일러에 따라 다를 수 있지만, 일반적으로 주소 가능한 메모리의 최대 크기를 표현할 수 있도록 설계되어 있습니다. 그래서 32비트 시스템에서는 32비트, 64비트 시스템에서는 64비트로 나타날 수 있습니다.
size_t는 주로 다음과 같은 경우에 사용됩니다:
sizeof 연산자의 결과를 저장할 때.
문자열의 길이를 반환하는 strlen 함수와 같은 표준 라이브러리 함수의 반환 타입으로.
메모리 할당 함수인 malloc과 calloc에서 할당할 메모리의 크기를 지정할 때.
*/
void allocArray(void** arr, int length, size_t size) {
    *arr = malloc(length * size);// *arr는 arr이 가리키는 포인터를 역참조하여 해당 포인터를 나타냅니다.
    //이 경우, *arr는 외부에서 전달된 원래의 포인터(예: numArr1 또는 numArr2)를 나타냅니다.
    //*arr = malloc(length * size);는 동적으로 할당된 메모리의 주소를 arr이 가리키는 포인터에 할당합니다.
}

/*

이중 포인터 사용 이유 (void** arr):
함수 내에서 동적 메모리를 할당하고 그 주소를 반환하는 방법으로는 크게 두 가지가 있습니다.
할당된 메모리의 주소를 반환 값으로 돌려주는 방법.
이중 포인터를 인자로 받아 그곳에 할당된 메모리 주소를 저장하는 방법.
여기서는 두 번째 방법을 사용하였습니다.
void** arr는 포인터를 가리키는 포인터입니다. 이를 통해 함수 외부의 포인터에 할당된 메모리 주소를 직접 변경할 수 있습니다.
역참조의 이유 (*arr):
*arr를 사용하여 arr이 가리키는 포인터를 역참조하게 됩니다. 그래서 *arr는 원래의 포인터를 나타내게 됩니다.
예를 들어, allocArray((void**)&numArr1, 10, sizeof(long long)); 코드에서 numArr1의 주소가 arr에 전달됩니다. 따라서 *arr는 numArr1을 나타냅니다.
그렇기 때문에 *arr = malloc(length * size); 코드는 numArr1에 동적으로 할당된 메모리의 시작 주소를 저장하게 됩니다.
이런 방식으로, 함수 내에서 메모리를 동적으로 할당하고, 그 주소를 바로 원래의 포인터(예: numArr1)에 할당할 수 있습니다. 이를 위해 이중 포인터를 사용한 것입니다.
*/

int main632()
{
    long long* numArr1;
    int* numArr2;

    allocArray((void**)&numArr1, 10, sizeof(long long));
    allocArray((void**)&numArr2, 3, sizeof(int));

    scanf("%lld %d", &numArr1[9], &numArr2[2]);
    printf("%lld %d\n", numArr1[9], numArr2[2]);

    free(numArr2);
    free(numArr1);

    return 0;
}




/* 이렇게 할 수 도 있다.
void* allocArray(int length, size_t size) {
    return malloc(length * size);
}

int main()
{
    long long* numArr1;
    int* numArr2;

    numArr1 = allocArray(10, sizeof(long long));
    numArr2 = allocArray(3, sizeof(int));

    scanf("%lld %d", &numArr1[9], &numArr2[2]);
    printf("%lld %d\n", numArr1[9], numArr2[2]);

    free(numArr2);
    free(numArr1);

    return 0;
}
*/
