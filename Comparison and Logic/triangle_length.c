#include <stdio.h>

int main(){

	int a , b , c;

	scanf("%d\n%d\n%d" , &a , &b , &c);

	if(a + b > c && b + c > a && c + a > b && a > 0 && b > 0 && c > 0){
		printf("1\n");
	} else{
		printf("0\n");
	}

	return 0;

}