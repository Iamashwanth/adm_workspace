/*
 * Kruskal's Algorithm for minimum spanning trees.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"
#include "priority_queue.h"
#include "union_find.h"

typedef struct {
	int x;
	int y;
	int w;
} edge_pair;

void to_edge_array(graph *g, prio_q *pq) {
	int i;
	edgenode *n;
	edge_pair *temp;

	for (i = 0; i < g->nvertices; i++) {
		n = g->edges[i];
		while (n != NULL) {
			temp = (edge_pair *) malloc(sizeof(edgenode));
			temp->x = i;
			temp->y = n->y;
			temp->w = n->weight;
			insert_elem(pq, temp);
			n = n->next;
		}
	}
}

int compare_edge_weight (void *x, void *y) {
	return ((edge_pair*)x)->w - ((edge_pair*)y)->w;
}

void kruskal (graph *g) {
	int i;
	set_union s;
	prio_q pq;
	edge_pair *e;

	init_prio_q(&pq, compare_edge_weight);
	set_union_init(&s, g->nvertices);

	to_edge_array(g, &pq);

	for (i=0; i<g->nedges; i++) {
		e = find_min(&pq);
		if(!same_component(&s, e->x, e->y)) {
			printf("edge %d -> %d in MST\n", e->x, e->y);
			union_sets(&s, e->x, e->y);
		}
		delete_min(&pq);
	}
}

void main() {
	int x;
	graph g;
	initGraph(&g, true);
	readGraph(&g);
	printGraph(&g);
	kruskal(&g);
}
