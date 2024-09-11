#include "0220bfs.h"

typedef struct QNode {
	int data;
	struct QNode* link;
}QNode;

typedef struct LQueueType {
	QNode* front, * rear;
} LQueueType;

LQueueType* createLinkedQueue21() {
	LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty21(LQueueType* LQ) {
	if (LQ->rear == NULL && LQ->front == NULL) {
	
		return 1; //�����.
	}
	else {
		return 0;
	}

}

void enQueue21(LQueueType* LQ, int item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if (isEmpty21(LQ) ){
		LQ->rear = newNode;
		LQ->front = newNode;
		return;
	}
	
	LQ->rear->link = newNode;
	LQ->rear = newNode;
	
}

int deQueue21(LQueueType* LQ) {
	if (isEmpty21(LQ)) {
		printf("\nQueue is empty!");
		return -1; // �� ť�� �� ��ȯ�� ��
	}

	int result = LQ->front->data;
	QNode* temp = LQ->front;
	LQ->front = LQ->front->link;
	if (LQ->front == NULL) {
		LQ->rear = NULL;
	}

	free(temp);
	return result;

}

void freeQueue(LQueueType* LQ) {
	while (!isEmpty21(LQ)) {
		deQueue21(LQ);
	}
	free(LQ);
}

void BFS_adjList(graphType2* g, int v) {
	LQueueType* LQ = createLinkedQueue21();
	graphNode* temp = g->adjList_H[v];
	printf("%c ", v + 'A');
	g->visited[v] = TRUE;
	while(1){
		while(temp !=NULL){
			if (g->visited[temp->vertex] == FALSE) {
				enQueue21(LQ, temp->vertex);
				g->visited[temp->vertex] = TRUE;
				printf("-> %c ", temp->vertex + 'A');
			}
			temp = temp->link;
		}
		v=deQueue21(LQ);
		if (v == -1) {
			return;
		}
		temp = g->adjList_H[v];
	}
	freeQueue(LQ);

}

int main0220() {
	int i;
	graphType2* G9 = (graphType2*)malloc(sizeof(graphType2));



	createGraph2(G9);

	for (i = 0; i < 7; i++) {
		insertVertex2(G9, i);
	}//0 1 2 3 5 6�� ��带 ����

	insertEdge2(G9, 0, 2);
	insertEdge2(G9, 0, 1);
	insertEdge2(G9, 1, 4);
	insertEdge2(G9, 1, 3);
	insertEdge2(G9, 1, 0);
	insertEdge2(G9, 2, 4);
	insertEdge2(G9, 2, 0);
	insertEdge2(G9, 3, 6);
	insertEdge2(G9, 3, 1);
	insertEdge2(G9, 4, 6);
	insertEdge2(G9, 4, 2);
	insertEdge2(G9, 4, 1);
	insertEdge2(G9, 5, 6);
	insertEdge2(G9, 6, 5);
	insertEdge2(G9, 6, 4);
	insertEdge2(G9, 6, 3);
	printf("\n G9�� ��������Ʈ");
	print_adjList2(G9);
	printf("\n �ʺ� �켱Ž�� >>");

	BFS_adjList(G9, 0);



	// ���� �Լ�����

	freeGraph2(G9);

	return 0;
}

