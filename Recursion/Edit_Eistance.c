#include <stdio.h>
#include <string.h>
#define min(x , y) (x < y ? x : y);

int count(char* a , char* b , int edit , int min){
	if(edit > min)
		return 30;
	if(!*a){
		int i = 0;
		while(*(b + i) != 0){
			i++;
		}
		return i;
	}
	if(!*b){
		int i = 0;
		while(*(a + i) != 0){
			i++;
		}
		return i;
	}

	while(*a == *b && *a != 0 && *b != 0){
		a++; b++;
	}

	if(*a == *b && *a == 0)
		return 0;

	return 1 + min(count(a + 1 , b , edit + 1 , min) , count(a , b + 1 , edit + 1 , min));

}

int main(){
	char str[105][12];

	int n = 0;
	while(fgets(str[n] , 12 , stdin) != NULL){
		n++; 
	}

	int min = 30 , a , b;

	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			int current = count(str[i] , str[j] , 0 , min);

			if(current < min){
				min = current;
				a = i; b = j;
			}else if(current == min){
				if(1000 * i + j < 1000 * a + b){
					a = i; b = j; min = current;
				}
			}

		}
	}

	printf("%d %d %d\n", min , a + 1 , b + 1);

	return 0;

}