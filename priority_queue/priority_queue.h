#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define ARR_MAX 100

typedef struct {
	void *unsorted_arr[ARR_MAX];
	int min_idx;
	int n;
	int (*compare)(void *x, void *y);
} prio_q;

void init_prio_q (prio_q *pq, int (*compare)(void *x, void *y));
void insert_elem (prio_q *pq, void *elem);
void* find_min (prio_q *pq);
void delete_min (prio_q *pq);

#endif
