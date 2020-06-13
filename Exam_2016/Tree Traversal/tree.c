#include <stdio.h>
#include "tree.h"

void traversal(Node *root, int N, int command[]){
	Node* ptr_arr[1000];
	ptr_arr[0] = root;
	int count = 0;
	for(int i = 0; i < N; i++){
		switch(command[i]){
			case 0:
				printf("%d\n", ptr_arr[count]->label);
				return;

			case 1:
				printf("%d\n", ptr_arr[count]->label);
				break;

			case 2:
				if(count <= 0){
					printf("%d\n", ptr_arr[count]->label);
					return;
				}
				count--;
				break;

			case 3:
				if(ptr_arr[count]->left == NULL){
					printf("%d\n", ptr_arr[count]->label);
					return;
				}
				count++; ptr_arr[count] = ptr_arr[count - 1]->left;
				break;

			case 4:
				if(ptr_arr[count]->right == NULL){
					printf("%d\n", ptr_arr[count]->label);
					return;
				}
				count++ , ptr_arr[count] = ptr_arr[count - 1]->right;
				break;

			case 5:
				if(count <= 0 || ptr_arr[count - 1]->left == NULL || ptr_arr[count - 1]->right == NULL){
					printf("%d\n", ptr_arr[count]->label);
					return;
				}else{
					if(ptr_arr[count - 1]->left == ptr_arr[count])
						ptr_arr[count] = ptr_arr[count - 1]->right;
					else
						ptr_arr[count] = ptr_arr[count - 1]->left;
				}
				break;

			default:
				printf("%d\n", ptr_arr[count]->label);
				return;
		}
	}
}