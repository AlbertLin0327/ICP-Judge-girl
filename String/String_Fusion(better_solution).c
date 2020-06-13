#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define min(x , y) (x < y ? x : y)
 
char* sub(char arr[] , int a , int b){
    char *substr = malloc((b - a + 2) * sizeof(char));
    for(int i = a; i <= b; i++){
        substr[i - a] = arr[i];
    }
    substr[b - a + 1] = '\0';
 
    return substr;
}
 
int main(){
    char result[127] , data[127]; result[0] = '\0';
 
    while(scanf("%s" , data) != EOF){
        int length = strlen(result);
        int repeat = 0;
 
        if(length == 0){
            strcpy(result , data);
        }else{
 
            for(int i = 0; i < strlen(result) && i < strlen(data); i++){
                char *temp = sub(result , length - i - 1 , length - 1);
                char *target = sub(data , 0 , i); 
                for(int j = 0; j <= i; j++){
                    target[j] = data[j];
                }
                target[i + 1] = '\0';
 
                if(strcmp(temp , target) == 0){
                    repeat = i + 1;
                }
                free(temp); free(target);
            }
            for(int i = 0; i + repeat < strlen(data); i++){
                result[length + i] = data[repeat + i];
            }
            result[length + strlen(data) - repeat] = '\0';
        }
 
    }
 
    printf("%s\n", result); 
 
    return 0;
 
}