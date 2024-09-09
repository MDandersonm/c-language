#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#define MAX_VERTEX1 30

typedef struct graphNode {
	int vertex;
	struct graphNode* link;

} graphNode;


typedef struct graphType1 {
	int n; // 그래프의 정점의 개수
	graphNode* adjList_H[MAX_VERTEX1];//그래프 정점에 대한 헤드노드배열
} graphType1;

//공백그래프 생성
void createGraph1(graphType1* g) {
	g->n = 0;

	for (int i = 0; i < MAX_VERTEX1; i++) {
		g->adjList_H[i] = NULL;
	};
}

//그래프에 정점v를 삽입하는 연산.
void insertVertex1(graphType1* g, int v) {

	if (((g->n) + 1) > MAX_VERTEX1) {
		printf("\n 그래프 정점의 개수를 초과");
		return;
	}
	
	g->n +=1;
	g->adjList_H[v] = NULL;
	//에러 . 여기서 노드를 생성하면 안되지. 헤드는 노드가 아님.
	//g->adjList_H[v] = (graphNode*)malloc(sizeof(graphNode));
	//
}



void insertEdge1(graphType1* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다.");
		return;
	}
	graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
	newNode->vertex = v;
	graphNode* temp = g->adjList_H[u];//헤드가 가리키는거
	g->adjList_H[u]= newNode;//첫부분으로 삽입
	newNode->link = temp;
	
};


void print_adjList(graphType1* g) {
	for (int i = 0; i < g->n; i++) {
		printf("\n 정점 %c 의 인접 리스트 ", i+'A');
		graphNode* temp = g->adjList_H[i];
		while(temp != NULL) {
			printf("-> %c ", temp->vertex+'A');
			temp = temp->link;
		};
	};

}

void freeGraph(graphType1* g) {
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


int main0200() {
	int i;
	graphType1* G1 = (graphType1*)malloc(sizeof(graphType1));
	graphType1* G2 = (graphType1*)malloc(sizeof(graphType1));
	graphType1* G3 = (graphType1*)malloc(sizeof(graphType1));
	graphType1* G4 = (graphType1*)malloc(sizeof(graphType1));
	graphType1* G9 = (graphType1*)malloc(sizeof(graphType1));
	createGraph1(G1);

	for (i = 0; i < 4; i++) {
		insertVertex1(G1, i);
	}//0 1 2 3 번 노드를 만듦

	insertEdge1(G1, 0, 3);
	insertEdge1(G1, 0, 1);
	insertEdge1(G1, 1, 3);
	insertEdge1(G1, 1, 2);
	insertEdge1(G1, 1, 0);
	insertEdge1(G1, 2, 3);
	insertEdge1(G1, 2, 1);
	insertEdge1(G1, 3, 2);
	insertEdge1(G1, 3, 1);
	insertEdge1(G1, 3, 0);
	printf("\n G1의 인접리스트");
	print_adjList(G1);


	createGraph1(G2);

	for (i = 0; i < 3; i++) {
		insertVertex1(G2, i);
	}//0 1 2  번 노드를 만듦


	insertEdge1(G2, 0, 2);
	insertEdge1(G2, 0, 1);
	insertEdge1(G2, 1, 2);
	insertEdge1(G2, 1, 0);
	insertEdge1(G2, 2, 1);
	insertEdge1(G2, 2, 0);
	printf("\n G2의 인접리스트");
	print_adjList(G2);


	createGraph1(G3);

	for (i = 0; i < 4; i++) {
		insertVertex1(G3, i);
	}//0 1 2 3 번 노드를 만듦
	insertEdge1(G3, 0, 3);
	insertEdge1(G3, 0, 1);
	insertEdge1(G3, 1, 3);
	insertEdge1(G3, 1, 2);
	insertEdge1(G3, 2, 3);
	printf("\n G3의 인접리스트");
	print_adjList(G3);


	createGraph1(G4);

	for (i = 0; i < 3; i++) {
		insertVertex1(G4, i);
	}//0 1 2 3 번 노드를 만듦

	insertEdge1(G4, 0, 2);
	insertEdge1(G4, 0, 1);
	insertEdge1(G4, 1, 2);
	insertEdge1(G4, 1, 0);
	printf("\n G4의 인접리스트");
	print_adjList(G4);




	// 메인 함수에서
	freeGraph(G1);
	freeGraph(G2);
	freeGraph(G3);
	freeGraph(G4);


	return 0;
}

