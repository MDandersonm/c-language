#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main2() {
	// 정수형 변수 선언
	int a = 10;

	// 포인터 변수 선언
	int* p;

	// 포인터 변수에 정수형 변수의 주소 할당
	p = &a;

	// 포인터 변수를 통해 정수형 변수의 값 출력
	printf("p의 값: %d\n", *p);

	// 포인터 변수를 통해 정수형 변수의 값 변경
	*p = 20;

	// 정수형 변수의 값 출력
	printf("a의 값: %d\n", a);

	//int p = 11; 불가능
	//printf("정수형 변수 p의 값: %d\n", p);

	printf("a의 주소: %p\n", &a);
	printf("p이 가리키는 값: %d\n", *p);//a값이 출력됨
	printf("p의 값: %p\n", p);//a의 주소가 출력됨

	//a의주소값이 출려됨
	printf("p의 값(a의 주소값) : %p\n", (void*)p);

	return 0;
}



int main3()
{
	int* numPtr1;
	int** numPtr2;
	int num1;

	scanf("%d", &num1);
	numPtr1 = &num1;
	numPtr2 = &numPtr1;

	printf("%d\n", **numPtr2);

	return 0;
}

int main4() {
	// 정수형 배열 선언
	int arr[5] = { 10, 20, 30, 40, 50 };

	// 포인터 변수 선언
	int* p;

	// 포인터 변수에 배열의 주소 할당
	p = arr;

	// 포인터 변수를 통해 배열의 요소 값 출력
	for (int i = 0; i < 5; i++) {
		printf("p[%d]의 값: %d\n", i, *(p + i));
	}

	return 0;
}


int main5() {
	int a = 10;
	int* ptr1 = &a;
	int** ptr2 = &ptr1;

	printf("a의 값: %d\n", a);
	printf("a의 주소: %p\n", &a);
	printf("ptr1이 가리키는 값: %d\n", *ptr1);
	printf("ptr1의 값: %p\n", ptr1);
	printf("ptr2이 가리키는 값: %p\n", *ptr2);
	printf("ptr2의 값: %p\n", ptr2);

	return 0;
}


int main6() {
	int num = 10;
	int* numpt1;
	int** numpt2;

	//*numpt1 = num;
	numpt1 = &num;
	numpt2 = &numpt1;

	printf("%p\n", numpt2);

	return 0;
}

#include <stdlib.h> //malloc 포함
int main7()
{
	int num1;
	int num2;

	scanf_s("%d %d", &num1, &num2);
	
	int* numPtr1 = (int*)malloc(sizeof(int));
	int* numPtr2 = (int*)malloc(sizeof(int));

	*numPtr1 = num1;
	*numPtr2 = num2;

	printf("%d\n", *numPtr1 + *numPtr2);

	free(numPtr1);
	free(numPtr2);

	return 0;
}


int main8() {

	char str[] = "Beethoven\n9th\nSymphony";  // 문자 배열로 문자열을 저장
	printf("%s\n", str);

	char s1[10];    // 크기가 10인 char형 배열을 선언

	printf("문자열을 입력하세요: ");
	scanf("%s", s1);     // 표준 입력을 받아서 배열 형태의 문자열에 저장
	// & (주소 연산자)를 사용하지 않는 이유는 문자열 이름 자체가 해당 문자열의 시작 주소를 나타내기 때문입니다.
	//배열 이름, 예를 들면 s1,은 배열의 첫 번째 원소의 주소를 나타냅니다. 따라서 s1는 &s1[0]과 동일한 주소값을 가집니다.

	printf("%s\n", s1);  // 문자열의 내용을 출력


	//scanf 함수에서 서식 지정자를 "%[^\n]s"와 같이 지정하면 공백까지 포함하여 문자열을 입력받을 수 있습니다.
	char s2[30];

	printf("공백을 포함한 문자열을 입력하세요: ");
	scanf("%[^\n]s", s2);    // 공백까지 포함하여 문자열 입력받기

	printf("%s\n", s2);

}


int main9() {

	char s22[10] = "Hello";    // 문자 배열에 문자열 리터럴 할당(배열에 문자열이 복사됨)
	s22[0] = 'A';              // 문자를 변경할 수 있음


	while (getchar() != '\n'); // 버퍼 비우기 //입력을 받게되는 현상이 일어나게된다.
	char* s31 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당
	scanf("%s", s31);    // 표준 입력을 받아서 배열 형태의 문자열에 저장
	printf("%s\n", s31);
	free(s31);    // 동적 메모리 해제
	//printf("%s\n", s31);//동적메모리 해제후 쓰이면 안됨

}


