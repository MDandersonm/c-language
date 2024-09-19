#include <stdio.h>

int partition2(int list[], int begin, int end) {
    int pivotIndex = (begin + end) / 2;
    int pivotValue = list[pivotIndex];
    int left = begin, right = end;

    while (left <= right) {
        while (list[left] < pivotValue) left++;
        while (pivotValue < list[right]) right--;
        if (left <= right) {
            int temp = list[left];
            list[left] = list[right];
            list[right] = temp;
            left++;
            right--;
        }
    }
    return left; // 반환하는 값은 'left', 이 값이 새로운 경계가 됨
}

void quickSort2(int list[], int begin, int end) {
    if (begin < end) {
        int p = partition2(list, begin, end - 1);
        quickSort2(list, begin, p - 1);
        quickSort2(list, p, end);
    }
}

int main02610() {
    int size = 8;
    int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
    printf("\n퀵정렬할 배열:  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    quickSort2(list, 0, size);

    printf("\n퀵정렬 후 배열:  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
