/*
 * Prim's Algorithm for minimum spanning trees.
 * start with an arbitrary vertex
 * Go throguh the neighbour list and update the distaces to each non-tree vertex.
 * Add the edge with the min distance.
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "graph.h"

int *distance = NULL;
int *in_tree = NULL;

void init_dijkstra (graph *g) {
	int i;

	distance = (int *) calloc(g->nvertices, sizeof(int));
	in_tree = (int *) calloc(g->nvertices, sizeof(int));

	for (i=0; i<g->nvertices; i++) {
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
}

find_path (int x) {
	if (parent[x] == -1) {
		printf("%d", x);
		return;
	} else {
		printf("%d->", x);
		find_path(parent[x]);
	}
}

print_paths (graph *g) {
	int i;

	for (i=0; i<g->nvertices; i++) {
		find_path(i);
		printf(" : d = %d\n", distance[i]);
	}
}

dijkstra (graph *g, int start) {
	edgenode *temp;
	int x, y, w, i, d, next_v;

	init_dijkstra(g);
	x = start;
	distance[x] = 0;

	while (in_tree[x] == 0) {
		in_tree[x] = 1;
		temp = g->edges[x];

		while (temp != NULL) {
			y = temp->y;
			w = temp->weight;

			if ((distance[x] + w) < distance[y]) {
				distance[y] = distance[x] + w;
				parent[y] = x;
			}
			temp = temp->next;
		}

		d = INT_MAX;
		for (i=0; i<g->nvertices; i++) {
			if (distance[i] < d && in_tree[i] == 0) {
				d = distance[i];
				next_v = i;
			}
		}
		if (in_tree[next_v] == 0)
			printf("%d: Next Edge %d->%d, distance:%d\n", x, parent[next_v], next_v, d);
		x = next_v;
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
	initSearch(&g);
	dijkstra(&g, x);
	print_paths(&g);
}
