#include <stdio.h>
#include <stdbool.h>

int main(){

	int N , num;
	while(scanf("%d" , &N) != EOF){

		int max = -10001 , min = 10001;

		while(N-- && scanf("%d" , &num) != EOF){
			max = (max > num ? max : num);
            min = (min < num ? min : num);
		}

		printf("%d\n", (N == -1) ? max : min);
	}

	return 0;
}