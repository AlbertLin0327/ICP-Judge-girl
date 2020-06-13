#include <stdio.h>

int main(){
	int n , m;
	scanf("%d%d" , &n , &m);

	int board[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}

	int knight[m][3];
	for(int i = 0; i < m; i++){
		scanf("%d%d" , &(knight[i][0]) , &(knight[i][1]));
		board[(knight[i][0])][(knight[i][1])] = 10000 * (i + 1);
		knight[i][2] = 0;
	}

	int dx[8] = {-2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
	int dy[8] = {1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};

	for(int i = 0; i < n * n; i++){
		for(int j = 0 ; j < m; j++){

			if(knight[j][2] == -1){
				continue;
			}

			int count[8];
			for(int l = 0; l < 8; l++){
				count[l] = 8;
			}

			for(int k = 0; k < 8; k++){

				int temp_x = knight[j][0] + dx[k];
				int temp_y = knight[j][1] + dy[k];

				if(temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < n && board[temp_x][temp_y] == 0){

					count[k] = 0;

					for(int l = 0; l < 8; l++){
						int check_x = temp_x + dx[l];
						int check_y = temp_y + dy[l];

						if(check_x >= 0 && check_x < n && check_y >= 0 && check_y < n && board[check_x][check_y] == 0){
							count[k]++;
						}
					}
				}
			}

			int min = 8 , index = -1;

			for(int p = 0; p < 8; p++){
				if(min > count[p] && count[p] != 100){
					min = count[p];
					index = p;
				}
			}

			if(index != -1){
				knight[j][0] += dx[index];
				knight[j][1] += dy[index];
				knight[j][2]++;
				board[knight[j][0]][knight[j][1]] = 10000 * (j + 1) + knight[j][2];
			}

			if(index == -1){
				knight[j][2] = -1;
			}

		}
	}

	for(int i = 0; i < n; i++){
		printf("%d", board[i][0]);
		for(int j = 1; j < n; j++){
			printf(" %d", board[i][j]);
		}
		printf("\n");
	}
}