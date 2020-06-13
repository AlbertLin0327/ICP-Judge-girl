#include <stdio.h>
#include <stdbool.h>


int main(){
	int N , M;
	scanf("%d%d" , &N , &M);

	int map[N][M];

	for(int i = 0 ; i < N ; i++){
		for(int j = 0; j < M; j++){
			map[i][j] = 0;
		}
	}

	int energy , x , y;
	scanf("%d%d%d" , &y , &x , &energy);
	map[y][x] = energy;

	int stones;
	scanf("%d" , &stones);

	while(stones--){
		int stone_x , stone_y , stone_energy;
		scanf("%d%d%d" , &stone_y , &stone_x , &stone_energy);
		map[stone_y][stone_x] = stone_energy;
	}

	int instruction;
	int hole;

	while(scanf("%d" , &instruction) == 1){
		int accumulate = 0;
		bool push = 0;

		switch(instruction){
			case 0 :
				for(int i = 0 ; i < N ; i++){
					printf("%d", map[i][0]);
					for(int j = 1; j < M; j++){
						printf(" %d", map[i][j]);
					}
					printf("\n");
				}
				break;

			case 1 :
				if(x == M - 1)
					break;
				for(int i = x + 1; i < M; i++){
					if(map[y][i] == 0){
						push = 1;
						hole = i;
						break;
					}else{
						accumulate += map[y][i];
					}

				}

				if(energy >= accumulate && push == 1){
					energy -= accumulate;
					map[y][x] = energy;
					for(int i = hole; i > x; i--){
						map[y][i] = map[y][i - 1];
					}
					map[y][x] = 0;
					x++;
				}
				break;

			case 2 :
				if(y == N - 1)
					break;
				for(int i = y + 1; i < N; i++){
					if(map[i][x] == 0){
						push = 1;
						hole = i;
						break;
					}else{
						accumulate += map[i][x];
					}

				}

				if(energy >= accumulate && push == 1){
					energy -= accumulate;
					map[y][x] = energy;
					for(int i = hole; i > y; i--){
						map[i][x] = map[i - 1][x];
					}
					map[y][x] = 0;
					y++;
				}
				break;

			case 3 :
				if(x == 0)
					break;
				for(int i = x - 1; i >= 0; i--){
					if(map[y][i] == 0){
						push = 1;
						hole = i;
						break;
					}else{
						accumulate += map[y][i];
					}

				}

				if(energy >= accumulate && push == 1){
					energy -= accumulate;
					map[y][x] = energy;
					for(int i = hole; i < x; i++){
						map[y][i] = map[y][i + 1];
					}
					map[y][x] = 0;
					x--;
				}
				break;

			case 4 :
				if(y == 0)
					break;
				for(int i = y - 1; i >= 0; i--){
					if(map[i][x] == 0){
						push = 1;
						hole = i;
						break;
					}else{
						accumulate += map[i][x];
					}

				}

				if(energy >= accumulate && push == 1){
					energy -= accumulate;
					map[y][x] = energy;
					for(int i = hole; i < y; i++){
						map[i][x] = map[i + 1][x];
					}
					map[y][x] = 0;
					y--;
				}
				break;	

		}

	}

	return 0;

}