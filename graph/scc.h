#ifndef SCC_H
#define SCC_H

void init_scc (graph* g);
void scc_vertex_early (int x);
void scc_edge (int x, int y);
void scc_vertex_late (int x);
void scc_print (graph *g);

#endif
