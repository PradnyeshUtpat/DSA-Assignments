
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

void init(graph *g, FILE *fp)
{
    int n,i,j,d;
    fscanf(fp, "%d", &n);
    g->n=n;
    g->A=(node **)malloc(sizeof(node )* n);
    for(i=0;i<n;i++)
        g->A[i]=NULL;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp, "%d", &d);
            if(d!=0)
            {
              node *temp=(node*)malloc(sizeof(node));
              temp->to=j;
              temp->weight=d;
              if(g->A[i]==NULL)
              {
                  g->A[i]=temp;
                  temp->next=NULL;
              }    
              else
              {
                  temp->next=g->A[i];
                  g->A[i]=temp;
              }
            }
        }
    }
}
void display_matrix(graph g)
{
 int i, j, M[g.n][g.n];
 for(i=0;i<g.n;i++)
  for(j=0;j<g.n;j++)
   M[i][j]=0;
 for(i=0;i<g.n;i++)
 {
  node *temp=g.A[i];
  while(temp)
  {
   M[i][temp->to]=temp->weight;
   temp=temp->next;
  }
 }
 for(i=0;i<g.n;i++)
 {
  for(j=0;j<g.n;j++)
   printf("%d ",M[i][j]);
  printf("\n");
 }
}



void display(graph g)
{
    int i;
    node *temp;
    for(i=0;i<g.n;i++)
    {
        temp=g.A[i];
        printf("%d -> ",i);
        while(temp)
        {
            printf("(%d, %d) ",temp->to, temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}



void display_degree(graph g){
for(int i=0;i<g.n;i++)
{int count = 0;
  node *temp=g.A[i];
  while(temp)
  {
    temp=temp->next;
    count++;
    
  }
  printf("degree of vertex %d is %d \n",i,count);
 }
}

void bfs(graph g,int s)
{
  Queue q;
  init_Q(&q, g.n);
  int *visited = calloc(g.n, sizeof(int)), v;
  enqueue(&q, s);
  visited[s] = 1;
  printf("%d ",s);
  while(!isEmpty(q))
  {
   v= dequeue(&q);
   node *temp=g.A[v];
    while(temp)
    {
      if(!visited[temp->to])
      {
        printf("%d ",temp->to);
        visited[temp->to]=1;
           enqueue(&q, temp->to);
    }
    temp=temp->next;
  }
   }
  printf("\n");
  free(visited);
  free(q);
  return;
}

void dfs(graph g,int s)
{
  Stack st;
  init_stack(&st, g.n);
  int *visited = calloc(g.n, sizeof(int)), v;
  push(&st, s);
  visited[s] = 1;
  printf("%d ",s);
  while(!isEmpty_s(st))
  {
   v= pop(&st);
   node *temp=g.A[v];
    while(temp)
    {
      if(!visited[temp->to])
      {
        printf("%d ",temp->to);
        visited[temp->to]=1;
           push(&st, temp->to);
    }
    temp=temp->next;
  }
   }
  printf("\n");
  free(visited);
  free(st);
  return;
}