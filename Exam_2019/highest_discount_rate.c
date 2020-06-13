#include <stdio.h>
 
int main(){
 
    int a , b , v , w , x , y , z;
    scanf("%d%d%d%d%d%d%d" , &a , &b , &v , &w , &x , &y , &z);
 
    int p , d , P , D;
    if(a % 2 == 1){
 
        if(v * (a + 1) >= w * a){
            p = a;
            d = v;
        }else{
            p = a + 1;
            d = w;
        }
 
        if(b % 3 == 0){
            if(x * (b + 1) >= y * b){
                P = b;
                D = x;
            }else {
                P = b + 1;
                D = y;
            }
 
            if(D * (b + 2) < z * P){
                P = b + 2;
                D = z;
            }
        } else if(b % 3 == 1){
            if(y * (b + 1) >= z * b){
                P = b;
                D = y;
            }else {
                P = b + 1;
                D = z;
            }
 
            if(D * (b + 2) < x * P){
                P = b + 2;
                D = x;
            }
        }else if(b % 3 == 2){
            if(z * (b + 1) >= x * b){
                P = b;
                D = z;
            }else {
                P = b + 1;
                D = x;
            }
 
            if(D * (b + 2) < y * P){
                P = b + 2;
                D = y;
            }
        }
 
        if(d * P >= p * D){
            p = p;
            d = d;
        }else {
            p = P;
            d = D;
        }
 
    }else if(a % 2 == 0){
 
        if(w * (a + 1) >= v * a){
            p = a;
            d = w;
        }else{
            p = a + 1;
            d = v;
        }
 
        if(b % 3 == 0){
            if(x * (b + 1) >= y * b){
                P = b;
                D = x;
            }else {
                P = b + 1;
                D = y;
            }
 
            if(D * (b + 2) < z * P){
                P = b + 2;
                D = z;
            }
        } else if(b % 3 == 1){
            if(y * (b + 1) >= z * b){
                P = b;
                D = y;
            }else {
                P = b + 1;
                D = z;
            }
 
            if(D * (b + 2) < x * P){
                P = b + 2;
                D = x;
            }
        }else if(b % 3 == 2){
            if(z * (b + 1) >= x * b){
                P = b;
                D = z;
            }else {
                P = b + 1;
                D = x;
            }
 
            if(D * (b + 2) < y * P){
                P = b + 2;
                D = y;
            }
        }
 
        if(d * P >= p * D){
            p = p;
            d = d;
        }else {
            p = P;
            d = D;
        }
 
    }   
     
    if(d == 0){
        p = 1;
    }
 
 
    printf("%d" , p);
 
    return 0;
 
}