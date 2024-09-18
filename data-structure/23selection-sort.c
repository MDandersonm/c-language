#include <stdio.h>

int size;


//�ð� ���⵵ : O(n ^ 2) (�ּ�, ���, �־� ��� ����)
//���� ���⵵ : O(1) (�߰� ������ ���� �ʿ� ����)
void selectionSort(int a[], int size) {
	printf("������ ���� : ");
	for (int k = 0; k < size; k++) {
		printf("%d ",a[k]);
	}
	printf("\n ���� ���� ����!!\n");
	
	for (int i = 0; i < size-1; i++) {
		int min= a[i]; 
		int idx = i; // idx�� �ʱ�ȭ�մϴ�.
		for (int j = i+1; j < size; j++) {
			//��ȯ�ϸ鼭 ���� ���� ���� ã�Ƽ� min���� �Է�, �� �ε����� idx�� �Է�
			if (a[j] < min) { 
				min = a[j];
				idx = j;
			}
		};
		if (a[i] != min) {
			//ã�� �ּҰ���  ������ġ���� ��ȯ
			a[idx] = a[i];
			a[i] = min;
			
		}
		
		printf("%d �ܰ�: ", i+1);
		for (int k = 0; k < size; k++) {
			printf("%d ", a[k]);
		}
		printf("\n");
		
	};

};

int main0230() {
	int list[8] = {69, 10, 30, 2, 16, 8, 31, 22};
	size = 8;
	selectionSort(list, size);




	return 0;
}
