#include <stdio.h>

#define max(x , y) ((x > y)? x : y)
#define min(x , y) ((x < y)? x : y)


int main(){
	int a ,  b , c , d = 0 , e = 0 , f = 0 ;
	scanf("%d %d %d" , &a , &b , &c);

	for(int i = 0; i <= 100000 ; i++){
		if(i * i * i + a * i * i + b * i + c == 0){
			f = -i;
			break;
		}
		if(- i * i * i + a * i * i - b * i + c == 0){
			f = i;
			break;
		}
	}

	for(int i = 0; i <= 100000; i++){
		if(i * i + (a - f) * i + b - f * (a - f) == 0){
			e = -i;
			break;
		}
		if(i * i - (a - f) * i + b - f * (a - f) == 0){
			e = i;
			break;
		}
	}

	for(int i = 0; i <= 100000; i++){
		if(i + a - f - e == 0){
			d = -i;
			break;
		}
		if(-i + a - f - e == 0){
			d = i;
			break;
		}
	}

	printf("%d %d %d\n" , min(d , min (e , f)) , d + e + f - min(d , min(e , f)) -  max(d , max(e , f)) , max(d , max(e , f)));

	return 0;
}