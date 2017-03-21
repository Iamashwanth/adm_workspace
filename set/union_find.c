#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "union_find.h"

void set_union_init (set_union *s, int n) {
	int i;

	for (i=0; i<n; i++) {
		s->parent[i] = i;
		s->size[i] = 1;
	}

	s->n = n;
}

int find (set_union *s, int x) {
	if (s->parent[x] == x) return x;
	else return find(s, s->parent[x]);
}

void union_sets (set_union *s, int x, int y) {
	int r1, r2;

	r1 = find(s, x);
	r2 = find(s, y);

	if (r1 == r2) return;

	if (s->size[r1] < s->size[r2]) {
		s->size[r2] += s->size[r1];
		s->parent[r1] = r2;
	} else {
		s->size[r1] += s->size[r2];
		s->parent[r2] = r1;
	}
}

int same_component (set_union *s, int x, int y) {
	return (find(s,x) == find(s,y));
}
