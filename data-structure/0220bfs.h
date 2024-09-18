#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef BFS_H
#define BFS_H
#include <stdio.h>
#include <stdlib.h> //malloc사용
#include <string.h>
#define MAX_VERTEX2 10
#define FALSE 0
#define TRUE 1


typedef struct graphNode {
	int vertex;
	struct graphNode* link;

} graphNode;


typedef struct graphType2 {
	int n; // 그래프의 정점의 개수
	graphNode* adjList_H[MAX_VERTEX2];//그래프 정점에 대한 헤드노드배열
	int visited[MAX_VERTEX2]; // 정점에 대한 방문 표시를 위한 배열
} graphType2;

void createGraph2(graphType2* g);
void insertVertex2(graphType2* g, int v);
void insertEdge2(graphType2* g, int u, int v);
void print_adjList2(graphType2* g);
void freeGraph2(graphType2* g);
#endif