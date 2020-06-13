#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[1005];
enum type{operator , operand};
enum leaf{Left , Right};

typedef struct NODE{
	enum type T;
	int data;
	char symbol;
	struct NODE* left , right , parent;
}Node;

Node* generate(Node* root , enum leaf L){
	Node* new_Node = malloc(sizeof(Node));
	switch(L){
		case Left:
			root->left = new_Node;
			new_Node->parent = root;
			break;
		case Right:
			root->right = new_Node;
			new_Node->parent = root;
			break;
	}
	return new_Node;
}

int main(){
	fgets(buffer , 1001 , stdin);
	int len = strlen(buffer);

	Node* root = malloc(sizeof(Node));

	for(int i = 0; i < len; i++){
		if(isspace(buffer[i]))
			continue;

		switch(buffer[i]){
			case '(':
				generate(root , Left);
				break;
			case '+': case '-': case 'x': case '/': 


		}
	}
}