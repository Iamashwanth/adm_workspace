#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"
#include "scc.h"
#include "stack.h"

int component_idx = 0;
int *scc = NULL;
int *reachable_ancestor = NULL;
int *child = NULL;
stack s;

void init_scc (graph* g) {
	init_stack(&s);
	scc = (int *) calloc(g->nvertices, sizeof(int));
	reachable_ancestor = (int *) calloc(g->nvertices, sizeof(int));
	child = (int *) calloc(g->nvertices, sizeof(int));
}

void pop_component (int x) {
	int t;

	component_idx++;
	scc[x] = component_idx;
	while (!is_empty(&s) && ((t = pop(&s)) != x)) {
		scc[t] = component_idx;
	}
}

void scc_vertex_early (int x) {
	reachable_ancestor[x] = x;
	push(&s, x);
}

void scc_edge (int x, int y) {
	edgeclass class;
	class = edgeClassify(x ,y);

	if (class == BACK) {
		if (entry_time[y] < entry_time[reachable_ancestor[x]])
			reachable_ancestor[x] = y;
	}

	if (class == CROSS) {
		if (scc[y] == 0) {
			if (entry_time[y] < entry_time[reachable_ancestor[x]])
				reachable_ancestor[x] = y;
		}
	}
}

void scc_vertex_late (int x) {

	printf("%d: parent: %d ancestor:%d pancestor:%d\n", x, parent[x], reachable_ancestor[x], reachable_ancestor[parent[x]]);

	if (reachable_ancestor[x] == x) {
		pop_component(x);
	}

	if (entry_time[reachable_ancestor[x]] < entry_time[reachable_ancestor[parent[x]]]) {
		reachable_ancestor[parent[x]] = reachable_ancestor[x];
	}
}

void scc_print (graph *g) {
	int i;
	for (i = 0; i < g->nvertices; i++) {
		printf("%d: %d\n", i, scc[i]);
	}
}
