#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// 표준입출력
#include <stdlib.h>//exit
#include <string.h>



//fwrite(저장자료변수, 레코드길이, 레코드개수, 파일포인터)
int main140() {
	char name[10];
	FILE* fp;
	fp = fopen("sample4.txt", "wb");//랜덤파일은 바이너리파일로
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}
	gets(name);

	//stcmp: 사전순 비교 양수면 앞에것이 사전순으로 뒤
	//0이면 두 단어가 같아서 0반환되면 false역할로 while이 멈춤
	//음수 양수 모두 true이다.
	while (strcmp(name, "end")) {//endoffile
		//strcat :두문자를 이어붙임
		fwrite(name,10,1, fp);
		gets(name);
	}
	fclose(fp);
	return 0;
}

//fread(읽을 자료변수, 레코드길이, 레코드개수, 파일포인터)
//읽기에 성공하면 읽은 레코드 수를 리턴
//puts:표준출력
int main141() {
	char name[10];
	FILE* fp;
	fp = fopen("sample4.txt", "rb");//랜덤파일은 바이너리파일로
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}
	while (1) {//endoffile
		if (fread(name, 10, 1, fp) != 1)
			break;
		puts(name);
	}
	fclose(fp);
	return 0;
}


/*

변경 전: fwrite(name, 10, 1, fp)는 name 배열을 한 번만 파일에 기록.
예를 들어 name이 "hello"일 경우 파일에 기록된 내용은 hello\0\0\0\0\0입니다.
변경 후: fwrite(name, 10, 5, fp)는 name 배열을 5번 반복해서 파일에 기록.
예를 들어 name이 "hello"일 경우 파일에 기록된 내용은 hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0입니다.

*/



//fseek 파일포인터를 ㅣㅁ의의 위치로 이동시키는 함수 . 랜덤파일의 특정부분을 입출력할수있따.
//fseek(파일포인터변수,이동할상대위치, 기준위치를 저장하는모드);
//기준위치로부터 앞 ,뒤로 이동하는 상대위치 개념 사용
//SEEK_SET SEEK_CUR SEEK_END


int main142() {
	char str[10];
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample6.txt", "wt");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}
	fputs("1234567890", fp);
	fclose(fp);
	


	fp = fopen("sample6.txt", "rt");

	fseek(fp, 7, SEEK_SET); //맨앞
	fgets(str, 4, fp);
	printf("7번째부터 3글자 출력 : %s \n", str);//890


	fseek(fp, -2, SEEK_CUR); //현재위치 :0 다음
	fgets(str, 3, fp);
	printf("현재위치에서 앞에 2글자부터 2글자출력: %s \n", str);//90



	fseek(fp, -9, SEEK_END); //맨뒤
	fgets(str, 6, fp);
	printf("맨 뒤에서 9번째 앞부터 5글자 출력 : %s \n", str);//23456



	fclose(fp);
	return 0;
}
// 1234567890\0