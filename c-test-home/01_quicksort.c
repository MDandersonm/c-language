#include <stdio.h>

int size, i = 0;


//부분집합 안에서 피봇의 위치를 찾아 확정하는 연산
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
		printf("와일문진입\n");
		while (l < r && list[l] < list[p]) {//피벗까지만 이동함
			l++;
		}
		while (l<r && list[p] <=list[r]) { //피벗을 지나 왼쪽으로 이동가능
			r--;
		}
		printf("l: %d\n", l);
		printf("r: %d\n", r);
		if (l == r) {//l과 r이 만났을때 r과 피벗과 교환           //= 로 썼을때 에러가 안나는구나.
			printf("l과 r이 만남\n");
			int pivotValue = list[p];
			list[p] = list[r];
			list[r] = pivotValue;
			break;
		}
		else {//l와 r가 만나지 않았을때 둘이 자리교환
			int temp = list[l];
			list[l] = list[r];
			list[r] = temp;
		}
	}
	return r;//새로이 피벗이 된 인덱스

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
	printf("\n퀵정렬할 배열:  ");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	quickSort(list, 0, size - 1);

	printf("\n퀵정렬 후  배열:  ");
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");



	return 0;
}
