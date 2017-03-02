#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_V 100

typedef enum {
	UNDISCOVERED,
	DISCOVERED,
	PROCESSED
} edgestate;

typedef struct listnode {
	int elem;
	struct listnode *next;
} listnode;

typedef struct edgenode {
	int y;
	int weight;
	struct edgenode *next;
} edgenode;

typedef struct {
	listnode *head;
	listnode *tail;
} queue;

typedef struct {
	int nvertices;
	int nedges;
	bool directed;
	edgenode *edges[MAX_V];
	int degree[MAX_V];
} graph;

void initQueue (queue *q) {
	q->head = q->tail = NULL;
}

int isEmpty (queue *q) {
	if (q->head == NULL || q->tail == NULL) return 1;
	else return 0;
}

void enqueue (queue *q, int elem) {
	listnode *node;
	node = (listnode *) malloc(sizeof(listnode));
	node->elem = elem;
	node->next = q->tail;
	q->tail = node;

	if (q->head == NULL) {
		q->head = node;
	}
}

int dequeue (queue *q) {
	listnode *iter, *node;
	int elem;

	if (q->head == q->tail) {
		node = q->head;
		q->head = q->tail = NULL;
	} else {
		iter = q->tail;
		while (iter->next != q->head) {
			iter = iter->next;
		}
		node = q->head;
		q->head = iter;
	}

	elem = node->elem;
	free(node);

	return elem;
}

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

void BFS (graph *g, int start) {
	int x, *parent;
	edgenode *temp;
	edgestate *state;
	queue q;

	state = (edgestate *) calloc(g->nvertices, sizeof(edgestate));
	parent = (int *) calloc(g->nvertices, sizeof(int));

	state[start] = DISCOVERED;

	initQueue(&q);
	enqueue(&q, start);

	while (!isEmpty(&q)) {
		x = dequeue(&q);
		printf("Processing vertex %d\n", x);

		temp = g->edges[x];

		while (temp != NULL) {
			if (state[temp->y] == UNDISCOVERED) {
				state[temp->y] = DISCOVERED;
				parent[temp->y] = x;
				enqueue(&q , temp->y);
			}
			temp = temp->next;
		}

		state[x] = PROCESSED;
	}
}

int main() {
	int x;
	graph g;
	initGraph(&g, false);
	readGraph(&g);
	printGraph(&g);
	printf("enter the first vertex to start transversal\n");
	scanf("%d", &x);
	BFS(&g, x);
}
