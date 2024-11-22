#include <stdio.h>
#include <stdlib.h>
#include "0140queue02.h"
#define RADIX 10
#define DIGIT 2


int getNthDigit(int number, int n) {
	while (n > 1) {  // n�� 1���� Ŭ ������ �ݺ�
		number /= 10;  // ���ڸ� 10���� ������ �ڸ��� ���̱�
		n--;  // ���ϴ� �ڸ������� ����
	}
	return number % 10;  // ���ϴ� ��ġ�� �ڸ��� ����
}

void radixSort(int list[], int size) {
	LQueueType* Q[RADIX];
	for (int bucket = 0; bucket < RADIX; bucket++) {
		Q[bucket] = createLinkedQueue();//Q[0]���� Q[9]���� ����
	}

	for (int d = 1;d<=DIGIT;d++) {
		for (int i = 0; i < size; i++) {
			int num = getNthDigit(list[i], d);//Ư���ڸ����� ����//1���ڸ���, 2���ڸ���
			//printf("%d�� �ְڽ��ϴ� \n", num);
			enLinkedQueue(Q[num],list[i]);
			//printLQint(Q[num]);
		}
		
		int k = 0;
		for (int i = 0; i <RADIX; i++) {//0���� 9����
			while( !isLinkedQueueEmpty(Q[i])){
				int num2 =deLinkedQueue(Q[i]);
				list[k] = num2;
				k++;
			}
		}

		printf("\n%d �ܰ��� :  ",d);
		for (int i = 0; i < size; i++) {
			printf("%d ", list[i]);
		}
		printf(" \n");

	}

	for (int i = 0; i < RADIX; i++) {
		freeQueue1(Q[i]);  // ���� �ʿ�
		free(Q[i]);
	}


}

int main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	
	printf(" \n �Է¿��� >>  ");
	
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}

	printf(" \n >>>>>>>>>>>������� ����<<<<<<<<< \n\n");
	radixSort(list,size);

	printf("\n ���� : ");
	
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}





	return 0;
}
;