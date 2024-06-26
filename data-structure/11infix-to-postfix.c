#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

StackNode* createNode(char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push2(StackNode** top, char data) {
    StackNode* newNode = createNode(data);
    if (!newNode) {
        printf("\nHeap Overflow");
        return;
    }
    newNode->next = *top;
    *top = newNode;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

char pop2(StackNode** top) {
    if (isEmpty(*top)) {
        return '$';
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

char peek2(StackNode* top) {
    if (isEmpty(top)) {
        return '$';
    }
    return top->data;
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infixToPostfix(char* exp) {
    StackNode* stack = NULL;
    int i, k = 0;
    for (i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {//알파벳또는 숫자인지 체크
            exp[k++] = exp[i];
        }
        else if (exp[i] == '(') {
            push2(&stack, exp[i]);
        }
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek2(stack) != '(') {
                exp[k++] = pop2(&stack);
            }
            pop2(&stack); // Remove '('
        }
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek2(stack))) {
                exp[k++] = pop2(&stack);
            }
            push2(&stack, exp[i]);
        }
    }

    while (!isEmpty(stack)) {
        exp[k++] = pop2(&stack);
    }
    exp[k] = '\0';
}

int main0110() {
    char exp[] = "((A*B)-(C/D))";
    infixToPostfix(exp);
    printf("후위 표현식: %s\n", exp);
    return 0;
}
