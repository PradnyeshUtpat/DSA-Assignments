#include "Avl.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int max(int a,int b){
    return a>b?a:b;
}


void InitAvl(AVL* root){
    (*root)=NULL;
}

int heightoftree(AVL root){
    if(!root) return 0;
    return 1+max(heightoftree(root->left),heightoftree(root->right));
}


void updatebalancefact(AVL root){
    if(!root) return;
    root->balfact=heightoftree(root->left)-heightoftree(root->right);
    updatebalancefact(root->parent);
}

AVL findfirstunbalanced(AVL root){
    if(!root) return NULL;
    AVL p=root;
   
    while(p){
        if(abs(p->balfact)>1) break;
        p=p->parent;
    }
    return p;
}

void LLRotation(AVL* root,AVL* n){
    
    AVL A=(*n);
    
    AVL B=((*n)->left);
    AVL BR=B->right;
    B->right=A;
    A->left=BR;
    B->parent=A->parent;
    if(BR)
       BR->parent=A;
    A->parent=B;
    B->balfact=0;
    A->balfact=0;
    if((*root)==A){
       (*root)=B;
       return;
    } 
    if(B->parent->left==A)
       B->parent->left=B;
    else  B->parent->right=B;
    return;
}

void RRRotation(AVL* root,AVL* n){
    AVL A=(*n);
    AVL B=((*n)->right);
    AVL BL=B->left;
    B->left=A;
    A->right=BL;
    B->parent=A->parent;
    if(BL)
      BL->parent=A;
    A->parent=B;
    B->balfact=0;
    A->balfact=0;
    if((*root)==A){
       (*root)=B;
       return;
    } 
    if(B->parent->left==A)
       B->parent->left=B;
    else  B->parent->right=B;
    return;
}


void LRRotation(AVL* root,AVL* n){
    RRRotation(root,&(*n)->left);
    LLRotation(root,n);
}

void RLRotation(AVL* root,AVL* n){
    LLRotation(root,&(*n)->right);
    RRRotation(root,n);
}



void InsertNode(AVL* root,char * month){
    AVL newnode=(AVL) malloc(sizeof(Avlnode));
    if(!newnode) return;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
    newnode->balfact=0;
    strcpy(newnode->month,month);
    if(!(*root)){
        (*root)=newnode;
        return;
    }
    AVL p,q;
    q=NULL;
    p=(*root);
    while(p){
        q=p;
        if(strcmp(p->month,month)>0)
          p=p->left;
        else if(strcmp(p->month,month)<0)
          p=p->right;
        else return;
    }
    
    newnode->parent=q;
    if(strcmp(q->month,month)>0)
        q->left=newnode;
    else q->right=newnode;
    
  
    updatebalancefact(q);
    AVL unbal=NULL;
    unbal=findfirstunbalanced(q);
    do{ 
       
        if(!unbal) return;
        AVL parentofunbal=unbal->parent;

        if(unbal->balfact==2 && unbal->left->balfact==1)
            LLRotation(root,&unbal);
        else if(unbal->balfact==2 && unbal->left->balfact==-1)
            LRRotation(root,&unbal);
        else if(unbal->balfact==-2 && unbal->right->balfact==1)
            RLRotation(root,&unbal);
        else if(unbal->balfact==-2 && unbal->right->balfact==-1){
            RRRotation(root,&unbal);
        }
        
        updatebalancefact(parentofunbal);
        unbal=findfirstunbalanced(parentofunbal);
    }while(unbal);
    
    return;
}

void RemoveNode(AVL* root,char *month){
     if(!(*root)) return;
     AVL p,q;
     p=(*root),q=NULL;
     while(p){
         if(strcmp(p->month,month)>0)
           p=p->left;
         else if(strcmp(p->month,month)<0)
           p=p->right;
         else break;
     }
     if(!p) return;
     q=p->parent;

     if(!p->left && !p->right){
         if(p==q->left) q->left=NULL;
         else q->right=NULL;
         free(p);
          updatebalancefact(q);
        AVL unbal=NULL;
        unbal=findfirstunbalanced(q);
        do{ 
        
            if(!unbal) return;
            AVL parentofunbal=unbal->parent;

            if(unbal->balfact==2 && unbal->left->balfact==1)
                LLRotation(root,&unbal);
            else if(unbal->balfact==2 && unbal->left->balfact==-1)
                LRRotation(root,&unbal);
            else if(unbal->balfact==-2 && unbal->right->balfact==1)
                RLRotation(root,&unbal);
            else if(unbal->balfact==-2 && unbal->right->balfact==-1){
                RRRotation(root,&unbal);
            }
            
            updatebalancefact(parentofunbal);
            unbal=findfirstunbalanced(parentofunbal);
        }while(unbal);
     }
     else if(!p->left || !p->right){
         AVL temp=p->left?p->left:p->right;
         if(p==q->left) q->left=temp;
         else q->right=temp;
         temp->parent=q;
         free(p);

          updatebalancefact(q);
        AVL unbal=NULL;
        unbal=findfirstunbalanced(q);
        do{ 
        
            if(!unbal) return;
            AVL parentofunbal=unbal->parent;

            if(unbal->balfact==2 && unbal->left->balfact==1)
                LLRotation(root,&unbal);
            else if(unbal->balfact==2 && unbal->left->balfact==-1)
                LRRotation(root,&unbal);
            else if(unbal->balfact==-2 && unbal->right->balfact==1)
                RLRotation(root,&unbal);
            else if(unbal->balfact==-2 && unbal->right->balfact==-1){
                RRRotation(root,&unbal);
            }
            
            updatebalancefact(parentofunbal);
            unbal=findfirstunbalanced(parentofunbal);
        }while(unbal);
     }
     else{
         AVL* temp1=&(p->left);
         while((*temp1)->right)
            temp1=&(*temp1)->right;
        strcpy(p->month,(*temp1)->month);
        RemoveNode(temp1,p->month);
     }


}

void Traverse(AVL root){
    if(!root) return;
    Traverse(root->left);
    char temp[10]="NULL";
    if(root->parent)
      strcpy(temp,root->parent->month);
    printf("Month = %s, Parent = %s,BalanceFactor = %d\n",root->month,temp,root->balfact);
    Traverse(root->right);
}

void Destroy(AVL* root){
    if(!(*root)) return;
    Destroy(&((*root)->left));
    Destroy(&((*root)->right));
    AVL temp=(*root);
    free(temp);
    (*root)=NULL;
}