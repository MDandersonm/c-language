#include <stdio.h>
int main991() {
	int* arr[3];
	int a = 12, b = 24, c = 36;
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &c;

	printf("%d\n", *arr[1] + **arr + 1);
}

/*
arr[0]는 a의 주소를 저장하고 있습니다.
*arr[0]를 사용하면 a의 값(즉, 12)를 얻을 수 있습니다.
arr 자체는 int* 타입의 배열이므로, *arr는 arr의 첫 번째 요소, 즉 arr[0]을 의미합니다. 따라서:
*arr는 arr[0]과 같으며 a의 주소를 가리킵니다.
**arr는 *arr[0]과 같으며 a의 값을 반환합니다.

*/
struct jsu {
	char nae[12];
	int os, db, hab, hhab;
};

int main992() {
	struct jsu st[3] = { {"데이터1", 95, 88},
					  {"데이터2", 84, 91},
					  {"데이터3", 86, 75} };
	struct jsu* p;

	p = &st[0];

	(p + 1)->hab = (p + 1)->os + (p + 2)->db;
	(p + 1)->hhab = (p + 1)->hab + p->os + p->db;

	printf("%d\n", (p + 1)->hab + (p + 1)->hhab);
}

int main993() {
	int ary[3];
	int s = 0;
	*(ary + 0) = 1;
	ary[1] = *(ary + 0) + 2;
	ary[2] = *ary + 3;
	for (int i = 0; i < 3; i++) {
		s = s + ary[i];
	}
	printf("%d", s);
}

/*
*(ary + 0)에서 ary는 배열의 이름입니다. 배열의 이름은 배열의 첫 번째 원소의 주소를 나타냅니다. 따라서, ary는 ary[0]의 주소와 같습니다.

ary + 0는 첫 번째 원소의 주소에 0을 더한 값이므로, 여전히 ary[0]의 주소를 나타냅니다.

따라서, *(ary + 0) = 1;는 ary[0]의 주소에 있는 값을 참조하여 그곳에 1을 저장한다는 의미입니다. 이는 ary[0] = 1;와 동일한 동작을 합니다.

간단하게 요약하면, *(ary + 0)는 배열의 첫 번째 원소 ary[0]을 참조하는 방식입니다. 여기서 + 0은 실제로 주소를 변경하지 않지만, 이를 확장하면 배열의 다른 원소들도 접근할 수 있게 됩니다. 예를 들면, *(ary + 1)은 ary[1]를 참조하게 됩니다.

*/


struct good {
	char name[10];
	int age;
};

void main994() {
	struct good s[] = { "Kim",28,"Lee",38,"Seo",50,"Park",35 };

/*
	여기서 struct good s[] = { "Kim",28,"Lee",38,"Seo",50,"Park",35 }; 부분은 struct good 타입의 배열 s를 선언하고 초기화하는 부분입니다.

배열 s는 struct good의 4개의 원소로 구성되어 있으며, 각 원소는 name과 age 두 개의 멤버를 가지고 있습니다.

초기화는 다음과 같이 이루어집니다:

첫 번째 원소 s[0]:
name: "Kim"
age: 28
두 번째 원소 s[1]:
name: "Lee"
age: 38
세 번째 원소 s[2]:
name: "Seo"
age: 50
네 번째 원소 s[3]:
name: "Park"
age: 35
	*/
	struct good* p;
	p = s;
	p++;
	printf("%s\n", p->name);
	printf("%s\n", p->age);

	/*
	*  s;라는 코드는 구조체 배열 s의 첫 번째 원소의 주소를 p에 할당합니다. 배열 이름은 배열의 첫 번째 원소의 주소를 나타내기 때문에, 이로 인해 p는 배열 s의 첫 번째 원소, 즉 s[0]를 가리키게 됩니다.
	*  p++는 p가 현재 가리키고 있는 메모리 주소에서 sizeof(struct good)만큼 이동시킵니
	*/

}

int main995() {
	char* p = "KOREA";
	printf("%s\n", p); // K의 주소값? 아니요 X KOREA
	printf("%s\n", p + 3);// E의주소값?아니요 X EA

	/*
	
	%s를 사용하면 이 포인터가 가리키는 주소부터 시작해서 널 문자('\0')가 나올 때까지의 문자열을 출력하게 됩니다.
	
	*/
	printf("%p\n", p); // K의 주소값
	printf("%p\n", p + 3);// E의주소값 

	printf("%c\n", *p); //K
	printf("%c\n", *(p + 3)); // E
	printf("%c\n", *p + 2);// M


	return 0;
}

int main996() {

	char a[] = "Art";
	char* p = NULL;
	p = a;

	printf("%s\n", a);//"Art"
	printf("%c\n", *p);//"A"
	printf("%c\n", *a);//"A"
	printf("%s\n", p);//"Art

	for (int i = 0; a[i] != '\0'; i++)
		printf("%c", a[i]);
	//Art
}


int len(char* p);

int len(char* p) {
	int r = 0;
	while (*p != '\0') {
		printf("Current character: %c ", *p);  // p의 현재 값을 출력합니다.
		printf("Current r: %d\n", r);  // p의 현재 값을 출력합니다.
		p++;
		r++;
	}
	return r;
}


int main997() {
	char* p1 = "2022";
	char* p2 = "202207";

	printf("%d", len(p1) + len(p2));

	return 0;
}

int main(int argc, char* argv[]) {
	int a[4] = { 0, 2, 4, 8 };
	int b[3] = {0,0,0};
	int i = 1;
	int sum = 0;
	int* p1;

	for (i; i < 4; i++) {
		p1 = a + i;
		b[i - 1] = *p1 - a[i - 1];
		sum = sum + b[i - 1] + a[i];
	}
	printf("%d", sum);

	return 0;
}