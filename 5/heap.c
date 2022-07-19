#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

void init_heap(Heap *heap, int size)
{
    heap->size = size;
    heap->rear = -1;
    heap->arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        heap->arr[i] = INT_MIN;
    }
}

void printHeap(Heap heap)
{
    int i = 0;
    while (i <= heap.rear)
    {
        printf("%d ", heap.arr[i]);
        i++;
    }
}

void insert_(Heap *heap, int val)
{
    if (heap->rear == heap->size)
    {
        printf("heap is full");
        return;
    }
    heap->arr[++heap->rear] = val;

    int parent = (heap->rear - 1) / 2;
    int i = heap->rear;
    while (heap->arr[parent] > heap->arr[i])
    {
        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[i];
        heap->arr[i] = temp;
        i = parent;
        parent = (parent - 1) / 2;
    }
}

int remove_(Heap *heap)
{
    if (heap->rear == -1)
        return 0;
    int k = heap->arr[0];
    heap->arr[0] = heap->arr[heap->rear--];
    int i = 0;
    int smaller = i;
    while (2 * i + 2 <= heap->rear)
    {
        if (heap->arr[2 * i + 1] < heap->arr[2 * i + 2])
        {
            smaller = (2 * i + 1);
        }
        else
            smaller = 2 * i + 2;

        int temp = heap->arr[smaller];
        heap->arr[smaller] = heap->arr[i];
        heap->arr[i] = temp;

        i = smaller;
    }
    if (2 * i + 1 <= heap->rear)
    {
        if (heap->arr[2 * i + 1] < heap->arr[i])
        {
            int temp = heap->arr[2 * i + 1];
            heap->arr[2 * i + 1] = heap->arr[i];
            heap->arr[i] = temp;
        }
    }
    return k;
}
