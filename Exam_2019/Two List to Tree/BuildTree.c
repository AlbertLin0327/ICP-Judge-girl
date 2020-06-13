#include <stdlib.h>
#include <stdbool.h>
#include "BuildTree.h"
 
int length_of_list(Node* root){
    return (root == NULL ? 0 : 1 + length_of_list(root->left));
}
 
Node* BuildTree(Node* list1, Node* list2){
    Node *root , *right_1 = NULL , *right_2 = NULL , *temp;
 
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    bool first  = (list1->val < list2->val);
    root = (first ? list1 : list2); 
    right_1 = list1 = (first ? list1->left : list1);
    right_2 = list2 = (first ? list2 : list2->left);

    int len = length_of_list(right_1);
    for(int i = 0; i < ((len + 1) / 2 - 1); i++)
        right_1 = right_1->left;

    len = length_of_list(right_2);
    for(int i = 0; i < ((len + 1) / 2 - 1); i++)
        right_2 = right_2->left;

    if(right_1 != NULL)
        temp = right_1 , right_1 = right_1->left , temp->left = NULL;
    if(right_2 != NULL)
        temp = right_2 , right_2 = right_2->left , temp->left = NULL;

    root->left = BuildTree(list1 , list2);
    root->right = BuildTree(right_1 , right_2);
    return root;
}