#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main10()
{
	char str[] = "Beethoven\n9th\nSymphony";  // 문자 배열로 문자열을 저장
	printf("%s\n", str);

	char s1[10];    // 크기가 10인 char형 배열을 선언

	printf("문자열을 입력하세요: ");
	scanf("%s", s1);     // 표준 입력을 받아서 배열 형태의 문자열에 저장
	// & (주소 연산자)를 사용하지 않는 이유는 문자열 이름 자체가 해당 문자열의 시작 주소를 나타내기 때문입니다.
	//배열 이름, 예를 들면 s1,은 배열의 첫 번째 원소의 주소를 나타냅니다. 따라서 s1는 &s1[0]과 동일한 주소값을 가집니다.

	printf("%s\n", s1);  // 문자열의 내용을 출력


	/*
	getchar()는 C 표준 라이브러리 함수로, 표준 입력(대부분 키보드)에서 한 문자를 읽어들이는 기능을 합니다. 읽어들인 문자를 반환합니다.
while (getchar() != '\n'); 구문은 표준 입력 버퍼에 남아 있는 문자들을 순차적으로 읽어들이면서, 개행 문자('\n')를 만날 때까지 계속 반복하는 것을 의미합니다.
여기서 '\n'은 개행 문자로, 보통 Enter 키를 눌렀을 때 입력되는 문자입니다.
이 구문의 주요 용도는 이전의 입력에서 버퍼에 남아있는 문자들, 특히 개행 문자를 제거하기 위해서 사용됩니다.
scanf와 같은 함수로 입력을 받을 때, 입력의 끝을 알리는 Enter 키를 누르면, 입력된 데이터와 함께 개행 문자도 버퍼에 남게 됩니다.
이 후의 scanf나 다른 입력 함수들이 그 개행 문자를 바로 읽어서 원치 않는 동작을 할 수 있기 때문에, 이를 방지하기 위해 버퍼를 비워주는 역할로 while (getchar() != '\n');를 사용하는 것입니다.
	*/

	while (getchar() != '\n'); // 버퍼 비우기




	//scanf 함수에서 서식 지정자를 "%[^\n]s"와 같이 지정하면 공백까지 포함하여 문자열을 입력받을 수 있습니다.
	char s2[30];

	printf("공백을 포함한 문자열을 입력하세요: ");
	scanf("%[^\n]s", s2);    // 공백까지 포함하여 문자열 입력받기

	printf("%s\n", s2);



	char* s11 = "Hello, world!";       // char 포인터에 문자열의 메모리 주소를 저장
	char s12[20] = "Hello, world!";    // char 배열에 문자열 저장
	char s13[] = "Hello, world!";      // char 배열에 문자열 저장(배열의 크기 생략)

	//이미 선언된 배열에는 문자열을 할당할 수 없습니다.

	//문자열 포인터에 문자열 리터럴을 할당한 뒤에는 인덱스로 접근하여 문자(요소)를 변경할 수 없습니다(문자열 리터럴이 있는 메모리 주소는 읽기 전용). 
	// 하지만 문자 배열은 인덱스로 접근하여 문자를 변경할 수 있습니다(배열에 문자열이 복사됨).
	//char* s1 = "Hello";       // 문자열 포인터에 문자열 리터럴 할당(읽기 전용 메모리를 가리킴)
   // s1[0] = 'A';              // 실행 에러: 문자를 변경할 수 없음

	char s22[10] = "Hello";    // 문자 배열에 문자열 리터럴 할당(배열에 문자열이 복사됨)
	s22[0] = 'A';              // 문자를 변경할 수 있음


	while (getchar() != '\n'); // 버퍼 비우기
	char* s31 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당
	scanf("%s", s31);    // 표준 입력을 받아서 배열 형태의 문자열에 저장
	printf("%s\n", s31);
	free(s31);    // 동적 메모리 해제

	//메모리 해제 후 접근: free(s31); 뒤에 printf("%s\n", s31);로 메모리에 접근하고 있습니다. 
	// 메모리를 해제한 후 그 메모리 영역에 접근하면 정의되지 않은 동작이 발생할 수 있습니다.
	//  따라서 메모리를 해제한 후에는 그 메모리 영역에 접근하면 안 됩니다.
	//printf("%s\n", s31);//메모리 해제 후 쓰면 안됨

	return 0;
}
int main11() {
	char ss3[10];
	//ss3 = "nice";
	printf("%s\n", ss3);

	return 0;
}


#include <stdio.h>
#include <string.h>    // strchr 함수가 선언된 헤더 파일

int main12()
{
	char s1[30] = "A Garden Diary";  // 크기가 30인 char형 배열을 선언하고 문자열 할당

	char* ptr = strchr(s1, 'a');     // 'a'로 시작하는 문자열 검색, 포인터 반환

	while (ptr != NULL)              // 검색된 문자열이 없을 때까지 반복
	{
		printf("%s\n", ptr);         // 검색된 문자열 출력
		printf("주소:%p\n", ptr);
		//printf("%s\n", *ptr);  //틀림
		ptr = strchr(ptr + 1, 'a');  // 포인터에 1을 더하여 a 다음부터 검색
	}

	return 0;
}//여기서 ptr은 주소인데% p로 출력해야맞지않냐 ?

#include <stdio.h>
#include <stdlib.h>

struct Data {
	char c1;
	int* numPtr;    // 포인터
};

int main13()
{
	int num1 = 10;
	struct Data d1;    // 구조체 변수
	struct Data* d2 = malloc(sizeof(struct Data));    // 구조체 포인터에 메모리 할당

	d1.numPtr = &num1;
	d2->numPtr = &num1;
	//(*d2).numPtr = &num1; //위와같음
	d2->c1 = 20;

	printf("%p\n", d1.numPtr);
	printf("%p\n", d2->numPtr);
	printf("%d\n", (*d2).c1);
	printf("%d\n", d2->c1);
	printf("%p\n", &(d1.numPtr));//numPtr의 주소
	printf("%p\n", &(d2->numPtr));
	printf("%d\n", *d1.numPtr);     // 10: 구조체의 멤버를 역참조


	free(d2);
};