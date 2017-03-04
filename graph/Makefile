all: graph

graph: graph.o queue.o
	gcc graph.o queue.o -o graph

graph.o:
	gcc -I ../queue -c graph.c

queue.o:
	gcc -I ../queue -c ../queue/queue.c

clean:
	rm *o graph
