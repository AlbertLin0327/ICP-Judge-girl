int validMoveNum(int r, int c, int n, int visited[100][100]){

	int count = 0;
	int move[8][2] = {{-2 , 1} , {-1 , 2} , {1 , 2} , {2 , 1} , {2 , -1} , {1 , -2} , {-1 , -2} , {-2 , -1}};

	if(r < 0 || c < 0 || r >= n || c >= n ||visited[r][c] != 0){
		return -1;
	}

	for(int i = 0; i < 8; i++){
		if((r + move[i][0] >= 0 && r + move[i][0] < n) && (c + move[i][1] >= 0 && c + move[i][1] < n) && visited[r + move[i][0]][c + move[i][1]] == 0){
			count++;
		}
	}

	return count;

}