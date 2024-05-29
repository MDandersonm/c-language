#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main387() {
    int** matrix;  // 이중 포인터로 2차원 배열을 가리킵니다.
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // 세로 공간(행) 메모리 할당
    matrix = (int**)malloc(rows * sizeof(int*));

    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 각 행마다 가로 공간(열) 메모리 할당
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation for row %d failed!\n", i);
            // 이전에 할당된 메모리 해제
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    // 2차원 배열에 값 입력
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 2차원 배열 출력
    printf("Matrix values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제. 먼저 각 행의 메모리를 해제한 후, 마지막에 전체 배열의 메모리를 해제
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
