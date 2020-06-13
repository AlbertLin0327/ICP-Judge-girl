int evaluate_f(int *iptr[], int n, int *index){
	*index = 0;

	int max = 4 * (*(iptr[0])) - 6 * (*(iptr[0] + 1));

	for(int i = 0; i < n; i++){

		if(max < 4 * iptr[i][0] - 6 * iptr[i][1]){
			max = 4 * iptr[i][0] - 6 * iptr[i][1];
			*index = i;
		}

	}

	return max;

}