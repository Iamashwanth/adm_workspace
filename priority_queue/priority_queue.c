#include <stdlib.h>
#include <stdio.h>

#include "priority_queue.h"

#define ARR_MAX 100

void init_prio_q (prio_q *pq, int (*compare)(void *x, void *y)) {
	pq->min_idx = -1;
	pq->n = 0;
	pq->compare = compare;
}

void insert_elem (prio_q *pq, void *elem) {
	if (pq->min_idx == -1 || (pq->compare(elem, pq->unsorted_arr[pq->min_idx]) < 0)) {
		pq->min_idx = pq->n;
	}
	pq->unsorted_arr[(pq->n)++] = elem;
}

void* find_min (prio_q *pq) {
	return pq->unsorted_arr[pq->min_idx];
}

void delete_min (prio_q *pq) {
	int i, del_idx, min_idx;
	del_idx = pq->min_idx;
	min_idx = 0;

	if (pq->n < 1)  return;

	for (i=0; i<del_idx; i++) {
		if (pq->compare(pq->unsorted_arr[i], pq->unsorted_arr[min_idx]) < 0)
			min_idx = i;
	}

	free(pq->unsorted_arr[i]);
	pq->n--;

	for (; i<pq->n; i++) {
		pq->unsorted_arr[i] = pq->unsorted_arr[i+1];
		if (pq->compare(pq->unsorted_arr[i], pq->unsorted_arr[min_idx]) < 0)
			min_idx = i;
	}

	pq->min_idx = min_idx;
}
