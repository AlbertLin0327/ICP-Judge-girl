#include <stdio.h>
#include <stdbool.h>

int main(){
	int n , m;
	scanf("%d%d" , &n , &m);

	char name[n][64];
	int place_x[n][m * m];
	int place_y[n][m * m];
	int row[n][m];
	int column[n][m];
	int diagonal1[n];
	int diagonal2[n];

	int num;

	for(int i = 0; i < n; i++){
		diagonal1[i] = 0;
		diagonal2[i] = 0;
		for(int j = 0; j < m; j++){
			row[i][j] = 0;
			column[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++){
		scanf("%s" , name[i]);
		for(int j = 0; j < m * m; j++){
			scanf("%d" , &num);
			place_x[i][num - 1] = j % m;
			place_y[i][num - 1] = j / m;
		}
		
	}

	int winner[n];
	bool end = 0;

	while(scanf("%d" , &num) == 1){
		for(int i = 0; i < n; i++){
			row[i][(place_x[i][num - 1])]++;
			column[i][(place_y[i][num - 1])]++;
			if(place_x[i][num - 1] == place_y[i][num - 1]){
				diagonal1[i]++;
			}
			if(place_x[i][num - 1] + place_y[i][num - 1] == m - 1){
				diagonal2[i]++;
			}
		}	

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(row[i][j] == m || column[i][j] == m || diagonal1[i] == m || diagonal2[i] == m){
					winner[i] = -1;
					end = 1;
				}
			}
		}

		if(end == 1){
			printf("%d", num);
			for(int i = 0; i < n; i++){
				if(winner[i] == -1){
					printf(" %s" , name[i]);
				}
			}
			printf("\n");
			break;
		}
	}

	return 0;

}