#include <stdio.h>

int size;

void insertionSort(int a[], int size) {

	printf("������ ���� : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
	printf("<<<<<<<���� ���� ���� >>>>>>>>>>>> \n\n");


	for (int i = 1; i < size; i++) {
		printf("%d �ܰ� : ", i + 1);
		int j = i;
		int temp = a[i];// ���Ե� ����
		while (j-1 >= 0) {
			if (a[j-1] > temp) {
				a[j] = a[j-1]; // �� ��ȣ���� �޹�ȣ ������ �����(�ڷ� ����ȿ��)
			}
			else{//j-1�� �ε��� ������ ���Ե� ���Ұ��� �� ũ��
				break;//break�ɸ��� j�� ���������ʰ� ����.
			}
			j--;
		}
		a[j] = temp;// j-1 �ε��� �տ� ������ ���� ��ġ

		for (int i = 0; i < size; i++) {
			printf("%d ", a[i]);
		}
		printf("\n\n");
		
	}
	printf("����\n\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}


}

int main0270() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	insertionSort(list, size);





	return 0;
}
