#include <stdlib.h>
#include <stdio.h>
#include "operations.h"

Node *FlipTree(Node *root){
	if(root == NULL)
		return NULL;
	Node *new_Node = malloc(sizeof(Node));
	new_Node->n = root->n;
	new_Node->left = FlipTree(root->right);
	new_Node->right = FlipTree(root->left);
	return new_Node;
}
int isIdentical(Node *tree1, Node *tree2){
	if(tree1 == NULL && tree2 == NULL)
		return 1;
	if((tree1 == NULL && tree2 != NULL) || (tree2 == NULL && tree1 != NULL) || tree1->n != tree2->n)
		return 0;
	
	return 1 && isIdentical(tree1->left , tree2->left) && isIdentical(tree1->right , tree2->right);
}

int depth_counting(Node* root , int layer , int* num_of_leaves){
	if(root == NULL)
		return 0;

	if(root->left == NULL && root->right == NULL){
		*num_of_leaves += 1; 
		return layer;
	}

	return depth_counting(root->right , layer + 1 , num_of_leaves) + depth_counting(root->left , layer + 1 , num_of_leaves);
}

void depthAvg(Node *root){
	int num_of_leaves = 0 , depth = depth_counting(root , 0 , &num_of_leaves);
	printf("%d/%d\n" , depth , num_of_leaves);

}