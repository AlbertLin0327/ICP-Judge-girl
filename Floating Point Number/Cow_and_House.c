#include <stdio.h>
#define pi 3.1415926

int main(){
	double a , b , c;
	scanf("%lf%lf%lf" , &a , &b , &c);
	double area = pi * c * c * 0.75;

	if(c > b){
		area += pi * (c - b) * (c - b) / 4;
	}
	if(c > a){
		area += pi * (c - a) * (c - a) / 4;
	}

	printf("%f\n" , area);

	return 0; 

}