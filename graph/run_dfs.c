#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"

int main() {
	int x, i;
	graph g;
	initGraph(&g, false);
	readGraph(&g);
	printGraph(&g);
	printf("enter the first vertex to start transversal\n");
	scanf("%d", &x);
	initSearch(&g);
	initTime(&g);
	DFS(&g, x, printEdge, checkBackEdge);
	for (i = 0; i < g.nvertices; i++) {
		printf("%d: %d %d\n", i, entry_time[i], exit_time[i]);
	}
}
