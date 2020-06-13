#include <stdlib.h>
#include <stdbool.h>
#include "merge.h"

Node* merge(Node* list[], int K){
	Node *head , *temp; head = temp = malloc(sizeof(Node));
	bool legal = 1 , down = 1;

	while(legal){
		legal = 0;
		for(int i = 0; i < K; i++){
			int index = (down ? i : K - 1 - i);
			if(list[index] != NULL){
				legal = 1;
				temp = temp->next = list[index];
				list[index] = list[index]->next;
			}
		}
		down = !down;
	}
	
	return head->next;
}