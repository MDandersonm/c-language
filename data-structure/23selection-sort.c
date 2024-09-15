#include <stdio.h>

int size;


//시간 복잡도 : O(n ^ 2) (최선, 평균, 최악 모두 동일)
//공간 복잡도 : O(1) (추가 공간이 거의 필요 없음)
void selectionSort(int a[], int size) {
	printf("정렬할 원소 : ");
	for (int k = 0; k < size; k++) {
		printf("%d ",a[k]);
	}
	printf("\n 선택 정렬 수행!!\n");
	
	for (int i = 0; i < size-1; i++) {
		int min= a[i]; 
		int idx = i; // idx를 초기화합니다.
		for (int j = i+1; j < size; j++) {
			//순환하면서 가장 작은 값을 찾아서 min으로 입력, 그 인덱스를 idx로 입력
			if (a[j] < min) { 
				min = a[j];
				idx = j;
			}
		};
		if (a[i] != min) {
			//찾은 최소값과  기준위치값과 교환
			a[idx] = a[i];
			a[i] = min;
			
		}
		
		printf("%d 단계: ", i+1);
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
