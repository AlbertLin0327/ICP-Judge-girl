#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum TYPE{one = 1 , two , three , four}type;

bool split(int l , int i , int j , type T){
	if(l == 1){
		printf("1 %d %d\n", i + 1 , j + 1);
		exit(0);
	}else if(l == 2){
		switch(T){
			case one:
				printf("%d %d %d\n" , T , i + 1 , j + 1);
				break;
			case two:
				printf("%d %d %d\n" , T , i - 1 , j + 1);
				break;
			case three:
				printf("%d %d %d\n" , T , i - 1 , j - 1);
				break;
			case four:
				printf("%d %d %d\n" , T , i + 1 , j - 1);
				break;
		}
	}else{
		switch(T){
			case one:
				return (split(l / 2 , i , j , one) + split(l / 2 , i , j + l , four) + split(l / 2 , i + l / 4 , j + l / 4 , one) + split(l / 2 , i + l , j , two));
				break;
			case two:
				return (split(l / 2 , i , j , two) + split(l / 2 , i , j + l , three) + split(l / 2 , i - l / 4 , j + l / 4 , two) + split(l / 2 , i - l , j , one));
				break;
			case three:
				return (split(l / 2 , i , j , three) + split(l / 2 , i , j - l , two) + split(l / 2 , i - l / 4 , j - l / 4 , three) + split(l / 2 , i - l , j , four));
				break;
			case four:
				return (split(l / 2 , i , j , four) + split(l / 2 , i , j - l , one) + split(l / 2 , i + l / 4 , j - l / 4 , four) + split(l / 2 , i + l , j , three));
				break;
		}
	}
}

int main(){
	int l , m; scanf("%d %d" , &l , &m);
	
	
	for(int k = 0 , r = l; m + k != l;){
		split(r / 2 , k , k , 1);
		split(r / 2 , k + r , k , 2);
		split(r / 2 , k , k + r , 4);
		split(r / 2, k + r / 4, k + r / 4 , 1);
		r /= 2; k += r;
	}
		
	

}