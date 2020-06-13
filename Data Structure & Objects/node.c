#include <stdlib.h>
#include "node.h"
 
struct node *getNode(struct node *head, unsigned int i){
    int counter = 0;
    struct node* temp = head;

    while(temp->next != NULL){
      temp = temp->next;
      counter++;
    }

    if(i > counter)
      return NULL;
    else{
      for(int j = 0; j < (counter - i); j++)
        head = head->next;
        return head;
    }
}