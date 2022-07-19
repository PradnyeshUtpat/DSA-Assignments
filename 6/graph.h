typedef struct node
{
    struct node* next;
    int weight, to;
}node;

typedef struct graph
{
    int n;
    node **A;
}graph;

typedef struct edge
{
    int src;
    int dest;
    int weight;
    struct edge *next;
} edge;

void init(graph *g, FILE *fp);

void display(graph g);

void display_matrix(graph g);

void display_degree(graph g);

void bfs(graph g,int s);

edge *prim(graph g, int s);

void delete_prim_arr(edge *arr, int n);

void delete_graph(graph *g);

void dfs(graph g,int s);