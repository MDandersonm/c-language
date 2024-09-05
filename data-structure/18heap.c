#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100


typedef struct heapType {
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

//���������� ����
heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

/*

void insertHeap(heapType* h, int item) {
	if (h->heap_size == MAX_ELEMENT) {
		printf("���� ���� á���ϴ�\n");
		return;
	}
	int i = ++h->heap_size; // �� ũ�� ���� �� �� �������� �ε��� ��������

	// �ùٸ� ��ġ�� ã�� ������ ���� �ö󰡸鼭 �̵�
	while ((i != 1) && (item > h->heap[i / 2])) { // ���� �������� �θ𺸴� ū�� Ȯ��
		h->heap[i] = h->heap[i / 2]; // �θ� �Ʒ��� �̵�
		i = i / 2; // Ʈ�� ������ �̵�
	}
	h->heap[i] = item; // �ùٸ� ��ġ�� �� ������ ����
}


*/

void insertHeap(heapType* h, int item) {
	if (h->heap_size == MAX_ELEMENT) {
		printf(" full \n");
		return;
	}
	h->heap_size++;//�߰��� ������ ���Ե� heap ����� ����
	int i = h->heap_size;

	if (i == 1) {//heap�� �������.
		h->heap[i] = item;
		return;
	}

	while (i > 0 && i/2 >0) {

		//���Լ��ڰ� �θ��尪����  �� ũ�� �θ��尪�� �ϴ� ������ġ�� ����
		if (h->heap[i / 2] < item) {
			h->heap[i] = h->heap[i / 2];	
			i = i / 2;
		}
		else {//���Լ��ڰ� �� �۰ų������� ����
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

	if (h->heap_size == 0) {  // ���� ����ִ��� Ȯ��
		return -1;  // Ȥ�� ������ ���� �ڵ�
	}

	int delValue = h->heap[1];
	h->heap[1] = h->heap[h->heap_size]; //�� ����������� ���� ��Ʈ���� �ű�(��Ʈ��Ʈ�� ����)
	int lastValue = h->heap[h->heap_size];
	printf("\n��������尪 :!%d!", lastValue);
	h->heap[h->heap_size] = 0;//�� ����
	h->heap_size--;//heap size�� �ٿ��ٰ��ؼ� �������� ��������Ʈ���� �������°Ծƴϴ�

	int i = 1;
	while ( h->heap[i] < h->heap[2*i] || h->heap[i] < h->heap[2*i+1]) {
		printf(", while�� ����");
		if (h->heap[2 * i] > h->heap[2 * i + 1]) {
			//printf("������ ���ɴϱ�?%d,%d", h->heap[2 * i], h->heap[2 * i + 1]);
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
	
	delValue = h->heap[1];//�����ҳ��
	lastValue = h->heap[h->heap_size];//�Ǹ��������
	h->heap_size--;//heap����� ����( �Ǹ����� ��� ����ȿ��)
	parent = 1;
	child = 2;//�����ڽ�; 2x1�̴ϱ�

	while (child <= h->heap_size) {   // �ڽ� ��尡 ���� ũ�� ���� ���� ������
		// �� ū �ڽ� ��带 ã��
		if (child < h->heap_size && h->heap[child] < h->heap[child + 1]) {
			//������ child�� ��ũ�� 1�� �÷���
			child++;//�������ڽ� ; 2x1+1 �� �ȰŴϱ�.
		}

		// ������ ���Ұ� ���� �ڽ� ��庸�� ũ�� �ߴ�
		//lastValue�� �� child �� ū child���� ũ�ٸ� ��ġ�� ���������ٴ� ���̴�.
		if (lastValue >= h->heap[child]) break;
		

		//  �ڽ� ��尪�� �θ���� �ø� �ø�
		h->heap[parent] = h->heap[child];

		// ���� �ڽ� ���� �̵�
		parent = child;
		child *= 2;
	}

	// ���� ��ġ�� ������ ���� ��ġ
	////lastValue�� �� child �� ū child���� ũ�ٸ� parent�� ����ǰ���.
	/*
	�ٿ����� ���� �� lastValue >= h->heap[child] ���ǿ� ���� ������ �ߴܵǸ�,
	�̴� �� �̻� lastValue�� �������� �ʿ䰡 ���ٴ� ���� �ǹ��մϴ�. 
	���� lastValue�� ���� parent�� ��ġ�� ��ġ�Ǹ�, 
	�̴� lastValue�� �� �ڸ����� ��� �ڽ� ���麸�� ũ�ų� ������ �����մϴ�.
	*/
	h->heap[parent] = lastValue;

	return delValue; // ������ ���� ��ȯ
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
		printf("\n delete(��Ʈ��尪) : [%d]\n ", item);
		printHeap(heap);
	}


	return 0;
}