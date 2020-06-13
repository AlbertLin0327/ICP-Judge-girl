#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
 
int n; 
int road[8][8];
 
int result[10] , current[10];
int max;
 
bool dfs(int index , int count){
 
    if(index == 0){
        if(max <= count){
            max = count;
            for(int i = 0; i < max; i++)
                result[i] = current[i];
        }
    }
 
    for(int i = n - 1; i >= 0; i--){
 
        bool legal = 1;
 
        for(int j = 0; j < count; j++)
            if(current[j] == i){
                legal = 0;
                break;
            }
 
 
        if(road[index][i] && legal){
            current[count] = i;
            dfs(i , count + 1);
        }
    }
    return 0;
 
}
 
int main(){
    max = 0;
    scanf("%d" , &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d" , &(road[i][j]));
        }
    }
 
    for(int i = n - 1; i >= 0; i--){
        if(road[0][i]){
            current[0] = i;
            dfs(i , 1);
        }
    }
 
    for(int i = 0; i < max - 1; i++)
        printf("%d ", result[i]);
    printf("\n");
}