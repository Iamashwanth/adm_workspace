#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"
#include "topologicalsort.h"

int main() {
	int x, i;
	graph g;
	initGraph(&g, true);
	readGraph(&g);
	printGraph(&g);
	printf("enter the first vertex to start transversal\n");
	scanf("%d", &x);
	initSearch(&g);
	initTime(&g);
	parent[x] = -1;
	DFS(&g, x, NULL, tsp_vertex_late, NULL);
}
