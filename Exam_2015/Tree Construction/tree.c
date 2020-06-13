#include "tree.h"
#include <stdlib.h>

Node* myConstruct(int array[] , int n , int index){
	if(index >= n) return NULL;

	Node* root = malloc(sizeof(Node));
	root->label = array[index];
	root->left = myConstruct(array , n , 2 * index + 1);
	root->right = myConstruct(array , n , 2 * index + 2);

	return root;
}

Node* construct(int array[] , int n){
	return myConstruct(array , n , 0);
}
