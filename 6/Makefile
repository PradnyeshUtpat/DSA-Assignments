all : graph.o main.o queue.o stack.o
	cc graph.o main.o queue.o stack.o -o run
graph.o : graph.c graph.h queue.h stack.h
	cc -c graph.c
main.o : main.c graph.h
	cc -c main.c
queue.o : queue.c queue.h
	cc -c queue.c
stack.o : stack.c stack.h
	cc -c stack.c
