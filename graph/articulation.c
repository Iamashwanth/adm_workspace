#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

int *reachable_ancestor = NULL;
int *child = NULL;

void initArticulation (graph* g) {
	reachable_ancestor = (int *) calloc(g->nvertices, sizeof(int));
	child = (int *) calloc(g->nvertices, sizeof(int));
}

void initAncestor (int x) {
	reachable_ancestor[x] = x;
}

void UpdateAncestor (int x, int y) {
	edgeclass class;
	class = edgeClassify(x ,y);

	if (class == TREE) {
		child[x]++;
	}

	if (class == BACK) {
		if (entry_time[y] < entry_time[reachable_ancestor[x]]) {
			reachable_ancestor[x] = y;
		}
	}
}

void processAncestor (int x) {

	printf("%d: parent: %d child: %d ancestor:%d pancestor:%d\n", x, parent[x], child[x], reachable_ancestor[x], reachable_ancestor[parent[x]]);

	if (parent[x] < 0) {
		if (child[x] > 1) {
			printf("Root articulation vertex: %d\n", x);
		}
		return;
	}

	if (reachable_ancestor[x] == parent[x] && !(parent[parent[x]] < 0)) {
		printf("Parent articulation vertex: %d\n", parent[x]);
	}

	if (reachable_ancestor[x] == x) {
		printf("Bridge articulation vertex: %d\n", parent[x]);

		if (child[x] != 0) {
			printf("Bridge articulation vertex: %d\n", x);
		}
	}

	if (entry_time[reachable_ancestor[x]] < entry_time[reachable_ancestor[parent[x]]]) {
		reachable_ancestor[parent[x]] = reachable_ancestor[x];
	}
}
