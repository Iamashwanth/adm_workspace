#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct listnode {
	int elem;
	struct listnode *next;
} listnode;

typedef struct {
	listnode *head;
	listnode *tail;
} queue;

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

int main() {
	queue q;
	int x;

	initQueue(&q);

	printf("Enter the numbers into queue\n");

	while (scanf("%d", &x) != EOF) {
		enqueue(&q, x);
	}

	printf("\n####\n");

	while (!isEmpty(&q)) {
		printf("%d ", dequeue(&q));
	}

	printf("\n");
}
