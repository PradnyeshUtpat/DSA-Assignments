#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void init_Q(Queue *Q,int size){
    (*Q) = (Queue)malloc(sizeof(queue));
    (*Q)->size = size;
    (*Q)->rear = (*Q)->front = 0;
    (*Q)->a = (int *)malloc(sizeof(int)*(*Q)->size);
    
    
}
int isEmpty(Queue Q){
    if(Q == NULL)
        return 0;
    if(Q->rear == Q->front)
        return 1;
    return 0;
}
int isFull(Queue Q){
    if(Q == NULL)
        return 0;
    if(Q->rear == Q->size -1 )
        return 1;
    return 0;
}
void enqueue(Queue *Q,int data){
    if(isFull(*Q))
        return;
    (*Q)->a[(*Q)->rear++] = data;
    
}

int dequeue(Queue *Q){
    if(isEmpty(*Q))
        return -1;
    return (*Q)->a[(*Q)->front++];
}
