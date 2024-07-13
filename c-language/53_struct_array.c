#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main53() {
    struct Student students[5];
    struct Student* studentPointers[5];

    // 구조체 배열 사용 예제
    strcpy(students[0].name, "John");
    students[0].age = 20;
    students[0].grade = 85.5;
    printf("Student name from array: %s\n", students[0].name);

    // 구조체 포인터 배열 및 메모리 할당 예제
    for (int i = 0; i < 5; i++) {
        studentPointers[i] = (struct Student*)malloc(sizeof(struct Student));
    }

    strcpy(studentPointers[0]->name, "Alice");
    studentPointers[0]->age = 22;
    studentPointers[0]->grade = 90.5;
    printf("Student name from pointer array: %s\n", studentPointers[0]->name);

    // 메모리 해제
    for (int i = 0; i < 5; i++) {
        free(studentPointers[i]);
    }

    return 0;
}
