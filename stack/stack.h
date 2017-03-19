#ifndef STACK_H
#define STACK_H

typedef struct listnode {
	int elem;
	struct listnode *next;
} listnode;

typedef struct {
	listnode *head;
} stack;

void init_stack (stack *s);
void push (stack *s, int elem);
int pop (stack *s);
int is_empty (stack *s);

#endif
