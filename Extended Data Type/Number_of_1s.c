#include <stdio.h>

int main(){
	int num;

	while(scanf("%d" , &num) != EOF){
		int ones = 0;

		for(int i = 0; i < 32; i++){
			if((num >> i) & 1){
				ones++;
			}
		}

		printf("%d\n", ones);

	}

	return 0;

}