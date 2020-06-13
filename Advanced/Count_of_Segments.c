#include <stdio.h>
#include <stdbool.h>
 
int main(){
 
    int time; scanf("%d" , &time);
    bool num; scanf("%d" , &num);
 
    bool prev = num;
    int count = 1;
    while(scanf("%d" , &num) != EOF){
        if(prev ^ num){
            prev = num;
            count++;
        }
    }
 
    printf("%d\n", count);
 
    return 0;
 
}