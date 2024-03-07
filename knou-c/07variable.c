#include <stdio.h>
#pragma warning(disable:4996)

//외부변수

void main() {
	extern int k;//정의된 k가 다른 파일에 있어도 가져오기 가능

	printf("k=%d \n", k);

	int i;
	int sum = 0;
	for (i = 0; i <= 10; i++) {
		sum += i;
		printf("내부 i = %d sum =%d\n", i, sum);
	}
	//i가 11일때 for문을 벗어나는거임!!!!!!!!!!!!!!!!!!
	printf("중간 i = %d sum =%d\n", i, sum);
	i = i- 1;
	printf("최종 i = %d sum =%d", i, sum);
}
int k = 500;