#include <stdio.h>
#define MAX 30
int size;
int sorted[MAX];

void merge(int list[], int begin, int middle, int end) {
	int i = begin; //첫번째 부분집합의 시작위치
	int j = middle + 1; // 두번째 부분집합의 시작 위치
	int k = begin; //배열 sorted에 정렬된 원소를 저장할 위치 설정

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
		mergeSort(list, begin, middle);//앞부분 분할
		mergeSort(list, middle + 1, end);//뒷부분 분할
		merge(list, begin, middle, end);//부분집합에대해 정렬과 병합작업 수행
	}
}


int main0290() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	printf(" \n 입력원소 >>");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf(" \n 병합정렬 수행 \n\n");
	mergeSort(list,0,size-1);

	printf(" \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}





	return 0;
}
;