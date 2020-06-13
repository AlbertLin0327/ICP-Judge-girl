#include <stdio.h>
#include <stdbool.h>

bool ones_counter(char n){
	int result = 0;
	for(int i = 0; i < 8; i++){
		result += ((n >> i) & 1);
	}
	return (result <= 1);
}

void ngram(unsigned char* storage , unsigned char key , int n){
	for(int i = 0; i < n; i++){
		char difference = (storage[i] ^ key);
		if(ones_counter(difference)){
			printf("%d\n", storage[i]);
			return;
		}
	}
}

int main(){
	int N , M , P; scanf("%d %d %d" , &N , &M , &P);
	unsigned long long int num[M];
	unsigned char storage[N + 2];
	unsigned char key;

	for(int i = 0; i < M; i++){
		scanf("%llu" , &num[i]);
	}

	for(int i = 0; i < N; i++){
		storage[i] = (unsigned char)(num[i / 8] >> (7 - i % 8) * 8);
	}

	while(P--){
		scanf("%hhu" , &key);
		ngram(storage , key , N);
	}

}