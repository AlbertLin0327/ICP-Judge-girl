#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
 
int max_indice , max_sum;
int rectangle[200][2];
 
bool cover(int a , int b){
    return ((rectangle[a][0] <= rectangle[b][0] && rectangle[a][1] <= rectangle[b][1]) ||\
            (rectangle[a][0] <= rectangle[b][1] && rectangle[a][1] <= rectangle[b][0]));
}
 
void stack(int current_index , int next_index , int current_sum , int current_indice){    
 
    if(next_index == -1){ 
        if(max_sum < current_sum){
            max_sum = current_sum;
            max_indice = current_indice;
        }else if(max_sum == current_sum){
            max_indice = (max_indice > current_indice ? max_indice : current_indice);
        }
        return;
    }
 
    if(cover(current_index , next_index)){
 
        // place your rectangle
        stack(next_index , next_index - 1 , current_sum + 1 , current_indice + next_index);
 
    }
 
    // don't place your rectangle
    stack(current_index , next_index - 1 , current_sum , current_indice);
 
}
 
int main(){
    int n; scanf("%d" , &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d" , &rectangle[i][0] , &rectangle[i][1]);    
 
    max_sum = 0; max_indice = 0;
    for(int i = 0; i < n - 1 && n - 1 - i >= max_sum; i++){
        stack(n - 1 - i , n - 2 - i , 1 , n - 1 - i);
    }
 
    printf("%d %d\n", max_sum , max_indice);
}