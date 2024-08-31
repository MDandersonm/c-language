#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
size_t�� C �� C++ ����� ǥ�� ���̺귯������ ���ǵ� ������ Ÿ������, ��ü�� ũ�⸦ ��Ÿ���� �� ���˴ϴ�. ��, �ַ� �޸� ���� �����̳� �迭�� ũ�⸦ ��Ÿ�� �� ����մϴ�.
size_t�� ��Ȯ�� ũ��� �÷����� �����Ϸ��� ���� �ٸ� �� ������, �Ϲ������� �ּ� ������ �޸��� �ִ� ũ�⸦ ǥ���� �� �ֵ��� ����Ǿ� �ֽ��ϴ�. �׷��� 32��Ʈ �ý��ۿ����� 32��Ʈ, 64��Ʈ �ý��ۿ����� 64��Ʈ�� ��Ÿ�� �� �ֽ��ϴ�.
size_t�� �ַ� ������ ���� ��쿡 ���˴ϴ�:
sizeof �������� ����� ������ ��.
���ڿ��� ���̸� ��ȯ�ϴ� strlen �Լ��� ���� ǥ�� ���̺귯�� �Լ��� ��ȯ Ÿ������.
�޸� �Ҵ� �Լ��� malloc�� calloc���� �Ҵ��� �޸��� ũ�⸦ ������ ��.
*/
void allocArray(void** arr, int length, size_t size) {
    *arr = malloc(length * size);// *arr�� arr�� ����Ű�� �����͸� �������Ͽ� �ش� �����͸� ��Ÿ���ϴ�.
    //�� ���, *arr�� �ܺο��� ���޵� ������ ������(��: numArr1 �Ǵ� numArr2)�� ��Ÿ���ϴ�.
    //*arr = malloc(length * size);�� �������� �Ҵ�� �޸��� �ּҸ� arr�� ����Ű�� �����Ϳ� �Ҵ��մϴ�.
}

/*

���� ������ ��� ���� (void** arr):
�Լ� ������ ���� �޸𸮸� �Ҵ��ϰ� �� �ּҸ� ��ȯ�ϴ� ������δ� ũ�� �� ������ �ֽ��ϴ�.
�Ҵ�� �޸��� �ּҸ� ��ȯ ������ �����ִ� ���.
���� �����͸� ���ڷ� �޾� �װ��� �Ҵ�� �޸� �ּҸ� �����ϴ� ���.
���⼭�� �� ��° ����� ����Ͽ����ϴ�.
void** arr�� �����͸� ����Ű�� �������Դϴ�. �̸� ���� �Լ� �ܺ��� �����Ϳ� �Ҵ�� �޸� �ּҸ� ���� ������ �� �ֽ��ϴ�.
�������� ���� (*arr):
*arr�� ����Ͽ� arr�� ����Ű�� �����͸� �������ϰ� �˴ϴ�. �׷��� *arr�� ������ �����͸� ��Ÿ���� �˴ϴ�.
���� ���, allocArray((void**)&numArr1, 10, sizeof(long long)); �ڵ忡�� numArr1�� �ּҰ� arr�� ���޵˴ϴ�. ���� *arr�� numArr1�� ��Ÿ���ϴ�.
�׷��� ������ *arr = malloc(length * size); �ڵ�� numArr1�� �������� �Ҵ�� �޸��� ���� �ּҸ� �����ϰ� �˴ϴ�.
�̷� �������, �Լ� ������ �޸𸮸� �������� �Ҵ��ϰ�, �� �ּҸ� �ٷ� ������ ������(��: numArr1)�� �Ҵ��� �� �ֽ��ϴ�. �̸� ���� ���� �����͸� ����� ���Դϴ�.
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




/* �̷��� �� �� �� �ִ�.
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
