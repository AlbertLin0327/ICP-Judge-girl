void snake(const int *ptr_array[100][100], int m){

	for(int i = m * m - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			int value_front = *(ptr_array[j / m][j % m]);
			int value_back = *(ptr_array[(j + 1) / m][(j + 1) % m]);

			if(value_front > value_back){
				const int* temp = ptr_array[j / m][j % m];
				ptr_array[j / m][j % m] = ptr_array[(j + 1) / m][(j + 1) % m];
				ptr_array[(j + 1) / m][(j + 1) % m] = temp;
			}

		}

	}

	for(int i = 1; i < m; i += 2){
		for(int j = 0 ; j < m / 2; j ++){
			const int* temp = ptr_array[i][j];
			ptr_array[i][j] = ptr_array[i][m - 1 - j];
			ptr_array[i][m - 1 - j] = temp;
		}
	}

}