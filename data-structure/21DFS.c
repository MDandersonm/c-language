#include "0220bfs.h"



typedef struct stackNode21 {
	int data;
	struct stackNode21* link;

} stackNode21;

stackNode21* top21 = NULL; // ������ �ֻ�� ���

void push21(int item) {
	stackNode21* newNode = (stackNode21*)malloc(sizeof(stackNode21));
	
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	newNode->data = item;
	newNode->link = top21;
	top21 = newNode;
}

int pop21() {
	if (top21 == NULL) {
		printf("���� ����÷ο�\n");
		exit(1);
	}
	stackNode21* deleteNode = top21;
	int result = deleteNode->data;
	top21 = top21->link;
	free(deleteNode);
	return result;

}


//����׷��� ����
void createGraph2(graphType2* g) {
	g->n = 0;

	for (int i = 0; i < MAX_VERTEX2; i++) {
		g->adjList_H[i] = NULL;
		g->visited[i] = FALSE;
	};
}

//�׷����� ����v�� �����ϴ� ����.
void insertVertex2(graphType2* g, int v) {

	if (((g->n) + 1) > MAX_VERTEX2) {
		printf("\n �׷��� ������ ������ �ʰ�");
		return;
	}

	g->n += 1;
	g->adjList_H[v] = NULL;
	//���� . ���⼭ ��带 �����ϸ� �ȵ���. ���� ��尡 �ƴ�.
	//g->adjList_H[v] = (graphNode*)malloc(sizeof(graphNode));
	//
}



void insertEdge2(graphType2* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�.");
		return;
	}
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->vertex = v;
	graphNode* temp = g->adjList_H[u];//��尡 ����Ű�°�
	g->adjList_H[u] = newNode;//ù�κ����� ����
	newNode->link = temp;

};


void print_adjList2(graphType2* g) {
	for (int i = 0; i < g->n; i++) {
		printf("\n ���� %c �� ���� ����Ʈ ", i + 'A');
		graphNode* temp = g->adjList_H[i];
		while (temp != NULL) {
			printf("-> %c ", temp->vertex + 'A');
			temp = temp->link;
		};
	};

}

void freeGraph2(graphType2* g) {
	for (int i = 0; i < g->n; i++) {
		graphNode* current = g->adjList_H[i];
		while (current != NULL) {
			graphNode* temp = current;
			current = current->link;
			free(temp);
		}
	}
	free(g);
}

void DFS_adjList(graphType2* g, int v) {

	top21 = NULL;
	graphNode* temp = g->adjList_H[v];
	printf("%c ", v+'A');
	push21(v);
	g->visited[v] = TRUE;
	while (top21 != NULL) {
		while(temp){
			if (g->visited[temp->vertex] ==FALSE ) {
				push21(temp->vertex);
				g->visited[temp->vertex] = TRUE;
				printf("-> %c ", temp->vertex + 'A');

				temp = g->adjList_H[temp->vertex];
			}
			else {
				temp = temp->link;
			}
		}
		if (top21 != NULL) {
			v = pop21();
			temp = g->adjList_H[v];
		}

	};

}

int main0210() {
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
	printf("\n ���� �켱Ž�� >>");

	DFS_adjList(G9,0);



	// ���� �Լ�����

	freeGraph2(G9);

	return 0;
}

