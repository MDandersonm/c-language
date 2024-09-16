#include <stdio.h>


int size;
//�ּ��� ��� (Best Case): O(n) (�̹� ���ĵ� �迭)
//����� ���(Average Case) : O(n ^ 2)
//�־��� ���(Worst Case) : O(n ^ 2)
void bubbleSort(int a[], int size) {
	printf("������ ���� : ");
	for (int k = 0; k < size; k++) {
		printf("%d ", a[k]);
	}
	printf("\n ���� ���� ����!!\n");

	
	int end = size;
	while (end >1) {
		printf("\n%d �ܰ�:  ", size - end+1);
		for (int i = 0; i < end - 1; i++) {
			if (a[i] > a[i + 1]) {//�տ� ���� �� ũ�� ���� ��ȯ�Ѵ�.
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
			printf("\n\t");
			for (int k = 0; k < size; k++) {
				printf("%d ", a[k]);
			}
			
		}
		end--;
		
	
	}
	
};

int main0240() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	bubbleSort(list, size);




	return 0;
}
