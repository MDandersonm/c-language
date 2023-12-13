#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// 기본 연산 함수 정의
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
float divide(int a, int b) { return (float)a / b; }

int main() {
    int num1, num2;
    char operator;
    printf("Enter an expression (ex: 5 + 3): ");
    scanf_s("%d %c %d", &num1, &operator, 1, &num2);

    switch (operator) {
    case '+':
        printf("Result: %d\n", add(num1, num2));
        break;
    case '-':
        printf("Result: %d\n", subtract(num1, num2));
        break;
    case '*':
        printf("Result: %d\n", multiply(num1, num2));
        break;
    case '/':
        printf("Result: %f\n", divide(num1, num2));
        break;
    default:
        printf("Invalid operator\n");
    }
    return 0;
}
