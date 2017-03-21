#ifndef UNION_FIND_H
#define UNION_FIND_H

#define SET_MAX 100

typedef struct {
	int parent[SET_MAX];
	int size[SET_MAX];
	int n;
} set_union;

void set_union_init (set_union *s, int n);
int find (set_union *s, int x);
void union_sets (set_union *s, int x, int y);
int same_component (set_union *s, int x, int y);
#endif
