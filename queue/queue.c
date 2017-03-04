#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "queue.h"

void initQueue (queue *q) {
	q->head = q->tail = NULL;
}

int isEmpty (queue *q) {
	if (q->head == NULL || q->tail == NULL) return 1;
	else return 0;
}

void enqueue (queue *q, int elem) {
	listnode *node;
	node = (listnode *) malloc(sizeof(listnode));
	node->elem = elem;
	node->next = q->tail;
	q->tail = node;

	if (q->head == NULL) {
		q->head = node;
	}
}

int dequeue (queue *q) {
	listnode *iter, *node;
	int elem;

	if (q->head == q->tail) {
		node = q->head;
		q->head = q->tail = NULL;
	} else {
		iter = q->tail;
		while (iter->next != q->head) {
			iter = iter->next;
		}
		node = q->head;
		q->head = iter;
	}

	elem = node->elem;
	free(node);

	return elem;
}
