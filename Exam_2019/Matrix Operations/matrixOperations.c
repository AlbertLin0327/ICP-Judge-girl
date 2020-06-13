#include<stdint.h>
#include <stdio.h>
#include <stdbool.h>

void printMatrix(uint64_t *matrix){
	printf("%llu\n", *matrix);

	for(int i = 0; i < 64; i++){
		printf("%d", (bool)((*matrix >> i) & 1));
		if((i & 7) == 7)
			printf("\n");
	}
}

void rotateMatrix(uint64_t *matrix){
	bool array[8][8];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			array[j][7 - i] = (bool)((*matrix >> (i * 8 + j)) & 1);

	*matrix = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			*matrix |= ((uint64_t)array[i][j] << (i * 8 + j));

}

void transposeMatrix(uint64_t *matrix){
	bool array[8][8];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			array[j][i] = (bool)((*matrix >> (i * 8 + j)) & 1);

	*matrix = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			*matrix |= ((uint64_t)array[i][j] << (i * 8 + j));
}