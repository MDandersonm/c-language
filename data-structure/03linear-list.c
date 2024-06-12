#include <stdio.h>


struct StructName1 {
	int row;
	int col;
	int value;
};

typedef struct StructName2 {
	int row;
	int col;
	int value;
} term2;



typedef struct {//����ü�̸� ����
	int row;//���
	int col;//����
	int value;// 0�� �ƴ� ������ ��
} term;

void smTranspose(term a[], term b[]);

void main030() {
	//struct StructName1 my1;
	//struct StrucName2 my2; //����

	/*
	StructName2�� typedef�� ���� term2�� ��Ī�� ������ ����ü�� �̸��̱� ������,
	struct StructName2 �������� ������ ������ �� �����ϴ�.
	���⼭�� term2 ��Ī�� ����ؾ� �մϴ�.
	*/

	//term2 my3;
	
	// testa�� 2���� �迭ó�� ���� �� ������, �����δ� term ����ü�� 1���� �迭�Դϴ�
	term a[11] = { {8,7,10},{0,2,2},{0,6,12},{1,4,7},{2,0,23},{3,3,31},{4,1,14},{4,5,25},{5,6,6},{6,0,52}, {7,4,11} };
	term b[11];
	smTranspose(a,b);
	
	// ��ġ�� ��� ��� ���
	printf("Row\tCol\tValue\n");
	for (int i = 0; i <= a[0].value; i++) {
		printf("%d\t%d\t%d\n", a[i].row,a[i].col, a[i].value);
	}
	printf("Row\tCol\tValue\n");
	for (int i = 0; i <= a[0].value; i++) {
		printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
	}

}

/*
a[]�� b[]�� term ����ü�� �ν��Ͻ��� ���� �� ������ �� �ִ� �迭�� ��Ÿ���ϴ�. 
��, a�� b�� ���� term Ÿ���� ��ҵ��� ��� �ִ� �迭�� ����Ű�� �������Դϴ�.
*/
void smTranspose(term a[], term b[]) {
	//a[]: ������a ,    b[]:��ġ��� b
	int m, n, v, i, j, p;
	m = a[0].row;
	n = a[0].col; 
	v = a[0].value; 
	b[0].row = n;
	b[0].col = m;
	b[0].value = v;
	/*
	for (int i = 1; i <= v; i++) {
		b[i].row = a[i].col;
		b[i].col = a[i].row;
		b[i].value = a[i].value;
	};
	*/
	if (v > 0) {// 0�� �ƴ� ���Ұ� �ִ� ��쿡�� ��ġ ���� ����
		p = 1;
		for (i = 0; i < n; i++) {// ������a�� ������ �ݺ�(  ��ġ����� ���̵��״� ����� ����ؾ��ؼ�)
			for (j = 1; j <=v; j++) {//0�� �ƴ� ���� ���� ���ؼ��� �ݺ�����
				if (a[j].col == i) {// ���� ���� ���ϴ� ���Ұ� ������ b[]�� ����
					//0��,1��.2�� .. ������ Ȯ���ؾ� ��ġ��Ŀ��� 0��,1��,2������� ������ �Ǳ⶧��
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}

		}

	}
};

