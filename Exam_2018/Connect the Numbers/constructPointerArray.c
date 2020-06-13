void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){

	static short int location[1024 * 1024][2];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			location[A[i][j]][0] = i; location[A[i][j]][1] = j;
		}
	}

	int index = 0;
	while(index < N * N){
		int next = (index + 1) % (N * N);
		B[location[index][0]][location[index][1]] = &(A[location[next][0]][location[next][1]]);
		index++;
	}

	return;

}