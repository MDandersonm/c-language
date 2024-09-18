#include <stdio.h>

int size, i = 0;


//�κ����� �ȿ��� �Ǻ��� ��ġ�� ã�� Ȯ���ϴ� ����
int partition(int list[], int begin, int end) {//0 7
	if (begin == 0 && end == 0) {
		return;
	}
	int p;
	p = (begin + end) / 2;
	printf("pivot index: %d \n", p);
	int l = begin;
	int r = end;
	while(l<=r){
		printf("���Ϲ�����\n");
		while (l < r && list[l] < list[p]) {//�ǹ������� �̵���
			l++;
		}
		while (l<r && list[p] <=list[r]) { //�ǹ��� ���� �������� �̵�����
			r--;
		}
		printf("l: %d\n", l);
		printf("r: %d\n", r);
		if (l == r) {//l�� r�� �������� r�� �ǹ��� ��ȯ           //= �� ������ ������ �ȳ��±���.
			printf("l�� r�� ����\n");
			int pivotValue = list[p];
			list[p] = list[r];
			list[r] = pivotValue;
			break;
		}
		else {//l�� r�� ������ �ʾ����� ���� �ڸ���ȯ
			int temp = list[l];
			list[l] = list[r];
			list[r] = temp;
		}
	}
	return r;//������ �ǹ��� �� �ε���

}

void quickSort(int list[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(list, begin, end);
		quickSort(list, begin, p - 1);
		quickSort(list, p+1, end);
	}

}

int main() {

	size = 8;

	int list[8] = { 69,10,30,2,16,8,31,22 };
	printf("\n�������� �迭:  ");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	quickSort(list, 0, size - 1);

	printf("\n������ ��  �迭:  ");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");



	return 0;
}
