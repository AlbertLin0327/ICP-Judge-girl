int findLength (int array[256][256], int N, int r, int c, int dr, int dc){
	int result = 0 , max = 0;

	while(r >= 0 && r <= N - 1 && c >= 0 && c <= N - 1){
		if(array[r][c] == 1){
			result++;
		}else{
			result = 0;
		}
		max = (max > result ? max : result);
		r += dr; c += dc;
	}

	return (max);

}