#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

int index_arr[10] = {0};

int smallest(int n){
	int min_index = 0 , value = INT16_MAX;
	for(int i = 0; i < n; i++){
		if(index_arr[i] < value){
			value = index_arr[i];
			min_index = i;
		}
	}
	return (1 + min_index);
}	

int main(){
	char in[60] , out[60]; int N;
	scanf("%s%d%s" , in , &N , out);

	FILE* input = fopen(in , "rb");
	unsigned char c;

	// dark magic
	int counter = 1; char index[3];
	index[0] = '1'; index[1] = '\0';

	// File's name dark magic
	char target[60]; memcpy(target , out , strlen(out));
	target[strlen(out)] = '\0'; strcat(target , index);
	FILE* output = fopen(target , "ab");

	bool change = 0;
	while(fread(&c , 1 , 1 , input)){
		if(c == 255){
			if(change == 0)
				continue;
			fclose(output);
			counter = smallest(N);

			sprintf(index , "%d" , counter);
			memcpy(target , out , strlen(out));
			target[strlen(out)] = '\0'; strcat(target , index);

			output = fopen(target , "ab");
			change = 0;
			continue;
		}

		// counter
		index_arr[counter - 1]++;
		fputc(c , output);
		change = 1;
	}
	fclose(output);
	fclose(input);
}