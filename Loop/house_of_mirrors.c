#include <stdio.h>
#include <stdbool.h>

int main(){

	int w , d;
	scanf("%d%d" , & w , &d);

	bool house[w][d];
	for(int i = d - 1; i >= 0; i--){
		for(int j = 0; j < w; j++){
			int mirror;
			scanf("%d" , &mirror);
			house[j][i] = (mirror == 1); 
		}
	} 

	int dx[4] = {0 , -1 , 0 , 1};
	int dy[4] = {1 , 0 , -1 , 0};
	int Dir[4] = {3 , 2 , 1 , 0};


	int x , y , dirrection;

	for(int i = 0; i < 2 * (w + d); i++){
		if(i < w){
			x = i;
			y = 0;
			dirrection = 0;
		}else if(i < w + d){
			x = w - 1; y = i - w; dirrection = 1;
		}else if(i < 2 * w + d){
			x = w - (i - (w + d)) - 1; y = d - 1; dirrection = 2;
		}else {
			x = 0; y = d - (i - (d + 2 * w)) - 1; dirrection = 3;
		}

		while(x >= 0 && x < w && y >= 0 && y < d){
			if(house[x][y] == 1){
				dirrection = Dir[dirrection];
			}
			x += dx[dirrection];
			y += dy[dirrection];
		}

		if(y < 0)
			printf("%d\n" , x);
		else if(x >= w)
			printf("%d\n" , w + y);
		else if(y >= d)
			printf("%d\n" , 2 * w + d - x - 1);
		else
			printf("%d\n" , 2 * w + 2 * d - y - 1);
	}

	return 0;
}