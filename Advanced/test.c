#include <stdio.h>

int main(){
	int n = 3;

	while(n--){
		printf("%d\n", n);
	}
	//output : 2 , 1 , 0

	printf("\n");

	n = 3;
	while(--n){
		printf("%d\n", n);
	}
	//output : 2 , 1

	return 0;
	
}