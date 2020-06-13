#include "subtree.h"
#include <stdlib.h>
#include <stdbool.h>

int arr_index = 0;

bool dfs(Node *root, int label[], int k){
	if(root == NULL) return 0;

	bool left = dfs(root->left , label , k) , right = dfs(root->right , label , k);

	if(root->label == k) return (1 + left + right);
	if(left && right)
		label[arr_index] = root->label , arr_index++;

	return (left + right);
}

int getNode(Node *root, int label[], int k){
	arr_index = 0 , dfs(root , label , k);
	return arr_index;
}