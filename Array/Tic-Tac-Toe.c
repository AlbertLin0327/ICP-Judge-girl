#include <stdio.h>
#include <stdbool.h>

int main(){
	int matrix[3][3] = {0};

	//black = 1    white = -1
	int player = 1;

	int N;
	scanf("ddd%d" , &N);

	int draw = 1;

	while(N--){
		int x , y;
		scanf("%d%d" , &x , &y);

		if(x < 0 || y < 0 || x > 2 || y > 2)	{
			continue;
		}
		if(matrix[x][y] != 0){
			continue;
		}

		matrix[x][y] = player;

		if( (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && matrix[0][0] == matrix[0][2] && matrix[0][0] == 1) ||\
			(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][0] == matrix[1][2] && matrix[1][0] == 1) ||\
			(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][0] == matrix[2][2] && matrix[2][0] == 1) ||\
			(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && matrix[0][0] == matrix[2][0] && matrix[0][0] == 1) ||\
			(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[0][1] == matrix[2][1] && matrix[0][1] == 1) ||\
			(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && matrix[0][2] == matrix[2][2] && matrix[0][2] == 1) ||\
			(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] == matrix[2][2] && matrix[0][0] == 1) ||\
			(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[2][0] == matrix[0][2] && matrix[2][0] == 1) ){
				printf("Black wins.\n");
				draw = 0;
				break;
		}

		if( (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && matrix[0][0] == matrix[0][2] && matrix[0][0] == -1) ||\
			(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][0] == matrix[1][2] && matrix[1][0] == -1) ||\
			(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][0] == matrix[2][2] && matrix[2][0] == -1) ||\
			(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && matrix[0][0] == matrix[2][0] && matrix[0][0] == -1) ||\
			(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[0][1] == matrix[2][1] && matrix[0][1] == -1) ||\
			(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && matrix[0][2] == matrix[2][2] && matrix[0][2] == -1) ||\
			(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] == matrix[2][2] && matrix[0][0] == -1) ||\
			(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2] && matrix[2][0] == matrix[0][2] && matrix[2][0] == -1) ){
				printf("White wins.\n");
				draw = 0;
				break;
		}

		player *= (-1);
			

	}

	if(draw == 1){
		printf("There is a draw.\n");
	}


	return 0;

}