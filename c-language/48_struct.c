#define _CRT_SECURE_NO_WARNINGS // strcpy 보안 경고 무시
#include <stdio.h>
#include <string.h>

struct Dashboard {
    int speed;
    char fuel;
    float mileage;
    int engineTemp;
    int rpm;
};

struct Student {
    char name[50];
    int age;
    float grade;
};

int main48()
{
    struct Dashboard d1 = { 80,'F', 5821.442871f ,200,1830 };
    

    printf("Speed: %dkm/h\n", d1.speed);
    printf("Fuel: %c\n", d1.fuel);
    printf("Mileage: %fkm\n", d1.mileage);
    printf("Engine temp: %d℃\n", d1.engineTemp);
    printf("RPM: %d\n", d1.rpm);



    struct Student std1 = { "John", 20, 85.5 };
    struct Student std2;

    std2.age = 22;
    strcpy(std2.name, "Alice");
    std2.grade = 90.5;

    printf("std1의 이름: %s\n", std1.name);
    printf("std2의 성적: %.2f\n", std2.grade);

    return 0;
}