#include <stdio.h>

int main005() {
	int num = 10;
	int* numpt1;
	int** numpt2;


	numpt1 = &num;
	numpt2 = &numpt1;

	printf("%d\n", **numpt2);




}
