void intersection(int map[100][100], int result[4]){

	//intersections, T-junctions, turns and dead ends
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;

	for(int i = 1; i < 99; i++){
		for(int j = 1; j < 99; j++){
			if(map[i][j] == 1){
				if(map[i - 1][j] + map[i + 1][j] + map[i][j + 1] + map[i][j - 1] == 4)
					result[0]++;
				if(map[i - 1][j] + map[i + 1][j] + map[i][j + 1] + map[i][j - 1] == 3)
					result[1]++;
				if(map[i - 1][j] + map[i + 1][j] + map[i][j + 1] + map[i][j - 1] == 2 && ((map[i - 1][j] == 1 && map[i][j + 1] == 1) || (map[i - 1][j] == 1 && map[i][j - 1] == 1) || (map[i + 1][j] == 1 && map[i][j + 1] == 1) || (map[i + 1][j] == 1 && map[i][j - 1] == 1)))
					result[2]++;
				if(map[i - 1][j] + map[i + 1][j] + map[i][j + 1] + map[i][j - 1] == 1)
					result[3]++;
			}
			
		}
	}

	for(int j = 1; j < 99; j++){
		if(map[0][j] == 1){
			if(map[1][j] + map[0][j + 1] + map[0][j - 1] == 3)
				result[1]++;
			if(map[1][j] + map[0][j + 1] + map[0][j - 1] == 2 && map[0][j + 1] + map[0][j - 1] != 2)
				result[2]++;
			if(map[0][j + 1] + map[0][j - 1] + map[1][j] == 1)
				result[3]++;
		}
	}

	for(int j = 1; j < 99; j++){
		if(map[99][j] == 1){
			if(map[98][j] + map[99][j + 1] + map[99][j - 1] == 3)
				result[1]++;
			if(map[98][j] + map[99][j + 1] + map[99][j - 1] == 2 && map[99][j + 1] + map[99][j - 1] != 2)
				result[2]++;
			if(map[99][j + 1] + map[99][j - 1] + map[98][j] == 1)
				result[3]++;
		}
	}

	for(int i = 1; i < 99; i++){
		if(map[i][0] == 1){
			if(map[i - 1][0] + map[i + 1][0] + map[i][1] == 3)
				result[1]++;
			if(map[i - 1][0] + map[i + 1][0] + map[i][1] == 2 && map[i - 1][0] + map[i + 1][0] != 2)
				result[2]++;
			if(map[i - 1][0] + map[i + 1][0] + map[i][1] == 1)
				result[3]++;
		}
			
	}

	for(int i = 1; i < 99; i++){
		if(map[i][99] == 1){
			if(map[i - 1][99] + map[i + 1][99] + map[i][98] == 3)
				result[1]++;
			if(map[i - 1][99] + map[i + 1][99] + map[i][98] == 2 && map[i - 1][99] + map[i + 1][99] != 2)
				result[2]++;
			if(map[i - 1][99] + map[i + 1][99] + map[i][98] == 1)
				result[3]++;
		}
			
	}

	if(map[0][0] == 1){
		if(map[0][1] + map[1][0] == 2)
			result[2]++;
		if(map[0][1] + map[1][0] == 1)
			result[3]++;
	}
	if(map[99][99] == 1){
		if(map[99][98] + map[98][99] == 2)
			result[2]++;
		if(map[99][98] + map[98][99] == 1)
			result[3]++;
	}
	if(map[0][99] == 1){
		if(map[0][98] + map[1][99] == 2)
			result[2]++;
		if(map[0][98] + map[1][99] == 1)
			result[3]++;
	}
	if(map[99][0] == 1){
		if(map[99][1] + map[98][0] == 2)
			result[2]++;
		if(map[99][1] + map[98][0] == 1)
			result[3]++;
	}
	

}
