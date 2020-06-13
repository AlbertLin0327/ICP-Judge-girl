typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2);
Node *treeOR(Node *root1, Node *root2);