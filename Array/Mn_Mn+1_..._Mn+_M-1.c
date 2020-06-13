#include <stdio.h>

int main(){

	int n;
	scanf("%d" , &n);

	int array[n];

	for(int i = 0; i <= n; i++){
		scanf("%d" , &(array[i]));
	}


	int count[200000] = {0};

	for(int i = 0; i < n; i++){
		int mod = array[i] % array[n];
		count[mod]++;
	}

	for(int i = 0; i < array[n]; i++){
		printf("%d\n", count[i]);
	}

	return 0;

}