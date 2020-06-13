#include <stdlib.h>
#include "tree.h"

Node *construct(Node *root, char instruction[MAXN]){
	if(root == NULL)
		root = malloc(sizeof(Node)) , root->data = 1 , root->left = root->right = NULL;
	else
		root->data++;

	switch(instruction[0]){
		case 'L':
			root->left = construct(root->left , instruction + 1);
			break;
		case 'R':
			root->right = construct(root->right , instruction + 1);
			break;
		default:
			break;
	}
	return root;
}

int query(Node *root, char instruction[MAXN]){
	if(root == NULL) return 0;
	switch(instruction[0]){
		case 'L':
			return query(root->left , instruction + 1);
			break;
		case 'R':
			return query(root->right , instruction + 1);
			break;
		default:
			return root->data;
			break;
	}
}