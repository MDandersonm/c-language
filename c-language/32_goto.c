#include <stdio.h>

int main32() {
    int number;

input_data://���̺�
    printf("Enter a positive number: ");
    scanf_s("%d", &number);

    if (number < 0) {
        printf("You entered a negative number. Please try again.\n");
        goto input_data;// ���̺�� �ٽ� �̵��϶�
    }

    printf("You entered: %d\n", number);
    return 0;
}
