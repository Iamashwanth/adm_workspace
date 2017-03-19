all: run_bfs run_dfs run_topologicalsort run_scc

run_scc: run_scc.o scc.o graph.o stack.o queue.o
	gcc run_scc.o graph.o queue.o stack.o scc.o -o run_scc

run_topologicalsort: run_topologicalsort.o topologicalsort.o graph.o queue.o
	gcc run_topologicalsort.o graph.o queue.o topologicalsort.o -o run_topologicalsort

run_bfs: run_bfs.o graph.o queue.o
	gcc run_bfs.o graph.o queue.o -o run_bfs

run_dfs: run_dfs.o graph.o queue.o articulation.o
	gcc run_dfs.o graph.o queue.o articulation.o -o run_dfs

run_topologicalsort.o:
	gcc -I ./ -c run_topologicalsort.c

run_bfs.o:
	gcc -I ./ -c run_bfs.c

run_dfs.o:
	gcc -I ./ -c run_dfs.c

scc.o:
	gcc -I ../stack -c scc.c

topologicalsort.o:
	gcc -I ./ -c topologicalsort.c

articulation.o:
	gcc -I ./ -c articulation.c

graph.o:
	gcc -I ../queue -c graph.c

queue.o:
	gcc -I ../queue -c ../queue/queue.c

stack.o:
	gcc -I ../stack -c ../stack/stack.c

clean:
	rm *o run_bfs run_dfs run_topologicalsort run_scc
