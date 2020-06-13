#include <stdio.h>

int main(){
	int digit , n = 0 , zero = 0 , eleven = 0;

	while(scanf("%d" , &digit) != EOF){

		if(!(n % 2)){
				eleven += digit;
			}else {
				eleven -= digit;
			}
		n++;
		if(digit == 0){
			zero++;
		} 
		
	}

	printf("%d\n" , n);

	if(!(digit % 2)){
		printf("1\n");
	} 
	else{
		printf("0\n");
	} 

	printf("%d\n" , zero);

	if(!(eleven % 11)){
		printf("1\n");
	} 
	else {
		printf("0\n");
	}

	return 0;

}