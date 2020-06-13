#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max(x , y) (x > y ? x : y)
 
int n , m; // m rows n column
int row[32] , column[32] , current_row[32] , current_column[32];
 
int matrix[32][32];
 
bool check(){
    for(int i = 0; i < m; i++){
        if(current_row[i] != row[i])
            return 0;       
    }
 
 
    for(int i = 0; i < n; i++){
        if(current_column[i] != column[i])
            return 0;
    }
 
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i][j] , j == n - 1 ? '\n' : ' ');
 
    return 1;
}
bool build(int number){
 
    if(number == 0 && check())
        return 1;
 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != 0)
                continue;
            if(number <= row[i] - current_row[i] && number <= column[j] - current_column[j]){
                current_row[i] += number; current_column[j] += number; matrix[i][j] = number;
                if(build(number - 1))
                    return 1;
                current_row[i] -= number; current_column[j] -= number; matrix[i][j] = 0;
            }
        }
    }
    return 0;
}
 
int main(){
 
    while(scanf("%d %d" , &m , &n) == 2){
        memset(matrix , 0 , sizeof(matrix));
        memset(current_row , 0 , 32 * sizeof(int));
        memset(current_column , 0 , 32 * sizeof(int));
 
        for(int i = 0; i < m; i++)
            scanf("%d" , &(row[i]));
 
        for(int i = 0; i < n; i++)
            scanf("%d" , &(column[i]));
 
        if(!build(m * n))
            printf("no solution\n");
    }
}