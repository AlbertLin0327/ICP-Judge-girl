#include <stdio.h>

int main(){
	long long num;

	while(scanf("%lld" , &num) != EOF){
		int ones = 0;

		for(int i = 0; i < 64; i++){
			if((num >> i) & 1){
				ones++;
			}
		}

		printf("%d\n", ones);

	}

	return 0;

}