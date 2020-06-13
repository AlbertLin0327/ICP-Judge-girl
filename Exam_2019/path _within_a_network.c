#include <stdio.h>
 
int main(){
 
    int a , b , c , d ,e ,f ,g ;
    scanf("%d%d%d%d%d%d%d" , &a , &b ,&c ,&d ,&e ,&f ,&g);
 
    int edge = a + b + c + d + a * e + b * e + c * e + c * f + d * f + e * g  + g + f;
    int path = a * e * g + b * e * g + c * e * g + c * f + d * f;
 
    printf("%d\n%d" , edge , path);
 
    return 0;
 
}