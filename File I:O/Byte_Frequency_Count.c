#include <stdio.h>
#include <stdint.h>

int appear[1<<17];

int main(){
	char filename[10]; scanf("%s" , filename);

	FILE* input = fopen(filename , "rb");

	int num;
	fread(&num , sizeof(int) , 1 , input);

	int16_t buffer[num + 5];
	fread(buffer , 2 , num , input);

	for(int i = 0; i < num; i++){
		appear[buffer[i] + 32768]++;
	}

	fclose(input);

	int max = -32768 , max_appear = 0;
	for(int i = 0; i < (1<<17); i++){
		if(appear[i] >= max_appear){
			max_appear = appear[i];
			max = i;
		}
	}

	printf("%d\n%d\n", (int16_t)(max - 32768) , max_appear);

	return 0;

}