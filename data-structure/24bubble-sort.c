#include <stdio.h>


int size;
//최선의 경우 (Best Case): O(n) (이미 정렬된 배열)
//평균의 경우(Average Case) : O(n ^ 2)
//최악의 경우(Worst Case) : O(n ^ 2)
void bubbleSort(int a[], int size) {
	printf("정렬할 원소 : ");
	for (int k = 0; k < size; k++) {
		printf("%d ", a[k]);
	}
	printf("\n 버블 정렬 수행!!\n");

	
	int end = size;
	while (end >1) {
		printf("\n%d 단계:  ", size - end+1);
		for (int i = 0; i < end - 1; i++) {
			if (a[i] > a[i + 1]) {//앞에 것이 더 크면 둘이 교환한다.
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
