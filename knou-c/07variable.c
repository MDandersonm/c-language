#include <stdio.h>
#pragma warning(disable:4996)

//�ܺκ���

void main() {
	extern int k;//���ǵ� k�� �ٸ� ���Ͽ� �־ �������� ����

	printf("k=%d \n", k);

	int i;
	int sum = 0;
	for (i = 0; i <= 10; i++) {
		sum += i;
		printf("���� i = %d sum =%d\n", i, sum);
	}
	//i�� 11�϶� for���� ����°���!!!!!!!!!!!!!!!!!!
	printf("�߰� i = %d sum =%d\n", i, sum);
	i = i- 1;
	printf("���� i = %d sum =%d", i, sum);
}
int k = 500;