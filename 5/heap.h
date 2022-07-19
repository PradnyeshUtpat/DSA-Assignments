typedef struct
{
    int *arr;
    int size;
    int rear;
} Heap;

void init_heap(Heap *heap, int size);
void insert_(Heap *heap, int val);

void printHeap(Heap heap);
int remove_(Heap *heap);