#include <stdio.h>
#include "node.h"

void dfs(struct node *root , int result[1005] , int index){

	if(root == NULL)
		return;

	// add value
	result[index] = root->data;
	index++;

	if(root->right == NULL && root->left == NULL){
		for(int i = 0; i < index; i++)
			printf("%d ", result[i]);
		printf("\n");
	}else{
		dfs(root->left , result , index);
		dfs(root->right , result , index);
	}
}

void print_all_paths(struct node *root){
	int result[1005];
	dfs(root , result , 0);
}