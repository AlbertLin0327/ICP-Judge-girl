#include <stdio.h>

int main(){
	int n;
	scanf("%d" , &n);

	int road[102][102] = {5};

	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n +1; j++){
			scanf("%d" , &(road[i][j]));
		}
	}

	int count[4] = {0};
	//intersections, T-junctions, turns and dead ends

	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++){
			if(road[i][j] == 1){
				if(road[i - 1][j] + road[i + 1][j] + road[i][j + 1] + road[i][j - 1] == 4)
					count[0]++;
				if(road[i - 1][j] + road[i + 1][j] + road[i][j + 1] + road[i][j - 1] == 3)
					count[1]++;
				if(road[i - 1][j] + road[i + 1][j] + road[i][j + 1] + road[i][j - 1] == 2 && ((road[i - 1][j] == 1 && road[i][j + 1] == 1) || (road[i - 1][j] == 1 && road[i][j - 1] == 1) || (road[i + 1][j] == 1 && road[i][j + 1] == 1) || (road[i + 1][j] == 1 && road[i][j - 1] == 1)))
					count[2]++;
				if(road[i - 1][j] + road[i + 1][j] + road[i][j + 1] + road[i][j - 1] == 1)
					count[3]++;
			}
			
		}
	}

	for(int i = 0; i < 4; i++){
		printf("%d\n", count[i]);
	}

	return 0;

}