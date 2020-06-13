#include <stdio.h>
#include <stdlib.h>
#define MAX 65540

int main(void){
	int key; scanf("%d" , &key);

	FILE* input = fopen("test" , "rb");
	FILE* output = fopen("test.enc" , "wb");

	int file_size;
	char buffer[MAX];

	while((file_size = fread(buffer , 1 , MAX , input)) != 0){
		for(int i = 0; i < file_size; i++)
			buffer[i] ^= key;
		fwrite(buffer , 1 , file_size , output);
	}

	fclose(input);
	fclose(output);

	return 0;

}																