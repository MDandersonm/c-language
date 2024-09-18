#include <stdio.h>


int size;
//�ּ��� ��� (Best Case): O(n) (�̹� ���ĵ� �迭)
//����� ���(Average Case) : O(n ^ 2)
//�־��� ���(Worst Case) : O(n ^ 2)
void bubbleSort2(int a[], int size) {
	printf("\n������ ���� : ");
	int i, j, t, temp;
	for ( t= 0; t < size; t++) {
		printf("%d ", a[t]);
	}
	printf("\n ���� ���� ����!!\n");


	for (i = size - 1; i > 0; i--) {

		printf("\n%d �ܰ�:  ", size - i);
		printf("\n\t");
		for (t = 0; t < size; t++) {
			printf("%3d ", a[t]);
		}
		for ( j = 0; j<i ; j++) {
			//printf("\n::%d,%d", a[j- 1], a[j]);
			//c���� �����ε����� ����ϸ�ȵ�.
			if (a[j] > a[j+1]) {//69>10
				temp = a[j];//temp=69
				a[j] = a[j+1];//�ǳ��ڸ��� 10
				a[j+1] = temp;//a[0]�� 69
				printf("�ٲ�");
			}
			printf("\n\t");
			for ( t = 0; t < size; t++) {
				printf("%3d ", a[t]);
			}

		}

	}

};

int main0250() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	bubbleSort2(list, size);




	return 0;
}
