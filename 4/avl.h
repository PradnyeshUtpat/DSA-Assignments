typedef struct Avlnode{
    char month[10];
    struct Avlnode *left,*right,*parent;
    int balfact;
} Avlnode;

typedef Avlnode* AVL;


void InitAvl(AVL* root);
void InsertNode(AVL* root,char* month);
void RemoveNode(AVL* root,char * month);
void Traverse(AVL root);
void Destroy(AVL* root);