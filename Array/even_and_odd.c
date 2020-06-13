#include <stdio.h>

int main(){

	int even[1000] , odd[1000];

	int n;
	scanf("%d" , &n);

	int even_num = 0 , odd_num = 0;

	while(n--){
		int num;
		scanf("%d" , &num);

		if(num % 2){
			odd[odd_num] = num;
			odd_num++;
		}else {
			even[even_num] = num;
			even_num++;
		}
	}

	for(int i = 0; i < odd_num; i++){
		printf("%d", odd[i]);
		if(i != odd_num - 1) printf(" ");
	}
	printf("\n");
	for(int i = 0; i < even_num; i++){
		printf("%d", even[i]);
		if(i != even_num - 1) printf(" ");
	}
	printf("\n");

	return 0;
	
}