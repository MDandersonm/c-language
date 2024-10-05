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
arr[0]�� a�� �ּҸ� �����ϰ� �ֽ��ϴ�.
*arr[0]�� ����ϸ� a�� ��(��, 12)�� ���� �� �ֽ��ϴ�.
arr ��ü�� int* Ÿ���� �迭�̹Ƿ�, *arr�� arr�� ù ��° ���, �� arr[0]�� �ǹ��մϴ�. ����:
*arr�� arr[0]�� ������ a�� �ּҸ� ����ŵ�ϴ�.
**arr�� *arr[0]�� ������ a�� ���� ��ȯ�մϴ�.

*/
struct jsu {
	char nae[12];
	int os, db, hab, hhab;
};

int main992() {
	struct jsu st[3] = { {"������1", 95, 88},
					  {"������2", 84, 91},
					  {"������3", 86, 75} };
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
*(ary + 0)���� ary�� �迭�� �̸��Դϴ�. �迭�� �̸��� �迭�� ù ��° ������ �ּҸ� ��Ÿ���ϴ�. ����, ary�� ary[0]�� �ּҿ� �����ϴ�.

ary + 0�� ù ��° ������ �ּҿ� 0�� ���� ���̹Ƿ�, ������ ary[0]�� �ּҸ� ��Ÿ���ϴ�.

����, *(ary + 0) = 1;�� ary[0]�� �ּҿ� �ִ� ���� �����Ͽ� �װ��� 1�� �����Ѵٴ� �ǹ��Դϴ�. �̴� ary[0] = 1;�� ������ ������ �մϴ�.

�����ϰ� ����ϸ�, *(ary + 0)�� �迭�� ù ��° ���� ary[0]�� �����ϴ� ����Դϴ�. ���⼭ + 0�� ������ �ּҸ� �������� ������, �̸� Ȯ���ϸ� �迭�� �ٸ� ���ҵ鵵 ������ �� �ְ� �˴ϴ�. ���� ���, *(ary + 1)�� ary[1]�� �����ϰ� �˴ϴ�.

*/


struct good {
	char name[10];
	int age;
};

void main994() {
	struct good s[] = { "Kim",28,"Lee",38,"Seo",50,"Park",35 };

/*
	���⼭ struct good s[] = { "Kim",28,"Lee",38,"Seo",50,"Park",35 }; �κ��� struct good Ÿ���� �迭 s�� �����ϰ� �ʱ�ȭ�ϴ� �κ��Դϴ�.

�迭 s�� struct good�� 4���� ���ҷ� �����Ǿ� ������, �� ���Ҵ� name�� age �� ���� ����� ������ �ֽ��ϴ�.

�ʱ�ȭ�� ������ ���� �̷�����ϴ�:

ù ��° ���� s[0]:
name: "Kim"
age: 28
�� ��° ���� s[1]:
name: "Lee"
age: 38
�� ��° ���� s[2]:
name: "Seo"
age: 50
�� ��° ���� s[3]:
name: "Park"
age: 35
	*/
	struct good* p;
	p = s;
	p++;
	printf("%s\n", p->name);
	printf("%s\n", p->age);

	/*
	*  s;��� �ڵ�� ����ü �迭 s�� ù ��° ������ �ּҸ� p�� �Ҵ��մϴ�. �迭 �̸��� �迭�� ù ��° ������ �ּҸ� ��Ÿ���� ������, �̷� ���� p�� �迭 s�� ù ��° ����, �� s[0]�� ����Ű�� �˴ϴ�.
	*  p++�� p�� ���� ����Ű�� �ִ� �޸� �ּҿ��� sizeof(struct good)��ŭ �̵���ŵ��
	*/

}

int main995() {
	char* p = "KOREA";
	printf("%s\n", p); // K�� �ּҰ�? �ƴϿ� X KOREA
	printf("%s\n", p + 3);// E���ּҰ�?�ƴϿ� X EA

	/*
	
	%s�� ����ϸ� �� �����Ͱ� ����Ű�� �ּҺ��� �����ؼ� �� ����('\0')�� ���� �������� ���ڿ��� ����ϰ� �˴ϴ�.
	
	*/
	printf("%p\n", p); // K�� �ּҰ�
	printf("%p\n", p + 3);// E���ּҰ� 

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
		printf("Current character: %c ", *p);  // p�� ���� ���� ����մϴ�.
		printf("Current r: %d\n", r);  // p�� ���� ���� ����մϴ�.
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