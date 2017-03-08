#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "graph.h"

int main() {
	int x;
	graph g;
	initGraph(&g, false);
	readGraph(&g);
	printGraph(&g);
	printf("enter the first vertex to start transversal\n");
	scanf("%d", &x);
	initSearch(&g);
	BFS(&g, x, NULL);
	twoColor(&g, x);
}
