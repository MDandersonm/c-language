#include <stdio.h>
#include <stdlib.h>
#include "0140queue02.h"
#define RADIX 10
#define DIGIT 2


int getNthDigit(int number, int n) {
	while (n > 1) {  // n이 1보다 클 때까지 반복
		number /= 10;  // 숫자를 10으로 나누어 자릿수 줄이기
		n--;  // 원하는 자리수까지 줄임
	}
	return number % 10;  // 원하는 위치의 자릿수 추출
}

void radixSort(int list[], int size) {
	LQueueType* Q[RADIX];
	for (int bucket = 0; bucket < RADIX; bucket++) {
		Q[bucket] = createLinkedQueue();//Q[0]부터 Q[9]까지 생성
	}

	for (int d = 1;d<=DIGIT;d++) {
		for (int i = 0; i < size; i++) {
			int num = getNthDigit(list[i], d);//특정자리수를 뽑음//1의자리수, 2의자리수
			//printf("%d을 넣겠습니다 \n", num);
			enLinkedQueue(Q[num],list[i]);
			//printLQint(Q[num]);
		}
		
		int k = 0;
		for (int i = 0; i <RADIX; i++) {//0부터 9까지
			while( !isLinkedQueueEmpty(Q[i])){
				int num2 =deLinkedQueue(Q[i]);
				list[k] = num2;
				k++;
			}
		}

		printf("\n%d 단계후 :  ",d);
		for (int i = 0; i < size; i++) {
			printf("%d ", list[i]);
		}
		printf(" \n");

	}

	for (int i = 0; i < RADIX; i++) {
		freeQueue1(Q[i]);  // 구현 필요
		free(Q[i]);
	}


}

int main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	
	printf(" \n 입력원소 >>  ");
	
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}

	printf(" \n >>>>>>>>>>>기수정렬 수행<<<<<<<<< \n\n");
	radixSort(list,size);

	printf("\n 최종 : ");
	
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}





	return 0;
}
;