#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
 
bool buffer[1048576][64];
 
void transmission(long long int belt[] , int N , int T){
 
    long long int * temp = malloc(N * sizeof(long long int));
    memcpy(temp , belt , N * sizeof(long long int));
 
    for(int i = 0; i < N; i++){
        belt[i] = temp[(i + T / 64) % N];
    }
 
    free(temp);
    T %= 64;
 
    for(int i = 0; i < T; i++){

    	long long int msb = belt[0] >> 63 & 1ll;

        for(int j = 0; j < N; j++){ 
        	belt[j] = belt[j] << 1;
        	belt[j] += (j == N - 1 ? msb : belt[j + 1] >> 63 & 1ll);
        }
    }
 	return;
}