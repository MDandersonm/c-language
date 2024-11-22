#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// 표준입출력
#include <stdlib.h>//exit malloc
#include <string.h>

int main150() {
	
	int* b;
	//b = (int*)malloc(5, sizeof(int));// 컴파일에러
	b = (int*)malloc(5* sizeof(int));

	int* a;
	a = (int*)calloc(5, sizeof(int)); //int형 크기의 기억공간을 5개 할당
	a = (int*)realloc(a, 10 * sizeof(int));// 새로추가된 메모리영역은 초기화되지않음

	// 새롭게 할당된 영역을 0으로 초기화
	for (int i = 5; i < 10; i++) {
		a[i] = 0;
	}


	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
			
	}
	free(a);
	free(b);


	return 0;
}

int main151() {

	char* s1 = "aaa";
	char* s2 = "bbb";
	int stat1;
	stat1 = memcmp(s1, s2, 3); //s1,s2메모리공간을 비교하는데 3바이트만큼
	printf("%d\n", stat1); //s1>s2 면 양수 반대는 음수 같으면 0

	/*
첫 번째 바이트 비교:
'a' (97) vs 'b' (98)
결과: 97 - 98 = -1
결과 해석:
memcmp는 첫 번째 바이트가 다르면 그 즉시 비교를 종료하고 결과를 반환합니다.
memcmp(s1, s2, 3)의 반환값은 -1이므로, s1이 s2보다 작습니다.
	*/
	

	char src2[] = "1234567890";
	char dest2[] = "askidhoasdhozsxzc";
	char* stat2;
	printf("memcpy()가 실행 전 dest의 데이터 : %s\n", dest2);
	// src에서 strlen(src)바이트만큼 dest에 복사)
	stat2 = (char*)memcpy(dest2, src2, strlen(src2));

	if (stat2) {
		printf("memcpy()실행후 dest의 데이터: %s\n", dest2);

	}
	else
		printf("복사실패\n");




	char s3[] = "1230567890";
	printf("memset()실행전의 s3데이터 : %s\n", s3);
	// memset함수: 포인터 s3가 가리키는곳을 '*'값으로 strlen(s3) byte만큼 채운다
	memset(s3, '*', strlen(s3));
	printf("memset()실행후의 s3데이터 : %s\n", s3);




	return 0;
}