#include <stdio.h>

int main(){
	int a;
	scanf("%d" , &a);
	int f[a];
	for(int i = a - 1; i >= 0; i--){
		scanf("%d" , &(f[i]));
	}

	int b;
	scanf("%d" , &b);
	int g[b];
	for(int i = b - 1; i >= 0; i--){
		scanf("%d" , &(g[i]));
	}

	int h[a + b - 1];
	for(int i = 0; i < a + b - 1; i++){
		h[i] = 0;
	}

	for (int i = 0; i < a; i++){
		for (int j = 0; j < b; j++){
			h[i + j] += f[i] * g[j];
		}
	}

	for (int i = a + b - 2; i >= 0; i--){
		if(i != 0){
			printf("%d " , h[i]);
		}
		if(i == 0){
			printf("%d\n" , h[i]);
		}
	}

	return 0;

}