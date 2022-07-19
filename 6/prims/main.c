#include "graph.h"

int main()
{
  
    FILE *fp = fopen("sample.txt","r");
 
    graph g;
    
    init_g(&g, fp);
    
    edge *edges = prim(g);
    print_mst(edges, g.size);
    int s;
    printf("Enter the source:");
    scanf("%d",&s);

    edge *edges1 = dijkstra(g,s);
    print_mst_dijkstra(edges1, g.size);
    return 0;
}