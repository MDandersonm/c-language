#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>// ǥ�������
#include <stdlib.h>//exit malloc
#include <string.h>

int main150() {
	
	int* b;
	//b = (int*)malloc(5, sizeof(int));// �����Ͽ���
	b = (int*)malloc(5* sizeof(int));

	int* a;
	a = (int*)calloc(5, sizeof(int)); //int�� ũ���� �������� 5�� �Ҵ�
	a = (int*)realloc(a, 10 * sizeof(int));// �����߰��� �޸𸮿����� �ʱ�ȭ��������

	// ���Ӱ� �Ҵ�� ������ 0���� �ʱ�ȭ
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
	stat1 = memcmp(s1, s2, 3); //s1,s2�޸𸮰����� ���ϴµ� 3����Ʈ��ŭ
	printf("%d\n", stat1); //s1>s2 �� ��� �ݴ�� ���� ������ 0

	/*
ù ��° ����Ʈ ��:
'a' (97) vs 'b' (98)
���: 97 - 98 = -1
��� �ؼ�:
memcmp�� ù ��° ����Ʈ�� �ٸ��� �� ��� �񱳸� �����ϰ� ����� ��ȯ�մϴ�.
memcmp(s1, s2, 3)�� ��ȯ���� -1�̹Ƿ�, s1�� s2���� �۽��ϴ�.
	*/
	

	char src2[] = "1234567890";
	char dest2[] = "askidhoasdhozsxzc";
	char* stat2;
	printf("memcpy()�� ���� �� dest�� ������ : %s\n", dest2);
	// src���� strlen(src)����Ʈ��ŭ dest�� ����)
	stat2 = (char*)memcpy(dest2, src2, strlen(src2));

	if (stat2) {
		printf("memcpy()������ dest�� ������: %s\n", dest2);

	}
	else
		printf("�������\n");




	char s3[] = "1230567890";
	printf("memset()�������� s3������ : %s\n", s3);
	// memset�Լ�: ������ s3�� ����Ű�°��� '*'������ strlen(s3) byte��ŭ ä���
	memset(s3, '*', strlen(s3));
	printf("memset()�������� s3������ : %s\n", s3);




	return 0;
}