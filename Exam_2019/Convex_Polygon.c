#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
 
    int n; scanf("%d" , &n);
 
    double x[n] , y[n];
 
    double a1 , b1 , c1; scanf("%lf%lf%lf" , &a1 , &b1 , &c1);
    double a1_f = a1 , b1_f = b1 , c1_f = c1;
 
    double a2 , b2 , c2;
    for(int i = 0; i < n - 1; i++){

        scanf("%lf%lf%lf" , &a2 , &b2 , &c2);
        y[i] = (c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
        x[i] = (a1 * c2 - c1 * a2) / (a1 * b2 - b1 * a2);

        a1 = a2; b1 = b2; c1 = c2;

    }
 
    y[n - 1] = (c1 * b1_f - b1 * c1_f) / (a1 * b1_f - b1 * a1_f);
    x[n - 1] = (a1 * c1_f - c1 * a1_f) / (a1 * b1_f - b1 * a1_f);
 
 
    double sum = 0;
 
    for(int i = 0; i < n - 1; i++){
        sum += sqrt(pow((x[i] - x[i + 1]) , 2) + pow((y[i] - y[i + 1]) , 2));
    }
    sum += sqrt(pow((x[0] - x[n - 1]) , 2) + pow((y[0] - y[n - 1]) , 2));
 
    printf("%.3lf\n", sum);
 
 
 
    return 0;
}