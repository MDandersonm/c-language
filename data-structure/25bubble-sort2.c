#include <stdio.h>


int size;
//최선의 경우 (Best Case): O(n) (이미 정렬된 배열)
//평균의 경우(Average Case) : O(n ^ 2)
//최악의 경우(Worst Case) : O(n ^ 2)
void bubbleSort2(int a[], int size) {
	printf("\n정렬할 원소 : ");
	int i, j, t, temp;
	for ( t= 0; t < size; t++) {
		printf("%d ", a[t]);
	}
	printf("\n 버블 정렬 수행!!\n");


	for (i = size - 1; i > 0; i--) {

		printf("\n%d 단계:  ", size - i);
		printf("\n\t");
		for (t = 0; t < size; t++) {
			printf("%3d ", a[t]);
		}
		for ( j = 0; j<i ; j++) {
			//printf("\n::%d,%d", a[j- 1], a[j]);
			//c언어에서 음수인덱스는 사용하면안됨.
			if (a[j] > a[j+1]) {//69>10
				temp = a[j];//temp=69
				a[j] = a[j+1];//맨끝자리에 10
				a[j+1] = temp;//a[0]에 69
				printf("바뀜");
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
