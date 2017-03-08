all: run_bfs

run_bfs: run_bfs.o graph.o queue.o
	gcc run_bfs.o graph.o queue.o -o run_bfs

run_bfs.o:
	gcc -I ./ -c run_bfs.c

graph.o:
	gcc -I ../queue -c graph.c

queue.o:
	gcc -I ../queue -c ../queue/queue.c

clean:
	rm *o run_bfs
