#include <stdio.h>
#define TEL "1577-2255"
#define width(x)(3.14*x*x)
#define CONDITION 1
void main02() {
	printf("hello world!!\n");
	//���ڴ�� �ܾ ���
	//enum �±׸� {������1,������2...};
	enum day1 {SUN,MON,TUE,WED,THU,FRI,SAT} d1;//������ ���� d1

	d1 = WED;
	printf("%d\n", d1);//3���
	//printf("%s\n", TEL);

#if CONDITION //���Ǻ� ������
	printf("%f\n", width(5));
#else
	printf("%s\n", TEL);
#endif
};