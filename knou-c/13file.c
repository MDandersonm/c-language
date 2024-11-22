#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// ǥ�������
#include <stdlib.h>//exit
#include <string.h>


//�������� ����Լ�
// putc(���ں���, ���������ͺ���)  == fputc(���ں���, ���������ͺ���) 
// //fputs(���ڿ�����, ���������ͺ���)  fprintf(���������ͺ���,"�������" ,����)


//�������� �Է��Լ�
//  getc(���������ͺ���)  == fgetc(���������ͺ���)
//  fgets(���ڿ�����,���ڿ�����(\0���Ա���) ,���������ͺ��� ) fscanf(���������ͺ���,"�Է�����",����)

//ǥ����� c=putchar()      puts(������)
//ǥ���Է� c=getchar()      gets(������)


int main130() {
	char ch;
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample.txt", "w");
	for (ch = 'A'; ch <= 'Z'; ch++) {
		fputc(ch, fp);

	}
	fclose(fp);
	return 0;
}


//����Ϳ� ǥ���Է��� getchar�� �޾Ƽ� putc�� ���Ͽ� ���
int main131() {
	char c;
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample1.txt", "w");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}

	while ((c = getchar()) != EOF) {//endoffile
		putc(c, fp);
	}
	fclose(fp);
	return 0;
}


//����Ϳ� ǥ���Է��� gets�� �޾Ƽ� ���Ͽ� fputs�� �Է�
int main132() {
	char name[64];
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample2.txt", "w");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}
	gets(name);

	//stcmp: ������ �� ����� �տ����� ���������� ��
	//0�̸� �� �ܾ ���Ƽ� 0��ȯ�Ǹ� false���ҷ� while�� ����
	//���� ��� ��� true�̴�.
	while (strcmp(name,"end")) {//endoffile
		//strcat :�ι��ڸ� �̾����
		strcat(name, "\n"); //�ϳ��� ���ڿ��� �ٸ���(\n) �� �߰��Ǽ� �����.
		fputs(name, fp);
		gets(name);
	}
	fclose(fp);
	return 0;
}


//getc�� �����о  putchar�� ����Ϳ� ǥ�����
int main133() {
	char c;
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample1.txt", "r");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}

	while ((c=getc(fp))!= EOF) {//endoffile �� �̻� ���� �����Ͱ� ���� ��(��, ������ ���� �������� ��) getc�� EOF�� ��ȯ��
		putchar(c);
	}
	fclose(fp);
	return 0;
}


//fgets�� ������ �о ǥ�����
int main134() {
	char name[20];//\0�� �����ؼ� 20����.
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample1.txt", "r");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}

	while (fgets(name,20,fp) !=NULL) {
		printf("%s", name);
		//puts(name);//\n�� �߰��Ǵ¹���������
	}
	fclose(fp);
	return 0;
}

//scanf�� ǥ���Է¹޾Ƽ� fprintf�� ���Ͽ� �Է�

int main135() {
	char no[10], name[10];
	int mid, term, rep, att, i;
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample2.txt", "w");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}

	//stdout: ����͸� ����Ű�� Ư���� ����������
	fprintf(stdout, "�й� �̸� �߰� �⸻ ����Ʈ �⼮ ������ �Է�\n");


	for (i = 0; i < 2; i++) {
		scanf("%s %s %d %d %d %d", no, name, &mid, &term, &rep, &att);
		fprintf(fp, "%10s %8s %3d %3d %3d %3d\n", no, name, mid, term, rep, att);
	}

	fclose(fp);
	return 0;
}
//fscanf�� ���Ͽ��� �����ͼ� printf�� ����Ϳ� ǥ�����


int main136() {
	char no[10], name[10];
	int mid, term, rep, att, i;
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample2.txt", "r");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}

	printf("�й� �̸� �߰� �⸻ ����Ʈ �⼮ ������ �Է�\n");


	while(!feof(fp)){
		fscanf(fp, "%10s %8s %3d %3d %3d %3d\n", no, name, &mid, &term, &rep, &att);
		printf("%-10s %-8s %4d %4d %4d %4d\n", no, name, mid, term, rep, att);
		
	}

	fclose(fp);
	return 0;
}



 