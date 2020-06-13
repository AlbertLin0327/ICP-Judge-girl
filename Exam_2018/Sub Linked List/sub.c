#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sub.h"
 
void substring(Node* text, Node* pattern){
    Node *temp = pattern;
    int sum = 0,index=0;
    while(temp != NULL && text != NULL){  
        if(text->c != temp->c)
            temp = pattern , sum = 0;        
        else       
            temp = temp->next , sum += index;
            
        text = text->next;
        index++;
    }
    printf("%d\n", sum);
}
 
void subsequence(Node* text, Node* pattern){
    int index = 0 , sum = 0;
    while(pattern != NULL){
        if(pattern->c == text->c){
            sum += index; pattern = pattern->next;
        }
        text = text->next , index++;
    }
    printf("%d\n", sum);
}