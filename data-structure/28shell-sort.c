#include <stdio.h>

int size;

void intervalSort(int a[], int begin, int end, int interval) {
	//�κ� ���տ� ���� ���� ������ �����ϴ� ����
	//  end :7 interval:4

	for (int i = begin+interval ; i <= end; i=i+interval) {
		int j = i;
		int temp = a[j];
		while ( ( j - interval >= begin) && (a[j - interval] > temp) ) {
			a[j] = a[j - interval];
			j = j - interval;
		}
		a[j] = temp;


	}




}

void shellSort(int a[], int size) {

	printf("������ ���� : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
	printf("<<<<<<<�� ���� ���� >>>>>>>>>>>> \n\n");
	
	int interval = size / 2; //4
	while (interval>=1 ) {
		for (int i = 0; i<interval ;i++) {
			intervalSort(a, i, size-1, interval);
		}
		printf("%d interval : ",interval);

		for (int i = 0; i < size; i++) {
			printf("%d ", a[i]);
		}
		printf("\n\n");

		interval = interval / 2;
	}

	printf("����\n\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}

}

int main0280() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	size = 8;
	shellSort(list, size);





	return 0;
}
