#include <stdio.h>

int main(){
	int r , c; scanf("%d%d" , &r , &c);

	int arr[r][c];
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d" , &arr[i][j]);
		}
	}

	int count = 0;

	for(int i = 0; i + 2 < r; i++){
		for(int j = 0; j + 3 < c; j++){
			if(arr[i + 1][j] + arr[i + 1][j + 2] == 7 && arr[i + 1][j + 1] + arr[i + 1][j + 3] == 7 && arr[i + 1][j] != arr[i + 1][j + 1] && arr[i + 1][j] != arr[i + 1][j + 3]){
				for(int k = 0; k < 4; k++){
					for(int l = 0; l < 4; l++){
						if(arr[i][k + j] + arr[i + 2][l + j] == 7 && arr[i][k + j] != arr[i + 1][j] && arr[i][k + j] != arr[i + 1][j + 1] && arr[i][k + j] != arr[i + 1][j + 2] && arr[i][k + j] != arr[i + 1][j + 3]\
							&& arr[i + 2][l + j] != arr[i + 1][j] && arr[i + 2][l + j] != arr[i + 1][j + 1] && arr[i + 2][l + j] != arr[i + 1][j + 2] && arr[i + 2][l + j] != arr[i + 1][j + 3]){
							count++;		
						}
					}
				}
			}
		}
	}

	printf("%d\n", count);

	return 0;

}