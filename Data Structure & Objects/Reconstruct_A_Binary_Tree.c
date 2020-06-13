#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(x, y) (x > y ? y : x)

typedef struct NODE{
	int value;
	struct NODE* left;
	struct NODE* right;
}Node;

int cmp(const void* a , const void* b){

	// dark magic : sort layer first and then value
	return ((*((int *)a + 1) > *((int *)b + 1)) ? 1 : (*((int *)a + 1) < *((int *)b + 1)) ? -1 : (*((int *)a) > *((int *)b)) ? 1 : -1);
}

void construct(Node* root , int value , int layer){

	// get the appropriate layer of current tree.
	for(int i = 1; i < layer - 1; i++){
		if(value > root->value)
			root = root->right;
		else
			root = root->left;
	}

	// generate new node
	Node* new_Node = malloc(sizeof(Node));
	new_Node->value = value;
	new_Node->left = new_Node->right = NULL;

	if(value > root->value)
		root->right = new_Node;
	else
		root->left = new_Node;
}

int search(Node* A , Node* B , int A_value , int B_value){
	int result = 0;

	// Find both node
	while(A->value != A_value || B->value != B_value){

		// Stop when founded
		int A_step = 0;
		if(A->value != A_value){
			A_step = 1;

			if(A->value > A_value)
				A = A->left;
			else
				A = A->right;
		}

		int B_step = 0;
		if(B->value != B_value){
			B_step = 1;

			if(B->value > B_value)
				B = B->left;
			else
				B = B->right;
		}

		// if they begin to go on different road, count them
		if(A != B)
			result += (A_step + B_step);
	}
	return result;
}

int main(){
	int n; scanf("%d" , &n);
	int data[n][2]; // (value , layer)

	for(int i = 0; i < n; i++)
		scanf("%d%d" , &data[i][0] , &data[i][1]);

	qsort(data , n , sizeof(int) * 2 , cmp);

	Node* root = malloc(sizeof(Node));
	root->value = data[0][0];
	root->left = root->right = NULL;

	for(int i = 1; i < n; i++)
		construct(root , data[i][0] , data[i][1]);

	int m; scanf("%d" , &m);
	for(int i = 0; i < m; i++){
		int A , B; scanf("%d%d" , &A , &B);

		// find the nodes at the same time
		printf("%d\n", search(root , root , A , B));
	}
}