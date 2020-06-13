#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
 
int max_indice , max_sum;
int max_area , min_area;
int rectangle[200][2];
 
bool cover(int a , int b){

#ifdef SMALLONLARGE
    return ((rectangle[a][0] <= rectangle[b][0] && rectangle[a][1] <= rectangle[b][1]) ||\
            (rectangle[a][0] <= rectangle[b][1] && rectangle[a][1] <= rectangle[b][0]));
#else
    return ((rectangle[b][0] <= rectangle[a][0] && rectangle[b][1] <= rectangle[a][1]) ||\
            (rectangle[b][0] <= rectangle[a][1] && rectangle[b][1] <= rectangle[a][0]));
#endif

}
 
void stack(int current_index , int next_index , int current_sum , int area){    
    if(next_index == -1){ 
        if(max_sum == current_sum){
            max_area = (max_area > area ? max_area : area);
            min_area = (min_area < area ? min_area : area);
        }else if(max_sum < current_sum){
            max_sum = current_sum;
            max_area = min_area = area;
        }
        return;
    }
 
    if(cover(current_index , next_index)){
 
        // place your rectangle
        stack(next_index , next_index - 1 , current_sum + 1 , area + rectangle[next_index][0] * rectangle[next_index][1]);
 
    }
 
    // don't place your rectangle
    stack(current_index , next_index - 1 , current_sum , area);
 
}
 
int main(){
    int n; scanf("%d" , &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d" , &rectangle[i][0] , &rectangle[i][1]);    
 
    max_sum = 0 , max_indice = 0 , max_area = 0 , min_area = INT_MAX;
    for(int i = 0; i < n; i++){
        stack(n - 1 - i , n - 2 - i , 1 , rectangle[n - 1 - i][0] * rectangle[n - 1 - i][1]);
    }

#ifdef MAXAREASUM
    printf("%d %d\n", max_sum , max_area);
#else
    printf("%d %d\n", max_sum , min_area);
#endif   

    
}