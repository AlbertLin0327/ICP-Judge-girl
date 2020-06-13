#include <stdio.h>

int main(){
	int n;
	scanf("%d" , &n);

	double matrix[n][n];

	for(int i = 0; i < n;i++){
		for(int j = 0; j < n; j++){
			scanf("%lf" , &(matrix[i][j]));
		}
	} 

	double y[n];
	for(int i = 0; i < n; i++){
		scanf("%lf" , &(y[i]));
	}

	double x[n];

	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j > i; j--){
			y[i] -= x[j] * matrix[i][j];
		}
		x[i] = y[i] / matrix[i][i];
	}

	for(int i = 0; i < n; i++){
		printf("%f\n" , x[i]);
	}

	return 0;

}