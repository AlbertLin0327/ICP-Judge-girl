#include <stdio.h>

int main(){
	int a , b , c , d , e , f , g;
	scanf("%d%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f , &g);

	int distance = d;

	if(a == e && b == f) {
		if(c <= g){
			printf("0\n");
		}else if(d == 0){
			printf("0\n");
		}else{
			distance = d + g;
			if(distance > c) printf("%d\n" , c);
			else printf("%d\n" , distance);
		}
	}else if(d == 0){

		printf("0\n");

	}else if(g >= d){

		if(c >= g){

			if(e * f * d < (a * b - e * f) * (g - d)){
				distance = (e * f * d) / (a * b - e * f) + d;
			}else {
				distance = (e * f * d - (a * b - e * f) * (g - d)) / (a * b) + g;
			}

		}else {
			if(e * f * d > (a * b - e * f) * (c - d)){
				distance = c;
			}else {
				distance = (e * f * d) / (a * b - e * f) + d;
			}
		}

		

		if(distance > c) printf("%d\n" , c);
		else printf("%d\n" , distance);

	} else {
		if(g <= d){

		distance = (a * b * d + e * f * g) / (a * b);
		if(distance > c) printf("%d\n" , c);
		else printf("%d\n" , distance);

		}

	}

	
	return 0;
	
}