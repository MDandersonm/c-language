#include <stdio.h>

void main100() {
	char* cp = "COMPUTER";//ĳ������ ������
	//int* p= 100;
	//printf("%p\n", p);
	printf("%p\n", cp);
	printf("%c\n", *cp);
	printf("%c\n", *(cp + 1));
	printf("%c\n", *(cp + 2));

	int i = 0;
	do {
		printf("%c", *(cp+i));
		//i++;

	} while (*(cp+i++) !='\0' );
}

void main101() {

	char s[] = "SCIENCE";
	char* cp;
	cp = s;


	printf("%p\n", s);//�迭���� �� �迭�� �����ּҰ��� ���´�.
	printf("%c\n", *s);
	printf("%p\n", cp);
	printf("%c\n", *cp);

}


void main102() {

	char* pa[3];
	pa[0] = "electronics";
	pa[1] = "data";
	pa[2] = "solution";


	//pa��� �����͹迭�� �ִµ� pa[0] ,pa[1] ,pa[2] ���� �����Ǿ�����
	//pa�� �ּҴ� pa[0]�� �ּҶ� ����

	printf("%p\n", pa);//pa[0]�� �ּ� 
	printf("%p\n", pa[0]);//"e~�� �ּ�"
	printf("%p\n", pa[1]);//"d~�� �ּ�"
	printf("%p\n", pa[2]);//"s~�� �ּ�"

	printf("----------\n");
	printf("%p\n", &pa);// pa[0]�� �ּ�
	printf("%p\n", &pa[0]);//pa[0]�� �ּ�
	printf("%p\n", &pa[1]);//pa[1]�� �ּ�
	printf("%p\n", &pa[2]);//pa[2]�� �ּ�

	printf("----------\n");
	printf("%p\n", pa[0]);//"e~�� �ּ�"
	printf("%p\n", *pa);      //*pa = pa[0]�� ��  = e�� ����Ű�� �ּ� (������Ÿ����)
	printf("%c\n", *pa[0]);
	printf("%c\n", *pa[1]);
	printf("%c\n", *pa[2]);

	printf("----------\n");

	printf("%c\n", *pa[0]); // �Ǵ�
	printf("%c\n", **pa); // �� �� 'e'�� ����մϴ�.

}