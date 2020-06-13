#include <stdio.h>
 
int main(){
 
    int N;
    scanf("%d" , &N);
 
    int card[N];
    for(int i = 0 ; i < N; i++){
        scanf("%d" , &(card[i]));
    }
 
    int appear[101];
    for(int i = 0 ; i <= 100 ; i++){
        appear[i] = -1;
    }
 
    for(int i = 0 ; i < N; i++){
        int value = card[i];
        if(appear[value] == -1){
            appear[value] = i;
            printf("%d\n" , i);
        }else{
            int index = appear[value];
            printf("%d %d %d\n" , i , index , value);
            appear[value] = -1;
        }
    }
 
 
 
 
    return 0;
}