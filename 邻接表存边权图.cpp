#include<stdio.h>
#include<iostream>
#include<malloc.h>
#define maxSize 1000
using namespace std;
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	int info;
}ArcNode;

typedef struct {
	int data;
	ArcNode* firstarc;
}Vnode;

typedef struct {
	Vnode adjlist[maxSize];
	int n, e;
}AGraph;

AGraph* graph;
void  insertNode(ArcNode* node, ArcNode* newNode) {
	ArcNode* p = node;
	while (p->nextarc != NULL) {
		p = p->nextarc;
	}
	p->nextarc = newNode;
}

void create() {
	graph = (AGraph*)malloc(sizeof(AGraph));
	cout << "输入顶点的数目: " << endl;
	cin >> graph->n;
	cout << "输入图中边的数目: " << endl;
	cin >> graph->e;
	cout << graph->n << " ";
	int u = -1, v = -1, weight = -1;
	for (int i = 0; i < graph->n; i++) {
		graph->adjlist[i].firstarc = NULL;
	}
	ArcNode* node;
	cout << graph->e << endl;
	for (int i = 0; i < graph->e; i++) {
		cin >> u >> v >> weight;
		node = (ArcNode*)malloc(sizeof(ArcNode));
		node->adjvex = v;
		node->info = weight;
		node->nextarc = NULL;
		graph->adjlist[u].data = u;
		if (graph->adjlist[u].firstarc == NULL) {
			//边 
			graph->adjlist[u].firstarc = node;
		}
		else {
			//插入边
			insertNode(graph->adjlist[u].firstarc, node);
		}
	}
}

void  travseTree() {
	for (int i = 0; i < graph->n; i++) {
		if (graph->adjlist[i].firstarc != NULL) {
			cout << i << " ";
			ArcNode* p = graph->adjlist[i].firstarc;
			while (p != NULL) {
				cout << p->adjvex << " ";
				p = p->nextarc;
			}
			cout << endl;
		}
	}
}

int main(void) {
	create();
	travseTree();
	return 0;
}