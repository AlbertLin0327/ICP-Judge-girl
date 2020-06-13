#include <stdbool.h>
#include "validMoveNum.h"

int nextMove(int r, int c, int n, int visited[100][100]){
	int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
	int min = 10 , min_index = -1;

	for(int i = 0; i < 8; i++){
		if(validMoveNum(r + move[i][0], c + move[i][1], n , visited) >= 0 && validMoveNum(r + move[i][0], c+move[i][1], n, visited) < min){
			min = validMoveNum(r + move[i][0], c + move[i][1], n, visited);
			min_index = i;
		}
	}

	return min_index;

}



/*#include <stdbool.h>

int nextMove(int r, int c, int n, int visited[100][100]){
	int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
	int min = 10 , min_index = -1;

	for(int i = 0; i < 8; i++){
		int temp_r = r + move[i][0] , temp_c = c + move[i][1];
		int count = 0;

		if(!(temp_r >= 0 && temp_r < n && temp_c >= 0 && temp_c < n && visited[temp_r][temp_c] == 0))
			continue;

		for(int j = 0; j < 8; j++){
			if((temp_r + move[j][0] >= 0 && temp_r + move[j][0] < n) && (temp_c + move[j][1] >= 0 && temp_c + move[j][1] < n) && visited[temp_r + move[j][0]][temp_c + move[j][1]] == 0){
				count++;
			}
		}
		if(count < min){
			min = count;
			min_index = i;
		}
		
	}

	return min_index;

}*/
