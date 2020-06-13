#include <stdio.h>

int main(){
	int N , k , x , y;
	scanf("%d%d%d%d" , &N , &k , &x , &y);

	int square[N][N];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			square[i][j] = -1;
		}
	}

	while(k != 1){
		x++;
		y--;
		k--;
		
		if(x > N - 1){
			x = 0;
		}
		if(y < 0){
			y = N - 1;
		}
	}

	square[x][y] = 1;
	k++;

	while(k <= N * N){
		x--;
		y++;
		
		if(x < 0){
			x = N - 1;
		}
		if(y > N - 1){
			y = 0;
		}
		if(square[x][y] == -1){
			square[x][y] = k;
		}else{
			x += 2;
			y--;
			if(x == N){
				x = 0;
			}else if(x == N + 1){
				x = 1;
			}
			if(y < 0){
				y = N - 1;
			}
			
			square[x][y] = k;
		}
		k++;
	}

	for(int i = 0; i < N; i++){
		printf("%d", square[i][0]);
		for(int j = 1; j < N; j++){
			printf(" %d", square[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}