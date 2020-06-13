#include <stdlib.h>

void prepare_array(int buffer[], int *array[], int row, int column[]){

	int *start = &buffer[0];

	for (int i = 0; i < row; i++){
		//array[i] = malloc(column[i] * sizeof(int));
		array[i] = start;
		start += column[i];
	}
     
}