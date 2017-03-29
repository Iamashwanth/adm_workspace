all: run_bfs run_dfs run_topologicalsort run_scc prim dijkstra kruskal

run_scc: run_scc.o scc.o graph.o stack.o queue.o
	gcc run_scc.o graph.o queue.o stack.o scc.o -o run_scc

run_topologicalsort: run_topologicalsort.o topologicalsort.o graph.o queue.o
	gcc run_topologicalsort.o graph.o queue.o topologicalsort.o -o run_topologicalsort

run_bfs: run_bfs.o graph.o queue.o
	gcc run_bfs.o graph.o queue.o -o run_bfs

run_dfs: run_dfs.o graph.o queue.o articulation.o
	gcc run_dfs.o graph.o queue.o articulation.o -o run_dfs

kruskal: kruskal.o graph.o queue.o priority_queue.o union_find.o
	gcc kruskal.o priority_queue.o union_find.o graph.o queue.o -o kruskal

kruskal.o:
	gcc -c -I ./ -I ../priority_queue -I ../set kruskal.c

prim: prim.o graph.o queue.o
	gcc prim.o graph.o queue.o -o prim

dijkstra: dijkstra.o graph.o queue.o
	gcc dijkstra.o graph.o queue.o -o dijkstra

run_topologicalsort.o:
	gcc -I ./ -c run_topologicalsort.c

run_bfs.o:
	gcc -I ./ -c run_bfs.c

run_dfs.o:
	gcc -I ./ -c run_dfs.c

scc.o:
	gcc -I ../stack -c scc.c

prim.o:
	gcc -I ./ -c prim.c

topologicalsort.o:
	gcc -I ./ -c topologicalsort.c

articulation.o:
	gcc -I ./ -c articulation.c

priority_queue.o:
	gcc -I ../priority_queue -c ../priority_queue/priority_queue.c

union_find.o:
	gcc -I ../set -c ../set/union_find.c

graph.o:
	gcc -I ../queue -c graph.c

queue.o:
	gcc -I ../queue -c ../queue/queue.c

stack.o:
	gcc -I ../stack -c ../stack/stack.c

clean:
	rm *o run_bfs run_dfs run_topologicalsort run_scc prim dijkstra kruskal
