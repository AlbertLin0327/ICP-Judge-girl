#include <stdlib.h>
#include "construct.h"
 
Node* List(int T[] , int start , int end){
    if (end < start)
        return NULL;
    Node* root = malloc(sizeof(Node));
    root->value = T[end];
    root->left = List(T , start , end - 1);
    root->right = NULL;
    return root;
}

int balance_index(int T[] , int start , int end){
    for(int i = start; i <= end; i++){
        long long int left_sum = 0 , right_sum = 0;
 
        for(int j = start; j < i; j++)
            left_sum += (long long int)T[j] * (i - j);
        for(int j = i + 1; j <= end; j++)
            right_sum += (long long int)T[j] * (j - i);
 
        if(left_sum == right_sum){
            return i;
        }
    }
    return -1;
}
 
Node* Construct(int T[] , int start , int end){
    if(end - start < 2)
        return List(T , start , end);
 
    int index = balance_index(T , start , end);
 	if(index == -1)
 		return List(T , start , end);

    Node* root = malloc(sizeof(Node));
    root->value = T[index];
    root->left = Construct(T , start , index - 1);
    root->right = Construct(T , index + 1, end);
    return root;
}
 
Node* ConstructTree(int T[] , int N){ 
	return Construct(T , 0 , N - 1); 
}