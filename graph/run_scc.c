#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"
#include "scc.h"

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
	init_scc(&g);
	parent[x] = -1;
	DFS(&g, x, scc_vertex_early, scc_vertex_late, scc_edge);
	scc_print(&g);
	for (i = 0; i < g.nvertices; i++) {
		printf("%d: %d %d\n", i, entry_time[i], exit_time[i]);
	}
}
