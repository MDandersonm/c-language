//�׷� �迭�� ũ�⸦ �������� �����Ϸ��� ��� �ؾ� �ұ��? ũ�⸦ �������� �����Ϸ��� �����͸� �����ϰ� �޸𸮸� �Ҵ��� �� �޸𸮸� �迭ó�� ����ؾ� �մϴ�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main388() {
    int* arr;  // ���� �迭�� ����Ű�� ������
    int length;  // �迭�� ũ�� (�������� ������ ����)

    printf("Enter the size of the array: ");
    scanf("%d", &length);

    // �޸� ���� �Ҵ�. ũ��� ����ڰ� ������ ���� int�� ũ�⸦ ���� ��ŭ�̴�.
    arr = (int*)malloc(length * sizeof(int));

    if (arr == NULL) {  // �޸� �Ҵ� ���� ��
        printf("Memory allocation failed!\n");
        return 1;
    }

    // ����ڿ��� �迭�� �� ��ҿ� ���� ���� �Է¹���
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // �迭 ��� ���
    printf("You entered: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);  // �������� �Ҵ��� �޸𸮴� ��� �� �����ؾ� ��

    return 0;
}
