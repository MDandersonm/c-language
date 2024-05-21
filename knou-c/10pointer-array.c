#include <stdio.h>

void main100() {
	char* cp = "COMPUTER";//캐릭터형 포인터
	//int* p= 100;
	//printf("%p\n", p);
	printf("%p\n", cp);
	printf("%c\n", *cp);
	printf("%c\n", *(cp + 1));
	printf("%c\n", *(cp + 2));

	int i = 0;
	do {
		printf("%c", *(cp+i));
		//i++;

	} while (*(cp+i++) !='\0' );
}

void main101() {

	char s[] = "SCIENCE";
	char* cp;
	cp = s;


	printf("%p\n", s);//배열명은 그 배열의 시작주소값을 갖는다.
	printf("%c\n", *s);
	printf("%p\n", cp);
	printf("%c\n", *cp);

}


void main102() {

	char* pa[3];
	pa[0] = "electronics";
	pa[1] = "data";
	pa[2] = "solution";


	//pa라는 포인터배열이 있는데 pa[0] ,pa[1] ,pa[2] 으로 구성되어있음
	//pa의 주소는 pa[0]의 주소랑 같음

	printf("%p\n", pa);//pa[0]의 주소 
	printf("%p\n", pa[0]);//"e~의 주소"
	printf("%p\n", pa[1]);//"d~의 주소"
	printf("%p\n", pa[2]);//"s~의 주소"

	printf("----------\n");
	printf("%p\n", &pa);// pa[0]의 주소
	printf("%p\n", &pa[0]);//pa[0]의 주소
	printf("%p\n", &pa[1]);//pa[1]의 주소
	printf("%p\n", &pa[2]);//pa[2]의 주소

	printf("----------\n");
	printf("%p\n", pa[0]);//"e~의 주소"
	printf("%p\n", *pa);      //*pa = pa[0]의 값  = e를 가리키는 주소 (포인터타입임)
	printf("%c\n", *pa[0]);
	printf("%c\n", *pa[1]);
	printf("%c\n", *pa[2]);

	printf("----------\n");

	printf("%c\n", *pa[0]); // 또는
	printf("%c\n", **pa); // 둘 다 'e'를 출력합니다.

}