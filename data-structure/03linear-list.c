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



typedef struct {//구조체이름 생략
	int row;//행수
	int col;//열수
	int value;// 0이 아닌 원소의 수
} term;

void smTranspose(term a[], term b[]);

void main030() {
	//struct StructName1 my1;
	//struct StrucName2 my2; //에러

	/*
	StructName2는 typedef를 통해 term2로 별칭이 지정된 구조체의 이름이기 때문에,
	struct StructName2 형식으로 변수를 선언할 수 없습니다.
	여기서는 term2 별칭을 사용해야 합니다.
	*/

	//term2 my3;
	
	// testa는 2차원 배열처럼 보일 수 있지만, 실제로는 term 구조체의 1차원 배열입니다
	term a[11] = { {8,7,10},{0,2,2},{0,6,12},{1,4,7},{2,0,23},{3,3,31},{4,1,14},{4,5,25},{5,6,6},{6,0,52}, {7,4,11} };
	term b[11];
	smTranspose(a,b);
	
	// 전치된 희소 행렬 출력
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
a[]와 b[]는 term 구조체의 인스턴스를 여러 개 포함할 수 있는 배열을 나타냅니다. 
즉, a와 b는 각각 term 타입의 요소들을 담고 있는 배열을 가리키는 포인터입니다.
*/
void smTranspose(term a[], term b[]) {
	//a[]: 희소행렬a ,    b[]:전치행렬 b
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
	if (v > 0) {// 0이 아닌 원소가 있는 경우에만 전치 연산 수행
		p = 1;
		for (i = 0; i < n; i++) {// 희소행렬a의 열별로 반복(  전치행렬의 행이될테니 행부터 출력해야해서)
			for (j = 1; j <=v; j++) {//0이 아닌 원소 수에 대해서만 반복수행
				if (a[j].col == i) {// 현재 열에 속하는 원소가 있으면 b[]에 삽입
					//0열,1열.2열 .. 순으로 확인해야 전치행렬에서 0행,1행,2행순으로 정렬이 되기때문
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}

		}

	}
};

