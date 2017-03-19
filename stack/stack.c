#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"

void init_stack (stack *s) {
	s->head = NULL;
}

int is_empty (stack *s) {
	if (s->head == NULL) return 1;
	else return 0;
}

void push (stack *s,  int elem) {
	listnode *node;
	node = (listnode *) malloc(sizeof(listnode));
	node->elem = elem;
	node->next = s->head;
	s->head = node;
}

int pop (stack *s) {
	listnode *iter, *node;
	int elem;

	node = s->head;
	s->head = node->next;

	elem = node->elem;
	free(node);

	return elem;
}
