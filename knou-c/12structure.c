#include <stdio.h>

//����ü ����
struct score {
	char no[4];
	char name[8];
	int korean;
	int math;
	int english;
};


//����ü �ʱ�ȭ ���1
struct score2 {
	char no[4];
	char name[8];
	int korean;
	int math;
	int english;
} stu1= { "n01","hong",50,60,70 };


void main120() {
	//����ü �ʱ�ȭ���2
	struct score student1 = { "n01","hong",50,60,70 };
	printf("%d",stu1.math);

}
struct student {
	char name[10];
	int kor;
	int eng;
};

//����ü ������
void main121() {
	struct student hs[4] = { {"kim",10,20},{"yeong",30,40},{"park",50,60},{"lee",70,80} };
	struct student* p;
	p = hs;
	printf("hs�� �ּ� %p\n", hs);
	printf("p�� ��= hs�� �ּ� %p\n", p);
	printf("%p\n", &hs[0]);// hs[0]�� ����ü�̱⋚���� �ּҸ� ǥ���Ϸ��� *�� �ٿ�����
	printf("%d\n", (*p).eng	);
	printf("%d\n", (*hs).eng);
	printf("%d\n", (*(p+1)).eng);
	printf("%s %d %d\n", (*p).name, (*p).kor, (*p).eng);
	printf("hs�� -> %s %d %d\n", hs->name, hs->kor, hs->eng);
	printf("%s %d %d\n", p->name, p->kor, p->eng);
	p += 3;
	printf("%s %d %d\n", p->name, p->kor, p->eng);
	p--;
	printf("%s %d %d\n", p->name, p->kor, p->eng);

}
