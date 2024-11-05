#include <stdio.h>

int size;

void insertionSort(int a[], int size) {

	printf("정렬할 원소 : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
	printf("<<<<<<<삽입 정렬 수행 >>>>>>>>>>>> \n\n");


	for (int i = 1; i < size; i++) {
		printf("%d 단계 : ", i + 1);
		int j = i;
		int temp = a[i];// 삽입될 원소
		while (j-1 >= 0) {
			if (a[j-1] > temp) {
				a[j] = a[j-1]; // 앞 번호값을 뒷번호 값으로 덮어씌움(뒤로 당기는효과)
			}
			else{//j-1의 인덱스 값보다 삽입될 원소값이 더 크면
				break;//break걸리면 j가 감소하지않고 끝남.
			}
			j--;
		}
		a[j] = temp;// j-1 인덱스 앞에 삽입할 원소 배치

		for (int i = 0; i < size; i++) {
			printf("%d ", a[i]);
		}
		printf("\n\n");
		
	}
	printf("최종\n\n");
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
