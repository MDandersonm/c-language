#include <stdio.h>
#pragma warning(disable:4996)

void main03() {
	int jsu1,jsu2;
	float ssu1;
	scanf("%d %d", &jsu1, &jsu2);
	printf("�Է��� ���ڴ� %d %d", jsu1,jsu2);

}


void main031() {
	/// �� ���� �Է��ϱ�
	char a = getchar();
	printf("a= %c \n", a);


	//�ѹ��ڸ� ����ϱ�
	char var1 = 'k';
	putchar(var1);
	putchar(var1+1);
	putchar('t');
}

void main032 () {
	//���ڿ� �Է� 
	char s[50];
	gets(s);
	printf("%s �� �Է��ϼ̽��ϴ�\n", s);

	//scanf�� ���ڿ��� �޴°�� , ���ڿ��� ������������ ©����
	scanf("%s", s);
	printf("scanf�� �Է��� ���ڿ� : %s\n", s);

	//���ڿ� ���
	char s1[50] = "SEOUL";
	char s2[50] = "MANAGER";
	puts(s1);
	puts(s2);//printf �� �������� puts()��  \n�� �ڵ������� ����ȴ�
	printf("%s", s1);
	printf("%s", s2);

}