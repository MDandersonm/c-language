#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// ǥ�������
#include <stdlib.h>//exit
#include <string.h>



//fwrite(�����ڷắ��, ���ڵ����, ���ڵ尳��, ����������)
int main140() {
	char name[10];
	FILE* fp;
	fp = fopen("sample4.txt", "wb");//���������� ���̳ʸ����Ϸ�
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}
	gets(name);

	//stcmp: ������ �� ����� �տ����� ���������� ��
	//0�̸� �� �ܾ ���Ƽ� 0��ȯ�Ǹ� false���ҷ� while�� ����
	//���� ��� ��� true�̴�.
	while (strcmp(name, "end")) {//endoffile
		//strcat :�ι��ڸ� �̾����
		fwrite(name,10,1, fp);
		gets(name);
	}
	fclose(fp);
	return 0;
}

//fread(���� �ڷắ��, ���ڵ����, ���ڵ尳��, ����������)
//�б⿡ �����ϸ� ���� ���ڵ� ���� ����
//puts:ǥ�����
int main141() {
	char name[10];
	FILE* fp;
	fp = fopen("sample4.txt", "rb");//���������� ���̳ʸ����Ϸ�
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
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

���� ��: fwrite(name, 10, 1, fp)�� name �迭�� �� ���� ���Ͽ� ���.
���� ��� name�� "hello"�� ��� ���Ͽ� ��ϵ� ������ hello\0\0\0\0\0�Դϴ�.
���� ��: fwrite(name, 10, 5, fp)�� name �迭�� 5�� �ݺ��ؼ� ���Ͽ� ���.
���� ��� name�� "hello"�� ��� ���Ͽ� ��ϵ� ������ hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0hello\0\0\0\0\0�Դϴ�.

*/



//fseek ���������͸� �Ӥ����� ��ġ�� �̵���Ű�� �Լ� . ���������� Ư���κ��� ������Ҽ��ֵ�.
//fseek(���������ͺ���,�̵��һ����ġ, ������ġ�� �����ϴ¸��);
//������ġ�κ��� �� ,�ڷ� �̵��ϴ� �����ġ ���� ���
//SEEK_SET SEEK_CUR SEEK_END


int main142() {
	char str[10];
	FILE* fp;//���������� (�������ϰ� ���α׷��� ������ �ִ� ���)
	fp = fopen("sample6.txt", "wt");
	if (fp == NULL) {
		printf("������ �����Ҽ�����");
		exit(1);
	}
	fputs("1234567890", fp);
	fclose(fp);
	


	fp = fopen("sample6.txt", "rt");

	fseek(fp, 7, SEEK_SET); //�Ǿ�
	fgets(str, 4, fp);
	printf("7��°���� 3���� ��� : %s \n", str);//890


	fseek(fp, -2, SEEK_CUR); //������ġ :0 ����
	fgets(str, 3, fp);
	printf("������ġ���� �տ� 2���ں��� 2�������: %s \n", str);//90



	fseek(fp, -9, SEEK_END); //�ǵ�
	fgets(str, 6, fp);
	printf("�� �ڿ��� 9��° �պ��� 5���� ��� : %s \n", str);//23456



	fclose(fp);
	return 0;
}
// 1234567890\0