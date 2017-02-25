#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEM 100

typedef struct {
	int elem[MAX_ELEM];
	int count;
} heap;

int parent(int n) {
	if (n == 0) {
		return (-1);
	}
	return (n/2);
}

int child (int n) {
	return (n*2);
}

void swap (int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleUp (heap* hp, int n) {
	if (parent(n) == -1) return;

	if (hp->elem[parent(n)] > hp->elem[n]) {
		swap(&hp->elem[parent(n)], &hp->elem[n]);
		bubbleUp(hp, parent(n));
	}
}

void bubbleDown (heap* hp, int n) {
	int min, p, yc, i;
	min = p = n;
	yc = child(p);

	for (i=0; i<=1; i++) {
		if(yc+i < hp->count && hp->elem[yc+i] < hp->elem[min])
			min = yc+i;
	}

	if(min != p) {
		swap(&hp->elem[p], &hp->elem[min]);
		bubbleDown(hp, min);
	}
}

void insert (heap *hp, int item) {
	if( hp->count >= MAX_ELEM) {
		printf("Maximum number of items already inserted\n");
		return;
	}

	hp->elem[hp->count] = item;
	bubbleUp(hp, hp->count++);
}

int findMinimum(heap *hp) {
	return hp->elem[0];
}

void deleteMinimum(heap *hp) {
	if (hp->count == 0) {
		printf("No elements in the heap\n");
	}
	hp->elem[0] = hp->elem[hp->count-1];
	hp->count--;
	bubbleDown(hp, 0);
}

void printArray (int *arr, int size) {
	int i;
	for (i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	heap hp;
	int n, i, temp;
	memset(&hp, 0, sizeof(heap));

	printf("Enter the number of elements\n");
	scanf("%d", &n);

	for (i=0; i<n; i++) {
		scanf("%d", &temp);
		insert(&hp, temp);
	}

	printArray(hp.elem, n);

	for (i=0; i<n; i++) {
		printf("%d ", findMinimum(&hp));
		deleteMinimum(&hp);
	}
	printf("\n");
}
