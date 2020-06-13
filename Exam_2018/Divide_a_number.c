#include <stdio.h>
#include <stdbool.h>

int main(){
	int k  , N1 , N2;
	scanf("%d%d" , &k , &N1);

	if(N1 >= k){
		printf("%d\n", N1 / k);
		N1 %= k;
	}

	bool greater = 0;

	while(scanf("%d" , &N2) == 1){
		printf("%d\n", (N1 * 10 + N2) / k);
		N1 = (N1 * 10 + N2) % k;
		greater = 1;
	}

	if(greater == 0 && N1 < k){
		printf("0\n");
	}


	return 0;

}