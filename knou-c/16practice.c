#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int age;
    float gpa;
} Student;

// 얕은 복사 함수
void shallow_copy(char** dest, char* src) {
    *dest = src; // 포인터 복사만 수행
}

/*
코드에서 shallow_copy1 함수는 두 개의 포인터 매개변수를 받지만, 
실제로 dest 포인터에 값을 할당하는 것은 함수 내에서만 영향을 미치므로 호출자에게 변경 사항이 전달되지 않습니다.
포인터 매개변수 복사: 함수 인자로 전달된 포인터 dest는 함수 내에서 로컬 변수처럼 취급됩니다.
할당 효과 없음: 함수에서 dest에 src를 할당하는 것은 
해당 함수의 지역 범위에서만 영향을 주고 함수 밖에는 영향을 주지 않습니다

포인터를 함수에서 변경하려면 해당 포인터의 주소를 전달해야 합니다.
따라서 포인터의 포인터를 매개변수로 사용해야 합니다.
*/
void shallow_copy1(char* dest, char* src) {
    dest = src; // 포인터 복사만 수행하나, 지역 변수에만 영향을 줌
}


// 깊은 복사 함수
void deep_copy(char** dest, char* src) {
    *dest = (char*)malloc(strlen(src) + 1); // 새로운 메모리 할당
    if (*dest != NULL) {
        strcpy(*dest, src); // 원본 내용을 새 메모리로 복사
    }
}



int main0160() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 배열의 전체 크기와 각 요소의 크기를 사용하여 길이를 계산
    size_t length1 = sizeof(arr) / sizeof(arr[0]);

    arr[3] = 55;
    printf("배열의 3인덱스값 %d\n", arr[3]);

    // 배열 길이 출력
    printf("배열의 길이: %zu\n", length1);
    printf("배열의 1인덱스값 %d\n", arr[1]);
    printf("배열의 주소 %p\n", arr);
    printf("배열의 주소 %p\n", &arr);
    printf("배열의 0인덱스 주소 %p\n", &arr[0]);


    //배열의 복사
    // 원본 배열
    char str0[20] = "this is cprog";

    // 얕은 복사
    char* shallow = NULL;
    shallow_copy(&shallow, str0);

    // 깊은 복사
    char* deep = NULL;
    deep_copy(&deep, str0);

    // 복사 후 출력
    printf("Original: %s\n", str0);
    printf("Shallow copy: %s\n", shallow);
    printf("Deep copy: %s\n", deep);

    // 원본 배열 수정
    strcpy(str0, "C programming");

    // 수정 후 출력
    printf("\nAfter modifying original data:\n");
    printf("Original: %s\n", str0);
    printf("Shallow copy: %s\n", shallow); // 얕은 복사는 원본과 함께 변경됨
    printf("Deep copy: %s\n", deep); // 깊은 복사는 원본과 별도로 유지됨

    // 깊은 복사 메모리 해제
    free(deep);




    //////////////////////////////////////////문자열
    char str1[20] = "this is cprog";//char배열은 1byte문자만 지원

    printf("문자열의 1인덱스 문자: %c\n", str1[1]);

    char source[] = "OpenAI";
    char destination[20];
    char greeting[50] = "Hello, ";

    // 문자열 복사
    strcpy(destination, source);//source문자열을 destination에 복사
    printf("Copied string: %s\n", destination);

    // 문자열 길이
    size_t length = strlen(source);// \0을 포함하지않은 길이.
    printf("Length of source string: %zu\n", length);

    // 문자열 이어붙이기
    strcat(greeting, source);
    printf("Concatenated string: %s\n", greeting);

    // 문자열 비교
    int cmp_result = strcmp("OpenAI", source);
    if (cmp_result == 0) {
        printf("Strings are identical\n");
    }
    else {
        printf("Strings are different\n");
    }


    //포인터문자열
    char* message = "Hello, World!";
    printf("문자열의 주소: %p\n", message);
    printf("문자열의 첫번째 문자 주소: %p\n", &message[0]);
    printf("문자열의 첫번째 문자: %c\n", message[0]);
    printf("문자열의 첫번째 문자: %c\n", *message);

    printf("문자열의 2번째 문자: %c\n", *(message+1) );



    //포인터배열

    int a = 10, b = 20, c = 30;
    int* ptrs[] = { &a, &b, &c }; // 포인터 배열

    // 배열의 크기 계산
    size_t length2 = sizeof(ptrs) / sizeof(ptrs[0]);

    // 각 포인터 배열 요소를 통해 값 출력
    for (size_t i = 0; i < length2; i++) {
        printf("Value at ptrs[%zu]: %d\n", i, *ptrs[i]);
    }

    //문자열 배열(포인터 배열)
    const char* fruits[] = { "Apple", "Banana", "Cherry", "Date" };
    size_t num_fruits = sizeof(fruits) / sizeof(fruits[0]);

    for (size_t i = 0; i < num_fruits; i++) {
        printf("Fruit %zu: %s\n", i + 1, fruits[i]);
    }



    ///구조체 포인터
 
    Student alice = { "Alice", 20, 3.5 };

    // 구조체 포인터 선언 및 초기화
    Student* ptr = &alice;

    // 구조체 멤버에 접근 (포인터 사용)
    
    printf("Name: %s\n", (*ptr).name);
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("GPA: %.2f\n", ptr->gpa);

    // 구조체 멤버 값 수정
    ptr->age = 21;
    printf("Updated Age: %d\n", alice.age);





	return 0;
}