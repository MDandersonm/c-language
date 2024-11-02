#include<stdio.h>
#pragma warning(disable:4996)

void main0100() {
	register int i;
	int sum = 0;
	for (i = 0; i <= 10; ++i)
		printf("i=%d\n", i);
		sum += i;
	printf("i=%d\n", i);
	i -= 1;
	printf("i=%d sum= %d", i, sum);
}


/*
int main() {
	{
		static int staticVar = 0; // static 지역 변수
	}

	staticVar++;
	printf("staticVar : %d ", staticVar);

    return 0;
}
*/

int main() {
	printf("keep looking!");
	printf("You'll find it! \n");
	return 0;

}