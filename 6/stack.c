#include<stdio.h>
#include<stdlib.h>
#include "stack.h"



void init_stack(Stack *s,int size)
{
    *s = (Stack)malloc(sizeof(Stack));
    (*s)->top = -1;
    (*s)->size = size;
    (*s)->arr = (int*)malloc(sizeof(int) * ((*s)->size));
}
int isEmpty_s(Stack s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isFull_s(Stack s)
{
    if (s->top == s->size)
        return 1;
    else
        return 0;
}
void push(Stack *s, int data)
{
    
    if (isFull_s(*s) == 1)
        return;
    else
    {
        (*s)->top++;
        (*s)->arr[(*s)->top] = data;
        return;
    }
}
int pop(Stack *s)
{
    if (isEmpty_s(*s) == 1)
        return -1;
    else
    {
      return (*s)->arr[(*s)->top--];
    }
}