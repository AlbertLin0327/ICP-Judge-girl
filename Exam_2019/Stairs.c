#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
int main(){
    char word[35];
    bool right = 1;
    int length = 0;
 
    char last = '\0';
 
    while(scanf("%s" , word) != EOF){
        if(right){
            if(last == word[0]){
                for(int i = 0; i < length; i++)
                    printf("*");
                printf("%s\n", word);
            }else{
                if(last != '\0'){
                    for(int i = 0; i < length; i++)
                        printf("*");
                    printf("%c\n", last);
                }
 
                for(int i = 0; i < length; i++)
                    printf("*");
                printf("%s\n", word);
            }
 
            last = word[strlen(word) - 1];
            length += strlen(word) - 1;
            right = 0;
 
        }else{
            if(last == word[0]){
                memmove(word , word + 1 , strlen(word));
                word[strlen(word)] = '\0';
            }
 
            for(int i = 0 ; i < strlen(word) - 1; i++){
                for(int j = 0; j < length; j++){
                    printf("*");
                }
                printf("%c\n", word[i]);
            }
 
            last = word[strlen(word) - 1];
            right = 1;
        }
    }
 
    if(right){
        for(int i = 0; i < length; i++)
            printf("*");
        printf("%c\n", last);
    }
 
}