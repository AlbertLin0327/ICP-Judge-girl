#include <stdio.h>
#define max(x , y) (x > y? x : y)
#define min(x , y) (x < y? x : y)
 
int main(){
 
    int a , b , c , d , e;
    scanf("%d%d%d%d%d" , &a , &b , &c , &d , &e);
 
    int ans[3];
    int input[3];
 
    int num;
    int i = 0;
 
    while(scanf("%d" , &num) == 1){
 
        int count = 0;
 
        if(i == 3){
            i = 0;
        }
 
        input[i] = num;
 
        if(num <= e && num >= d){
            num = 0;
        }else{
            while(num > e || num < d){
                num = (a * num + b) % c;
                count++;
            }
        }
 
        ans[i] = count;
 
        if(i < 3){
            i++;
        }
 
        if( max(ans[0] , max(ans[1] , ans[2])) - min(ans[0] , min(ans[1] , ans[2])) == 2 &&\
            ans[0] != ans[1] && ans[1] != ans[2] && ans[0] != ans[2] ){

                printf("%d %d %d\n" , input[(i) % 3] , input[(i + 1) % 3] , input[(i + 2) % 3]);
                return 0;
                
        }
 
    }
 
    printf("Not found\n");
 
    return 0;
 
}