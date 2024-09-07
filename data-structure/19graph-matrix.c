#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30


typedef struct graphType {
	int n; // 그래프의 정점의 개수
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];

} graphType;

void createGraph(graphType* g) {
	g->n = -1;
	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX;j++) {
			g->adjMatrix[i][j]=0;
		}
	};
	
}
void insertVertex(graphType* g, int v) {
	if (g->n + 1 >= MAX_VERTEX) {
		printf("Error: 초과할 수 있는 최대 정점 수를 넘음\n");
		return;
	}
	g->n++;

}
void insertEdge(graphType* g, int u, int v) {
	if (u > g->n || v > g->n || u < 0 || v < 0) {
		printf("Error: 잘못된 정점 인덱스\n");
		return;
	}
	if (g->adjMatrix[u][v] == 0) {
		g->adjMatrix[u][v] = 1;
	}
	
};


void print_adjMatrix(graphType* g) {
	for (int i = 0; i <= g->n; i++) {
		for (int j = 0; j <= g->n; j++) {
			printf("%d ", g->adjMatrix[i][j]);
		}
		printf("\n");
	};
	printf("----\n");


}
int main0190() {
	graphType* G1=(graphType*)malloc(sizeof(graphType));
	graphType* G3 = (graphType*)malloc(sizeof(graphType));

	createGraph(G1); 
	createGraph(G3);

	for (int i = 0; i < 4; i++) {
		insertVertex(G1, i);
	}
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 3, 0);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 2);
	printf("\nG1의 인접행렬\n");
	print_adjMatrix(G1);


	for (int i = 0; i < 4; i++) {
		insertVertex(G3, i);
	}
	insertEdge(G3, 0, 1);
	insertEdge(G3, 0, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 2, 3);
	printf("\nG3의 인접행렬\n");
	print_adjMatrix(G3);




	return 0;
}