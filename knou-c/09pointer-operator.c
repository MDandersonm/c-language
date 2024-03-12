#include <stdio.h>

void main09() {
	int* p;
	int a[] = { 10,20,30,40,50 };
	p = &a[0];

	//++가 *보다 먼저
	
	printf("*p == %d\n", *p);
	printf("*p++ == %d\n", *p++);// 10으로 출력하고 한칸옆으로가서 *p는 20이됨
	printf("*++p == %d\n", *++p); // p를 한칸 옆으로하고 *역참조 하면 30
	printf("++*p == %d\n", ++*p); // *역참조하고 1증가후 출력.
	printf("(*p)++ == %d\n", (*p)++); // 역참조하고 출력후, 1증가
	printf("*p == %d\n", *p);

	p = p + 2; //두칸이동 *p는 50
	printf("*p+2 == %d\n", *p + 2); //주의 
}