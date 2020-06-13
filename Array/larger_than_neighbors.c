#include <stdio.h>

int main(){
	int r , c;
	scanf("%d%d" , &r , &c);

	int matrix[r][c];

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c ; j++){
			scanf("%d" , &(matrix[i][j]));
		}
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c ; j++){
			
			if(j != c - 1){
				if(matrix[i][j] <= matrix[i][j + 1])
					continue;
			}
			if(j != 0){
				if(matrix[i][j] <= matrix[i][j - 1])
					continue;
			}
			if(i != r - 1){
				if(matrix[i][j] <= matrix[i + 1][j])
					continue;
			}
			if(i != 0){
				if(matrix[i][j] <= matrix[i - 1][j])
					continue;
			}
			
			printf("%d\n" , matrix[i][j]);
			
		}
	}

	return 0;

}