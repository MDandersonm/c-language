#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main591()
{
    short* numPtrA;
    short* numPtrB;
    short* numPtrC;

    scanf("%p", &numPtrA);


    numPtrB = numPtrA + 3;
    numPtrC = numPtrA + 5;

    //포인터에 정수를 더하면 (또는 빼면) 해당 포인터 타입의 크기 (바이트 단위)에 정수를 곱한 값만큼 주소가 증가 (또는 감소)합니다.
    /*
    컴퓨터 메모리는 주소로 나타나며 각 주소는 특정 바이트를 가리킵니다. 포인터는 메모리 주소를 저장하고 있기 때문에 포인터에 정수를 더하면 그 주소가 증가합니다.
포인터 타입이 고려되는 이유는, 포인터가 가리키는 타입에 따라 다음 위치로 이동할 때 얼마나 많은 바이트를 건너뛸 것인지 결정되기 때문입니다. 예를 들어, int 타입의 포인터가 있고, 
해당 포인터에 1을 더하면 그 포인터는 4바이트를 건너뜁니다 (대부분의 아키텍처에서 int는 4바이트를 차지합니다). 이렇게 동작하도록 설계된 것은 포인터 산술을 통해 배열과 같은 연속적인 메모리 위치를 효과적으로 다루기 위함입니다.
    */


    printf("%X\n", numPtrB);
    printf("%X\n", numPtrC);

    return 0;
}