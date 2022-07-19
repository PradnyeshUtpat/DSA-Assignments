#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

typedef struct
{
    int *arr;
    int size;
    int rear;
} Heap;


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


int main()
{
    Heap heap;
    init_heap(&heap, 1000);

    int sortedArr[700];

    FILE *filePtr;
    filePtr = fopen("random.txt", "w");
    for (int i = 0; i < 1000; i++)
    {
        fprintf(filePtr, "%d\n", rand() % 500);
    }
    fclose(filePtr);

    FILE *filePtr1;
    filePtr1 = fopen("random.txt", "r");

    if (NULL == filePtr1)
    {
        printf("file can't be opened \n");
    }
    char ch = '$';
    int n = 0;
    while (ch != EOF)
    {

        ch = fgetc(filePtr1);
        if (ch == '\n')
        {
            insert_(&heap, n);
            n = 0;
        }
        else
        {
            n = n * 10 + (ch - 48);
        }
    }
    for (int i = 0; i < 500; i++)
    {
        int k = remove_(&heap);
        sortedArr[i] = k;
    }
    for (int i = 0; i < 500; i++)
    {
        printf("%d ", sortedArr[i]);
    }
}