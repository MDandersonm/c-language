#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int age;
    float gpa;
} Student;

// ���� ���� �Լ�
void shallow_copy(char** dest, char* src) {
    *dest = src; // ������ ���縸 ����
}

/*
�ڵ忡�� shallow_copy1 �Լ��� �� ���� ������ �Ű������� ������, 
������ dest �����Ϳ� ���� �Ҵ��ϴ� ���� �Լ� �������� ������ ��ġ�Ƿ� ȣ���ڿ��� ���� ������ ���޵��� �ʽ��ϴ�.
������ �Ű����� ����: �Լ� ���ڷ� ���޵� ������ dest�� �Լ� ������ ���� ����ó�� ��޵˴ϴ�.
�Ҵ� ȿ�� ����: �Լ����� dest�� src�� �Ҵ��ϴ� ���� 
�ش� �Լ��� ���� ���������� ������ �ְ� �Լ� �ۿ��� ������ ���� �ʽ��ϴ�

�����͸� �Լ����� �����Ϸ��� �ش� �������� �ּҸ� �����ؾ� �մϴ�.
���� �������� �����͸� �Ű������� ����ؾ� �մϴ�.
*/
void shallow_copy1(char* dest, char* src) {
    dest = src; // ������ ���縸 �����ϳ�, ���� �������� ������ ��
}


// ���� ���� �Լ�
void deep_copy(char** dest, char* src) {
    *dest = (char*)malloc(strlen(src) + 1); // ���ο� �޸� �Ҵ�
    if (*dest != NULL) {
        strcpy(*dest, src); // ���� ������ �� �޸𸮷� ����
    }
}



int main0160() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // �迭�� ��ü ũ��� �� ����� ũ�⸦ ����Ͽ� ���̸� ���
    size_t length1 = sizeof(arr) / sizeof(arr[0]);

    arr[3] = 55;
    printf("�迭�� 3�ε����� %d\n", arr[3]);

    // �迭 ���� ���
    printf("�迭�� ����: %zu\n", length1);
    printf("�迭�� 1�ε����� %d\n", arr[1]);
    printf("�迭�� �ּ� %p\n", arr);
    printf("�迭�� �ּ� %p\n", &arr);
    printf("�迭�� 0�ε��� �ּ� %p\n", &arr[0]);


    //�迭�� ����
    // ���� �迭
    char str0[20] = "this is cprog";

    // ���� ����
    char* shallow = NULL;
    shallow_copy(&shallow, str0);

    // ���� ����
    char* deep = NULL;
    deep_copy(&deep, str0);

    // ���� �� ���
    printf("Original: %s\n", str0);
    printf("Shallow copy: %s\n", shallow);
    printf("Deep copy: %s\n", deep);

    // ���� �迭 ����
    strcpy(str0, "C programming");

    // ���� �� ���
    printf("\nAfter modifying original data:\n");
    printf("Original: %s\n", str0);
    printf("Shallow copy: %s\n", shallow); // ���� ����� ������ �Բ� �����
    printf("Deep copy: %s\n", deep); // ���� ����� ������ ������ ������

    // ���� ���� �޸� ����
    free(deep);




    //////////////////////////////////////////���ڿ�
    char str1[20] = "this is cprog";//char�迭�� 1byte���ڸ� ����

    printf("���ڿ��� 1�ε��� ����: %c\n", str1[1]);

    char source[] = "OpenAI";
    char destination[20];
    char greeting[50] = "Hello, ";

    // ���ڿ� ����
    strcpy(destination, source);//source���ڿ��� destination�� ����
    printf("Copied string: %s\n", destination);

    // ���ڿ� ����
    size_t length = strlen(source);// \0�� ������������ ����.
    printf("Length of source string: %zu\n", length);

    // ���ڿ� �̾���̱�
    strcat(greeting, source);
    printf("Concatenated string: %s\n", greeting);

    // ���ڿ� ��
    int cmp_result = strcmp("OpenAI", source);
    if (cmp_result == 0) {
        printf("Strings are identical\n");
    }
    else {
        printf("Strings are different\n");
    }


    //�����͹��ڿ�
    char* message = "Hello, World!";
    printf("���ڿ��� �ּ�: %p\n", message);
    printf("���ڿ��� ù��° ���� �ּ�: %p\n", &message[0]);
    printf("���ڿ��� ù��° ����: %c\n", message[0]);
    printf("���ڿ��� ù��° ����: %c\n", *message);

    printf("���ڿ��� 2��° ����: %c\n", *(message+1) );



    //�����͹迭

    int a = 10, b = 20, c = 30;
    int* ptrs[] = { &a, &b, &c }; // ������ �迭

    // �迭�� ũ�� ���
    size_t length2 = sizeof(ptrs) / sizeof(ptrs[0]);

    // �� ������ �迭 ��Ҹ� ���� �� ���
    for (size_t i = 0; i < length2; i++) {
        printf("Value at ptrs[%zu]: %d\n", i, *ptrs[i]);
    }

    //���ڿ� �迭(������ �迭)
    const char* fruits[] = { "Apple", "Banana", "Cherry", "Date" };
    size_t num_fruits = sizeof(fruits) / sizeof(fruits[0]);

    for (size_t i = 0; i < num_fruits; i++) {
        printf("Fruit %zu: %s\n", i + 1, fruits[i]);
    }



    ///����ü ������
 
    Student alice = { "Alice", 20, 3.5 };

    // ����ü ������ ���� �� �ʱ�ȭ
    Student* ptr = &alice;

    // ����ü ����� ���� (������ ���)
    
    printf("Name: %s\n", (*ptr).name);
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("GPA: %.2f\n", ptr->gpa);

    // ����ü ��� �� ����
    ptr->age = 21;
    printf("Updated Age: %d\n", alice.age);





	return 0;
}