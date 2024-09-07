#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100


typedef struct heapType {
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

//공백히프를 생성
heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

/*

void insertHeap(heapType* h, int item) {
	if (h->heap_size == MAX_ELEMENT) {
		printf("힙이 가득 찼습니다\n");
		return;
	}
	int i = ++h->heap_size; // 힙 크기 증가 및 새 아이템의 인덱스 가져오기

	// 올바른 위치를 찾을 때까지 힙을 올라가면서 이동
	while ((i != 1) && (item > h->heap[i / 2])) { // 삽입 아이템이 부모보다 큰지 확인
		h->heap[i] = h->heap[i / 2]; // 부모를 아래로 이동
		i = i / 2; // 트리 상위로 이동
	}
	h->heap[i] = item; // 올바른 위치에 새 아이템 삽입
}


*/

void insertHeap(heapType* h, int item) {
	if (h->heap_size == MAX_ELEMENT) {
		printf(" full \n");
		return;
	}
	h->heap_size++;//추가될 노드까지 포함된 heap 노드의 개수
	int i = h->heap_size;

	if (i == 1) {//heap이 비었을떄.
		h->heap[i] = item;
		return;
	}

	while (i > 0 && i/2 >0) {

		//삽입숫자가 부모노드값보다  더 크면 부모노드값을 일단 삽입위치에 적고
		if (h->heap[i / 2] < item) {
			h->heap[i] = h->heap[i / 2];	
			i = i / 2;
		}
		else {//삽입숫자가 더 작거나같으면 고정
			break;
		}
	}
	h->heap[i] = item;
}


void printHeap(heapType* h) {
	printf("------------");
	int i = 1;
	printf("HEAP : ");
	while (i <= h->heap_size) {
		printf("[%d] ", h->heap[i]);
		i++;
	}
	printf("------------\n");
}

/*
int deleteHeap(heapType* h) {

	if (h->heap_size == 0) {  // 힙이 비어있는지 확인
		return -1;  // 혹은 적절한 에러 코드
	}

	int delValue = h->heap[1];
	h->heap[1] = h->heap[h->heap_size]; //맨 마지막노드의 값을 루트노드로 옮김(루트노트값 삭제)
	int lastValue = h->heap[h->heap_size];
	printf("\n마지막노드값 :!%d!", lastValue);
	h->heap[h->heap_size] = 0;//값 삭제
	h->heap_size--;//heap size를 줄였다고해서 예전값이 순차리스트에서 없어지는게아니다

	int i = 1;
	while ( h->heap[i] < h->heap[2*i] || h->heap[i] < h->heap[2*i+1]) {
		printf(", while문 진입");
		if (h->heap[2 * i] > h->heap[2 * i + 1]) {
			//printf("참으로 들어옵니까?%d,%d", h->heap[2 * i], h->heap[2 * i + 1]);
			h->heap[i] = h->heap[2 * i];
			h->heap[2 * i] = lastValue;
			i = 2 * i;
		}
		else {
			h->heap[i] = h->heap[2 * i+1];
			h->heap[2 * i+1] = lastValue;
			i = 2 * i +1;
		}
	}
	return delValue;
}

*/

int deleteHeap(heapType* h) {
	int parent, child;
	int delValue, lastValue;
	
	delValue = h->heap[1];//삭제할노드
	lastValue = h->heap[h->heap_size];//맨마지막노드
	h->heap_size--;//heap사이즈를 줄임( 맨마지막 노드 삭제효과)
	parent = 1;
	child = 2;//왼쪽자식; 2x1이니까

	while (child <= h->heap_size) {   // 자식 노드가 히프 크기 내에 있을 때까지
		// 더 큰 자식 노드를 찾음
		if (child < h->heap_size && h->heap[child] < h->heap[child + 1]) {
			//오른쪽 child가 더크면 1을 올려줌
			child++;//오른쪽자식 ; 2x1+1 이 된거니까.
		}

		// 마지막 원소가 현재 자식 노드보다 크면 중단
		//lastValue가 두 child 중 큰 child보다 크다면 위치상 문제가없다는 뜻이다.
		if (lastValue >= h->heap[child]) break;
		

		//  자식 노드값을 부모노드로 올림 올림
		h->heap[parent] = h->heap[child];

		// 다음 자식 노드로 이동
		parent = child;
		child *= 2;
	}

	// 최종 위치에 마지막 원소 배치
	////lastValue가 두 child 중 큰 child보다 크다면 parent에 들어가면되겠지.
	/*
	다운히프 과정 중 lastValue >= h->heap[child] 조건에 의해 루프가 중단되면,
	이는 더 이상 lastValue를 내려보낼 필요가 없다는 것을 의미합니다. 
	따라서 lastValue는 현재 parent의 위치에 배치되며, 
	이는 lastValue가 그 자리에서 모든 자식 노드들보다 크거나 같음을 보증합니다.
	*/
	h->heap[parent] = lastValue;

	return delValue; // 삭제된 원소 반환
}

int main0180() {
	
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);

	insertHeap(heap, 11);
	insertHeap(heap, 96);
	printHeap(heap);

	n = heap->heap_size;
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete(루트노드값) : [%d]\n ", item);
		printHeap(heap);
	}


	return 0;
}