#ifndef GRAPH_H
#define GRPAH_H

#define MAX_V 100

#define WHITE 1
#define BLACK 0

typedef enum {
	UNDISCOVERED,
	DISCOVERED,
	PROCESSED
} edgestate;

typedef struct edgenode {
	int y;
	int weight;
	struct edgenode *next;
} edgenode;

typedef struct {
	int nvertices;
	int nedges;
	bool directed;
	edgenode *edges[MAX_V];
	int degree[MAX_V];
} graph;

extern edgestate *state;
extern int *parent;
extern int *color;

void initGraph (graph *g, bool directed);
void insertEdge (graph *g, int x, int y, int w, bool directed);
void readGraph (graph *g);
void printGraph (graph* g);
void initSearch(graph *g);
void BFS (graph *g, int start, void (*processEdge)(int x, int y));
void twoColor (graph *g, int start);
#endif
