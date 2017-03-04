#ifndef QUEUE_H
#define QUEUE_H

typedef struct listnode {
	int elem;
	struct listnode *next;
} listnode;

typedef struct {
	listnode *head;
	listnode *tail;
} queue;

void initQueue (queue *q);
int isEmpty (queue *q);
void enqueue (queue *q, int elem);
int dequeue (queue *q);

#endif
