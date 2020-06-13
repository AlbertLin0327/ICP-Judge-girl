#include <stdlib.h>
#include <assert.h>
#include "BuildTree.h"
 
int length_of_list(Node* root){
    int len = 0;
    while(root != NULL)
        len++; root = root->left;
 
    return len;
}
 
Node* BuildTree(Node* list1, Node* list2){
    Node *root , *left_1 = NULL , *left_2 = NULL , *right_1 = NULL , *right_2 = NULL , *temp;
 
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
 
    root = (list1->val < list2->val ? list1 : list2); 
 assert(root != NULL);
    printf("%d\n", root->val);
   

    left_1 = left_2 = (list1->val < list2->val ? list1->left : list1);
    int len = length_of_list(left_2);

    for(int i = 0; i < (len + 1) / 2 - 1; i++)
        left_2 = left_2->left;
    temp = left_2; left_2 = left_2->left; temp->left = NULL;

    right_1 = right_2 = (list1->val < list2->val ? list2 : list2->left);
    len = length_of_list(right_2);

    for(int i = 0; i < (len + 1) / 2 - 1; i++)
        right_2 = right_2->left;
    temp = left_2; right_2 = right_2->left; temp->left = NULL;

    //root->left = BuildTree(left_1 , right_1);
    //root->right = BuildTree(left_2 , right_2);

    return root;
}