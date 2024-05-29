#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main387() {
    int** matrix;  // ���� �����ͷ� 2���� �迭�� ����ŵ�ϴ�.
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // ���� ����(��) �޸� �Ҵ�
    matrix = (int**)malloc(rows * sizeof(int*));

    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // �� �ึ�� ���� ����(��) �޸� �Ҵ�
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation for row %d failed!\n", i);
            // ������ �Ҵ�� �޸� ����
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    // 2���� �迭�� �� �Է�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 2���� �迭 ���
    printf("Matrix values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // �޸� ����. ���� �� ���� �޸𸮸� ������ ��, �������� ��ü �迭�� �޸𸮸� ����
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
