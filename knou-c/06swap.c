#include <stdio.h>
#pragma warning(disable:4996)

//���� ���� �ڷ�����
void swap(int a, int b);

//������ ���� �ڷ�����
void swap1(int* x, int* y);
void main06() {

	int a = 5;
	int b = 4;
	swap(a, b);
	printf("a�� %d b�� %d \n", a, b);  

	//a,b�� ��ȯ�����ʾҴ� swap(5,4)�ҋ� 5,4 �� ��
	//�Լ�ȣ��� a,b ���� x,y�� ������.

	//& �ּҿ����� 
	//*  �ּ��� ������ �ٷ�� ���� ������
	// *x : x�� �ּҸ� �ٷ�������� *x�� �� �ּ��� ����
	swap1(&a, &b);//a�� �ּ��� ����
	printf("�ּҿ����ڸ� ������� ��� a�� %d b�� %d \n", a, b);


}

void swap(int x,int y) {
	int temp = x;
	x = y;
	y = temp;
}


//�ּҰ��� ���޹ޱ� ���� �����ͺ��� int *x�� ����
void swap1(int *x, int *y) {//x�� a�� �ּ� *x�� a�� �ּ��� ���밪
	int temp = *x;
	*x = *y;
	*y = temp;
}


