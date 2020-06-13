#include <stdio.h>
#define max(x , y) (x >= y ? x : y)

int main(){
	int n;
	scanf("%d" , &n);

	int map[n][n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n ; j++){
			scanf("%d" , &map[i][j]);
		}
	}

	int row = 0 , column = 0 , diagonal1 = 0 , diagonal2 = 0;
	int Max = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n ; j++){

			if(map[i][j] == 0){
				row = 0;
			}else{
				row++;
			}

			if(map[j][i] == 0){
				column = 0;
			}else{
				column++;
			}


			if(i + j < n){
				if(map[i + j][j] == 0){
					diagonal1 = 0;
				}else{
					diagonal1++;
				}

				if(map[j][i + j] == 0){
					diagonal2 = 0;
				}else{
					diagonal2++;
				}
			}

			Max = max(row , max(column , max(diagonal1 , max(diagonal2 , Max))));
			
		}

		column = 0; row = 0; diagonal1 = 0; diagonal2 = 0;

	}

	printf("%d\n", Max);

	return 0;

}