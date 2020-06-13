#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char buffer[4010];
enum sub_Node{LEFT , RIGHT};
enum mode{HLHR , HRHL};

typedef struct NODE{
	int value;
	struct NODE* left;
	struct NODE* right;
	struct NODE* top;
}Node;


Node* new_Node(Node* parent , enum sub_Node type){

	// allocate memory & initialize current node
	Node* treeNode = malloc(sizeof(Node));
	treeNode->value = 0;
	treeNode->left = treeNode->right = NULL;
	treeNode->top = parent;

	// connect parent node and child
	switch(type){
		case LEFT:
			parent->left = treeNode;
			break;

		case RIGHT:
			parent->right = treeNode;
			break;
	}

	return treeNode;
}

void add_Value(Node* child , int n){
	while(child != NULL){
		child->value += n;
		child = child->top;
	}
	return;
}

void traversal(Node * current , enum mode type){
	if(current == NULL)
		return;

	// next type
	switch(type){
		case HRHL:
			printf("%d\n", current->value);
			traversal(current->right , HLHR);
			printf("%d\n", current->value);
			traversal(current->left , HLHR);
			break;

		case HLHR:
			printf("%d\n", current->value);
			traversal(current->left , HRHL);
			printf("%d\n", current->value);
			traversal(current->right , HRHL);
			break;
	}

	return;
}

int main(){
	Node* root = malloc(sizeof(Node));
	root->value = 0;
	root->left = root->right = root->top = NULL;
	Node* current = root;

	fread(buffer , sizeof(char) , 4005 , stdin);
	int length = strlen(buffer);

	for(int i = 0; i < length; i++){

		if(buffer[i] == '(' && buffer[i + 1] != ',')
			current = new_Node(current , LEFT);

		else if(buffer[i] == ',' && buffer[i + 1] != ')')
			current = new_Node(current , RIGHT);

		else if(buffer[i] == ')')
			current = current->top;

		else if(isdigit(buffer[i])){
			int n;
			sscanf(buffer + i , "%d" , &n);
			
			// remove redundant digits
			while(isdigit(buffer[i + 1]))
				i++;	
			add_Value(current , n);
			current = current->top;
		}
	}

	//HLHR for the first branch. And Next type will be HRHL
	printf("%d\n", root->value);
	traversal(root->left , HRHL);
	printf("%d\n", root->value);
	traversal(root->right , HRHL);

}
