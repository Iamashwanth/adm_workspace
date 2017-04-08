#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_a_solution (int *a, int k, int n) {
	return k == n;
}

void construct_candidates (int *a, int k, int *c, int *ncandidates) {
	c[0] = 1;
	c[1] = 0;
	*ncandidates = 2;
}

void process_solution (int *a, int k) {
	int i;

	printf("{");
	for (i=1; i<=k; i++) {
		if (a[i] == 1) printf(" %d", i);
	}
	printf(" }\n");
}

void backtrack (int *a, int k, int n) {
	int c[2];
	int ncandidates;
	int i;

	if (is_a_solution(a, k, n))
		process_solution(a, k);
	else {
		k = k + 1;
		construct_candidates(a, k, c, &ncandidates);
		for (i=0; i<ncandidates; i++) {
			a[k] = c[i];
			backtrack(a, k, n);
		}
	}
}

void main() {
	int a[11];

	backtrack(a, 0, 10);
}
