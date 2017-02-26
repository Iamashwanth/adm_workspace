#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_V 100

typedef struct edgenode {
	int y;
	int weight;
	struct edgenode *next;
} edgenode;

typedef struct {
	int nvertices;
	int nedges;
	bool directed;
	edgenode *edges[MAX_V];
	int degree[MAX_V];
} graph;

void initGraph (graph *g, bool directed) {
	int i ;
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;

	for (i = 0; i < MAX_V; i++) {
		g->edges[i] = NULL;
		g->degree[i] = 0;
	}
}

void insertEdge (graph *g, int x, int y, int w, bool directed) {
	edgenode *node;

	node = (edgenode *) malloc(sizeof(edgenode));

	node->y = y;
	node->weight = w;
	node->next = g->edges[x];
	g->edges[x] = node;
	g->degree[x]++;

	if (!directed) {
		insertEdge(g, y, x, w, true);
	} else {
		g->nedges++;
	}
}

void readGraph (graph *g) {
	int m, i, x, y, w;

	printf("Enter the number of vertices and edges\n");
	scanf("%d %d", &(g->nvertices), &m);

	printf("Now enter the edges and their weights\n");

	for ( i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		insertEdge(g, x, y, w, g->directed);
	}
}

void printGraph (graph* g) {
	int i;
	edgenode *n;

	for (i = 0; i < g->nvertices; i++) {
		printf("%d: ", i);
		n = g->edges[i];
		while (n != NULL) {
			printf("%d ", n->y);
			n = n->next;
		}
		printf("\n");
	}
}

int main() {
	graph g;
	initGraph(&g, false);
	readGraph(&g);
	printGraph(&g);
}
