
typedef struct queue{
    int rear,front,size;  
    int *a;
}queue;

typedef queue *  Queue;

void init_Q(Queue *Q,int size);
int isEmpty(Queue Q);
int isFull(Queue Q);
void enqueue(Queue *Q,int data);
int dequeue(Queue *Q);