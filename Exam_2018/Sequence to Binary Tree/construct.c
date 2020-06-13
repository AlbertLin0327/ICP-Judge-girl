#include <stdlib.h>
#include <string.h>
#include "construct.h"

int cmp(const void* a , const void* b){
	return (*(int *)a > *(int *)b ? -1 : 1);
}

int search(int sequence[] , int start , int end){
	int compare[end - start + 1];
	memcpy(compare , sequence + start , (end - start + 1) * sizeof(int));
	qsort(compare , end - start + 1 , sizeof(int) , cmp);

	int index = start , value = compare[MAXLENGTH - 1];
	for(; index <= end; index++)
		if(value == sequence[index]) break;

	return index;
}

Node* gen_Node(int value , Node* left , Node* right){
	Node* new_Node = malloc(sizeof(Node));
	new_Node->value = value;
	new_Node->left = left;
	new_Node->right = right;

	return new_Node;
}

Node* link_list(int sequence[] , int start , int end){
	if(start > end)
		return NULL;

	Node* root = gen_Node(sequence[end] , link_list(sequence , start , end - 1) , NULL);
	return root;
}

Node* my_Construct(int sequence[] , int start , int end){
	if(start > end)
		return NULL;

	Node* root = NULL;
	if(end - start + 1 < MAXLENGTH)
		root = link_list(sequence , start , end);
	else{
		int index = search(sequence , start , end);
		root = gen_Node(sequence[index] , my_Construct(sequence , start , index - 1) , my_Construct(sequence , index + 1 , end));
	}
	
	return root;
}

Node* ConstructTree(int sequence[] , int N){
	return my_Construct(sequence , 0 , N - 1);
}