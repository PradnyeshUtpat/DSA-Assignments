typedef struct stack
{
    int top;
    int size;
    int *arr;
} stack;

typedef stack * Stack;

void init_stack(Stack *s,int size);

int isEmpty_s(Stack s);

int isFull_s(Stack s);

void push(Stack *s, int data);

int  pop(Stack *s);