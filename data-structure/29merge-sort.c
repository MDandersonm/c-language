#include <stdio.h>
#define MAX 30
int size;
int sorted[MAX];

void merge(int list[], int begin, int middle, int end) {
	int i = begin; //ù��° �κ������� ������ġ
	int j = middle + 1; // �ι�° �κ������� ���� ��ġ
	int k = begin; //�迭 sorted�� ���ĵ� ���Ҹ� ������ ��ġ ����

	while (i <= middle && j <= end) {
		if (list[i]<=list[j]) {
			sorted[k] = list[i];
			i++;
		}
		else {
			sorted[k] = list[j];
			j++;

		}
		k++;
	}
	if (i > middle) {
		for (;j<=end;k++,j++) {
			sorted[k] = list[j];
		}
	}
	else if (j > end) {
		for (; i <= middle; k++, i++) {
			sorted[k] = list[i];
		}
	}

	for (int t=begin;t<=end;t++) {
		list[t] = sorted[t];
	}

}

void mergeSort(int list[], int begin, int end) {
	int middle;
	if (begin < end) {
		middle = (begin + end) / 2;
		mergeSort(list, begin, middle);//�պκ� ����
		mergeSort(list, middle + 1, end);//�޺κ� ����
		merge(list, begin, middle, end);//�κ����տ����� ���İ� �����۾� ����
	}
}


int main0290() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	printf(" \n �Է¿��� >>");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf(" \n �������� ���� \n\n");
	mergeSort(list,0,size-1);

	printf(" \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}





	return 0;
}
;