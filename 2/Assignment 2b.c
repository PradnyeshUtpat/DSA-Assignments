#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node* newNode(int data){
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* insert(struct node* root, int key){
    struct node* newnode = newNode(key);
    struct node* x = root;
    struct node* y = NULL;
	while (x != NULL) {
		y = x;
		if (key < x->data)
			x = x->left;
		else
			x = x->right;
	}

	if (y == NULL)
		y = newnode;
	else if (key < y->data)
		y->left = newnode;
	else
		y->right = newnode;
	return y;
}

void Inorder(struct node* root){
	if (root == NULL)
		return;
	else {
		Inorder(root->left);
		printf("%d ",root->data);
		Inorder(root->right);
	}
}

struct node* arraytotree(int arr[] , int size){
    struct node* root = NULL;
    root = insert(root , arr[size-1]);
    int a = arr[size-1];
    int i = size-1;
    while(i!=0){
        while(arr[i]>a){
            insert(root , arr[i]);
            i--;
        }
        i--;
        insert(root , arr[i]);
        a = arr[i];
    }
    return root;
}
int main(){
    
    printf("Enter size of postorder array : ");
    int size;
    scanf("%d", &size);
    printf("\n");
    
    int arr[size];
    for(int i=0 ; i<size; i++){
        printf("Enter array elements : ");
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray elements are : ");
    for(int i=0 ; i<size; i++){
        printf("%d ", arr[i]);
    }
    
    struct node * root;
    root = arraytotree(arr , size);
    printf("\n");
    printf("Inorder traversal is : ");
    Inorder(root);
    
    return 0;
}