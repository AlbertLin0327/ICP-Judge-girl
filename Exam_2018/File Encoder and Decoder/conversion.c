#define min(x , y) (x < y ? x : y)
#include <stdio.h>

void bin2ascii(char input_file[32], char output_file[32], char dict[17]){
	FILE* input = fopen(input_file , "rb");
	FILE* output = fopen(output_file , "wt");

	fseek(input , 0 , SEEK_END);
	int len = ftell(input);
	rewind(input);

	unsigned char buffer[16] , result[32];
	while(len){
		int count = min(len , 16);
		fread(buffer , sizeof(char) , count , input);

		for(int i = 0; i < count; i++){
			char a = ((buffer[i]) >> 4) & 0x0F;
			char b = buffer[i] & 0x0F;
			result[2 * i] = dict[a];
			result[2 * i + 1] = dict[b];
		}
		len -= count;
		fwrite(result , sizeof(char) , count * 2 , output);
	}
	fclose(input); fclose(output);
}

void ascii2bin(char input_file[32], char output_file[32], char dict[17]){
	FILE* input = fopen(input_file , "rt");
	FILE* output = fopen(output_file , "wb");

	fseek(input , 0 , SEEK_END);
	int len = ftell(input);
	rewind(input);

	char buffer[32] , result[16];
	while(len){
		int count = min(len , 16);
		fread(buffer , sizeof(char) , count , input);

		for(int i = 0; i < count; i++){
			char a = buffer[2 * i];
			char b = buffer[2 * i + 1];
			char num_front = 0 , num_back = 0;
			for(int j = 0; j < 16; j++){
				if(a == dict[j])
					num_front = j;
				if(b == dict[j])
					num_back = j;
			}
			result[i] = ((num_front << 4) + num_back);
		}
		len -= count;
		fwrite(result , sizeof(char) , count / 2 , output);
	}
	fclose(input); fclose(output);
}