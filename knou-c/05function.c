#include <stdio.h>
#pragma warning(disable:4996)

int add(int a, int b);//�Լ��� ��������

//�����Ϸ��� �������ҋ��� �����Լ����� �������س����ԵǴµ� 
//add�Լ��� ������ ������ �־����.
//�� add�� main�Լ� �ڿ� �ִ°�� �Լ��� ���������� �ʿ��ϴ�
void main05() {
	int k = add(5, 4);
	printf("���� %d�Դϴ�\n", k);

}

add(int a, int b) {//��ȯŸ���� �����ϸ� int�� �ȴ�.
	return a + b;

}