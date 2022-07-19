#include <stdlib.h>
#include <limits.h>
#include "graph.h"

void init_g(graph *g, FILE*fp)
{   int n,i,j,d;
    fscanf(fp, "%d", &n);
    g->size=n;
    g->arr=(edge **)malloc(sizeof(edge )* n);
    for(i=0;i<n;i++)
        g->arr[i]=NULL;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp, "%d", &d);
            if(d!=0)
            {
              edge*temp=(edge*)malloc(sizeof(edge));
              temp->src=i;
              temp->dest=j;
              temp->weight=d;
              if(g->arr[i]==NULL)
              {
                  g->arr[i]=temp;
                  temp->next=NULL;
              }    
              else
              {
                  temp->next=g->arr[i];
                  g->arr[i]=temp;
              }
            }
        }
    }
    
}




void print_graph(graph g)
{
    printf("Matrix representation of the graph --->\n");
    edge *ptr;
    for (int i = 0; i < g.size; i++)
    {
        ptr = g.arr[i];

        printf("Vertice %d --> ", i);
        while (ptr != NULL)
        {
            printf("%d|%d -> ", ptr->dest, ptr->weight);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

edge *prim(graph g)
{
    edge *ptr = NULL;
    int *visited = (int *)calloc(g.size - 1, sizeof(int));

    edge min_edge;
    int min_weight;
    edge *edges = (edge *)malloc(sizeof(edge) * g.size - 1);

    min_edge.src = g.arr[0]->src;
    min_edge.dest = g.arr[0]->dest;
    min_edge.weight = g.arr[0]->weight;
    min_weight = min_edge.weight;
    visited[0] = 1;
    for (int i = 0; i < g.size; i++)
    {
        min_weight = INT_MAX;
        for (int j = 0; j < g.size; j++)
        {
            ptr = g.arr[j];
            while (ptr != NULL)
            {
                if (ptr->weight < min_weight)
                {

                    if (visited[ptr->src] == 1 && visited[ptr->dest] == 0)
                    {
                        min_edge.src = ptr->src;
                        min_edge.dest = ptr->dest;
                        min_edge.weight = ptr->weight;
                        min_weight = ptr->weight;
                    }
                }
                ptr = ptr->next;
            }
        }
        visited[min_edge.dest] = 1;
        edges[i] = min_edge;
    }
    return edges;
}

void print_mst(edge *edges, int size)
{
    printf("-----Prim's mst: -----\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d %d %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

edge *dijkstra(graph g, int src)
{
    int *visited = (int *)calloc(g.size, sizeof(int));

    int *cost = (int *)malloc(sizeof(int) * g.size);

    visited[src] = 1;

    edge *edges = (edge *)malloc(sizeof(edge) * g.size - 1);

    for (int i = 0; i < g.size; i++)
    {
        cost[i] = INT_MAX;
    }

    cost[src] = 0;
    edge *ptr = g.arr[0];
    int min_weight = INT_MAX;
    edge min_edge;
    int crr;

    for (int i = 0; i < g.size; i++)
    {
        crr = 0;
        min_weight = INT_MAX;
        for (int j = 0; j < g.size; j++)
        {
            ptr = g.arr[j];
            while (ptr != NULL)
            {
                if (visited[ptr->src] == 1 && visited[ptr->dest] == 0 && cost[ptr->src] + ptr->weight < cost[ptr->dest])
                {
                    cost[ptr->dest] = cost[ptr->src] + ptr->weight;                                              //relaxation
                }

                if (visited[ptr->src] == 1 && visited[ptr->dest] == 0 && ptr->weight < min_weight)
                {
                    min_edge.src = ptr->src;
                    min_edge.dest = ptr->dest;
                    min_edge.weight = cost[ptr->dest];
                    min_weight = ptr->weight;
                }
                ptr = ptr->next;
            }
        }
        edges[i] = min_edge;
        visited[min_edge.dest] = 1;
    }
    return edges;
}

void print_mst_dijkstra(edge *edges, int size)
{
    printf("-----Dijkstra's mst: -----\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d %d %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }

}