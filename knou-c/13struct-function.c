#include <stdio.h>
struct num {
	int x;
	int y;
	int sum;
	int mul;
};

/// ���� ���� �ڷ�����

struct num calc(struct num); //����ü ���� ����

void main130() {
	struct num number1;
	number1.x = 10;
	number1.y = 20;
	number1 = calc(number1); // ��ȣ���Լ� calc()�� struct num�� ����ü�� �Ű������� �Ѱ���   calc�� ����ü�� �����ϴ� �Լ��̴�.
	printf("%d %d %d %d\n ", number1.x, number1.y, number1.sum, number1.mul);
	//getchar();
}


struct num calc(struct num number2) {   // �Ѱܹ���  struct num�� ����ü�� ������� ����Ѵ�.
	number2.sum=number2.x+number2.y;
	number2.mul = number2.x * number2.y;
	return number2;//����ü�� ����
}

////////////////////// ����ü �����͸� �Լ��� �Ű������� ���(������ ���� �ڷ�����)

struct num calc2(struct num*);

void main131() {
	struct num number3;
	number3.x = 10;
	number3.y = 20;
	calc2(&number3);
	printf("%d %d %d %d\n ", number3.x, number3.y, number3.sum, number3.mul);
	//getchar();
}

struct num calc2(struct num* number2) {   // �Ѱܹ���  struct num�� ����ü�� ������� ����Ѵ�.
	number2->sum = number2->x + number2->y;
	number2->mul = number2->x * number2->y;
}