#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"
#include "graph.h"

edgestate *state = NULL;
int *parent = NULL;
int *color = NULL;
int *entry_time = NULL;
int *exit_time = NULL;
int time;

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

void initSearch (graph* g) {
	state = (edgestate *) calloc(g->nvertices, sizeof(edgestate));
	parent = (int *) calloc(g->nvertices, sizeof(int));
}

void initTime (graph* g) {
	entry_time = (int *) calloc(g->nvertices, sizeof(int));
	exit_time = (int *) calloc(g->nvertices, sizeof(int));
}

void BFS (graph *g, int start, void (*processEdge)(int x, int y)) {
	int x;
	edgenode *temp;
	queue q;

	state[start] = DISCOVERED;

	initQueue(&q);
	enqueue(&q, start);

	while (!isEmpty(&q)) {
		x = dequeue(&q);

		// Do preprocessing on the vertex

		temp = g->edges[x];

		while (temp != NULL) {
			if ((state[temp->y] != PROCESSED) || g->directed) {
				if (processEdge != NULL) {
					(*processEdge)(x, temp->y);
				}
			}
			if (state[temp->y] == UNDISCOVERED) {
				state[temp->y] = DISCOVERED;

				parent[temp->y] = x;
				enqueue(&q , temp->y);
			}
			temp = temp->next;
		}

		state[x] = PROCESSED;
		// Do postprocessing on the vertex
	}
}

void DFS (graph *g, int start, void (*processVertexEarly)(int x), void (*processVertexLate)(int x), void (*processEdge)(int x, int y)) {
	edgenode *temp;
	state[start] = DISCOVERED;
	temp = g->edges[start];

	entry_time[start] = ++time;
	if (processVertexEarly) {
		processVertexEarly(start);
	}

	while (temp != NULL) {
		if (state[temp->y] == UNDISCOVERED) {
			parent[temp->y] = start;
			if (processEdge) {
				(*processEdge)(start, temp->y);
			}
			DFS(g, temp->y, processVertexEarly, processVertexLate, processEdge);
		} else if ((state[temp->y] != PROCESSED) || g->directed) {
			if (processEdge) {
				(*processEdge)(start, temp->y);
			}
		}
		temp = temp->next;
	}

	if (processVertexLate) {
		processVertexLate(start);
	}

	exit_time[start] = ++time;
	state[start] = PROCESSED;
}

void complementColor (int x, int y) {
	if (color[x] == WHITE) color[y] = BLACK;
	else if (color[x] == BLACK) color[y] = WHITE;
}

void twoColor(graph *g, int start) {
	int i;

	color = (int *) calloc(g->nvertices, sizeof(int));

	for (i = 0; i < g->nvertices; i++) {
		color[i] = -1;
	}

	initSearch(g);
	color[start] = WHITE;
	BFS(g, start, complementColor);

	printf("\n");
	for (i = 0; i < g->nvertices; i++) {
		printf("%d", color[i]);
	}
	printf("\n");
}

edgeclass edgeClassify (int x, int y) {
	if (parent[y] == x) {
		return TREE;
	} else if (parent[x] == y) {
		return CLASS_MAX;
	} else if (state[y] == DISCOVERED) {
		return BACK;
	}
	return CLASS_MAX;
}

void printEdge (int x, int y) {
	printf("Edge %d to %d\n", x, y);
}

void checkBackEdge (int x, int y) {
	printEdge(x, y);
	if (parent[x] != y) {
		printf("Found cycle from %d to %d\n", x, y);
	}
}
