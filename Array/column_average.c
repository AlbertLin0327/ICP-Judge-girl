#include <stdio.h>

int main(){
	int r , c;
	scanf("%d%d" , &r , &c);

	int matrix[r][c];

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d" , &(matrix[i][j]));
		}
	}

	for(int i = 0; i < c; i++){

		int average = 0;

		for(int j = 0; j < r; j++){
			average += matrix[j][i];
		}

		average /= r;
		printf("%d\n", average);

	}

	return 0;

}