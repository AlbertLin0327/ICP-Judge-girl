#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "construct.h"

Node* gen_Node(char name[16] , int height , int weight){
	Node* new_Node = malloc(sizeof(Node));
	new_Node->height = height , new_Node->weight = weight;
	strcpy(new_Node->name , name);
	new_Node->left = new_Node->right = NULL;

	return new_Node;
}

void insert_Node(Node* root , char name[16] , int height , int weight){
#if defined HEIGHT
#define FLAG height
#else
#define FLAG weight
#endif

	while(1){
		if(FLAG > root->FLAG){
			if(root->right == NULL){
				root->right = gen_Node(name , height , weight);
				return;
			}else
				root = root->right;
		}else{
			if(root->left == NULL){
				root->left = gen_Node(name , height , weight);
				return;
			}else
				root = root->left;
		}
	}
	return;
}

Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
	Node* root = malloc(sizeof(Node));
	root->height = height[0] , root->weight = weight[0];
	strcpy(root->name , name[0]);

	for(int i = 1; i < N; i++){
		insert_Node(root , name[i] , height[i] , weight[i]);
	}
	return root;
}