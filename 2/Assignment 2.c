#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define MAXSIZE 100
typedef struct node{
    int size;
    int *array;
}artree;
artree* init(){
    artree* ar1 = malloc(sizeof(artree));
    if(!ar1)
    return NULL;
    ar1->size = MAXSIZE;
    ar1->array = malloc(ar1->size * sizeof(int));
    
    for(int i=0; i<MAXSIZE; i++){
        ar1->array[i] = INT_MIN;
    }
    return ar1;
}

void insert(artree *a1 , int x){
    int index = 0;
    if(a1-> array[index] == INT_MIN){
        a1-> array[index] = x;
    }
    
    if(a1->array[index] > x){
        index = 2*index + 1;
        while(index<=MAXSIZE && a1->array[index]!=INT_MIN){
            if(a1->array[index] > x){
                index = 2*index + 1;
            }
            else{
                index = 2*index + 2;
            }
        }
        if(a1->array[index]==INT_MIN){
             a1-> array[index] = x;
        }
    }
    
    else if(a1->array[index] < x){
        index = 2*index + 2;
        while(index<=MAXSIZE && a1->array[index]!=INT_MIN){
            if(a1->array[index] > x){
                index = 2*index + 1;
            }
            else{
                index = 2*index + 2;
            }
        }
        if(a1->array[index]==INT_MIN){
             a1-> array[index] = x;
        }
    }
}

void leveltraverse(artree *a1){
    int i=0;
    for(i = 0; i<MAXSIZE; i++){
        if(a1-> array[i] != INT_MIN){
            printf("%d ", a1-> array[i]);
        }
    }
}

void intraverse(artree *a1 , int index){
    //artree *a1;
    if (a1-> array[index] == INT_MIN)
		return ;
	else {
		intraverse(a1 , 2* index + 1 );
		if(a1-> array[index]!=INT_MIN)
            printf("%d ", a1-> array[index]);
		intraverse(a1 , 2* index + 2);
	}
}

void traverse(artree *a1 , int index){
    if (a1-> array[index] == INT_MIN)
		return;
	else {
	    if(a1-> array[index]!=INT_MIN)
            printf("%d ", a1-> array[index]);
		traverse(a1 , 2* index + 1 );
		traverse(a1 , 2* index + 2);
	}
}

void posttraverse(artree *a1 , int index){
    if (a1-> array[index] == INT_MIN)
		return;
	else {
		posttraverse(a1 , 2* index + 1 );
		posttraverse(a1 , 2* index + 2);
		if(a1-> array[index]!=INT_MIN)
            printf("%d ", a1-> array[index]);
	}
}

int isComplete(artree *a1){
    for(int i=0; i<MAXSIZE; i++){
        if(a1-> array[i]==INT_MIN){
            for(int j=i+1; j<MAXSIZE; j++){
                if(a1-> array[j]!=INT_MIN){
                    return 0;
                    break;
                    }
                }
            }
        }
    return 1;
}
int main(){
    artree *a;
    a=init();
    insert(a , 50);
    insert(a , 30);
    insert(a , 70);
    insert(a , 20);
    insert(a , 60);
    insert(a , 10);
    insert(a , 25);
    insert(a , 80);
    
    printf("Levelorder Traversal : ");
    leveltraverse(a);
    printf("\nInorder Traversal : ");
    intraverse(a , 0);
    printf("\nPreorder Traversal : ");
    traverse(a, 0);
    printf("\nPostorder Traversal : ");
    posttraverse(a, 0);
    printf("\n%d" ,isComplete(a));
    return 0;
}