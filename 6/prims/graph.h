#include <stdio.h>

typedef struct edge
{
    int src;
    int dest;
    int weight;
    struct edge *next;
} edge;



typedef struct graph
{
    edge **arr;
    int size;
} graph;



void init_g(graph *g, FILE *fp);



edge *prim(graph g);

void print_mst(edge *edges, int size);
edge *dijkstra(graph g, int src);
void print_mst_dijkstra(edge *edges, int size);