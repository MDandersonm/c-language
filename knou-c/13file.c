#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// 표준입출력
#include <stdlib.h>//exit
#include <string.h>


//순차파일 출력함수
// putc(문자변수, 파일포인터변수)  == fputc(문자변수, 파일포인터변수) 
// //fputs(문자열변수, 파일포인터변수)  fprintf(파일포인터변수,"출력형식" ,변수)


//순차파일 입력함수
//  getc(파일포인터변수)  == fgetc(파일포인터변수)
//  fgets(문자열변수,문자열길이(\0포함길이) ,파일포인터변수 ) fscanf(파일포인터변수,"입력형식",변수)

//표준출력 c=putchar()      puts(변수명)
//표준입력 c=getchar()      gets(변수명)


int main130() {
	char ch;
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample.txt", "w");
	for (ch = 'A'; ch <= 'Z'; ch++) {
		fputc(ch, fp);

	}
	fclose(fp);
	return 0;
}


//모니터에 표준입력을 getchar로 받아서 putc로 파일에 출력
int main131() {
	char c;
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample1.txt", "w");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}

	while ((c = getchar()) != EOF) {//endoffile
		putc(c, fp);
	}
	fclose(fp);
	return 0;
}


//모니터에 표준입력을 gets로 받아서 파일에 fputs로 입력
int main132() {
	char name[64];
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample2.txt", "w");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}
	gets(name);

	//stcmp: 사전순 비교 양수면 앞에것이 사전순으로 뒤
	//0이면 두 단어가 같아서 0반환되면 false역할로 while이 멈춤
	//음수 양수 모두 true이다.
	while (strcmp(name,"end")) {//endoffile
		//strcat :두문자를 이어붙임
		strcat(name, "\n"); //하나의 문자열에 다른것(\n) 을 추가되서 저장됨.
		fputs(name, fp);
		gets(name);
	}
	fclose(fp);
	return 0;
}


//getc로 파일읽어서  putchar로 모니터에 표준출력
int main133() {
	char c;
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample1.txt", "r");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}

	while ((c=getc(fp))!= EOF) {//endoffile 더 이상 읽을 데이터가 없을 때(즉, 파일의 끝에 도달했을 때) getc는 EOF를 반환합
		putchar(c);
	}
	fclose(fp);
	return 0;
}


//fgets로 파일을 읽어서 표준출력
int main134() {
	char name[20];//\0을 포함해서 20글자.
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample1.txt", "r");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}

	while (fgets(name,20,fp) !=NULL) {
		printf("%s", name);
		//puts(name);//\n이 추가되는문제가생김
	}
	fclose(fp);
	return 0;
}

//scanf로 표준입력받아서 fprintf로 파일에 입력

int main135() {
	char no[10], name[10];
	int mid, term, rep, att, i;
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample2.txt", "w");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}

	//stdout: 모니터를 가리키는 특수한 파일포인터
	fprintf(stdout, "학번 이름 중간 기말 레포트 출석 점수를 입력\n");


	for (i = 0; i < 2; i++) {
		scanf("%s %s %d %d %d %d", no, name, &mid, &term, &rep, &att);
		fprintf(fp, "%10s %8s %3d %3d %3d %3d\n", no, name, mid, term, rep, att);
	}

	fclose(fp);
	return 0;
}
//fscanf로 파일에서 가져와서 printf로 모니터에 표준출력


int main136() {
	char no[10], name[10];
	int mid, term, rep, att, i;
	FILE* fp;//파일포인터 (실제파일과 프로그램을 연결해 주는 통로)
	fp = fopen("sample2.txt", "r");
	if (fp == NULL) {
		printf("파일을 개방할수없음");
		exit(1);
	}

	printf("학번 이름 중간 기말 레포트 출석 점수를 입력\n");


	while(!feof(fp)){
		fscanf(fp, "%10s %8s %3d %3d %3d %3d\n", no, name, &mid, &term, &rep, &att);
		printf("%-10s %-8s %4d %4d %4d %4d\n", no, name, mid, term, rep, att);
		
	}

	fclose(fp);
	return 0;
}



 