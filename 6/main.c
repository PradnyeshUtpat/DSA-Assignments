#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main(){

graph g;
FILE *fp ;
fp = fopen("graph.txt","r");

if(!fp){
    printf("could not open file");
}

init(&g,fp);
display(g);
printf("\n");
display_matrix(g);
printf("\n");
display_degree(g);
printf("\n");
printf("bfs traversal : ");
bfs(g,0);
printf("dfs traversal : ");
dfs(g,0);
}