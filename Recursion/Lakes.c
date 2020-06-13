#include <stdio.h>
#include <stdbool.h>

int compare(const void* a , const void* b){
	return *(int*)b - *(int*)a;
}

int lake(int r , int c , int N , int M , int map[410][410] , int dr[] , int dc[]){
	
	int result = 0;
	
	for(int i = 0; i < 4; i++){
		if(r + dr[i] >= 0 && r + dr[i] < N && c + dc[i] >= 0 && c + dc[i] < M && map[r + dr[i]][c + dc[i]] == 1){
			map[r + dr[i]][c + dc[i]] = 0;
			result += (1 + lake(r + dr[i] , c + dc[i] , N , M , map , dr , dc));
		}
	}
	
	return result;

}

int main(){
	int N , M; scanf("%d%d" , &N , &M);

	int dr[] = {0 , 0 , 1 , -1};
	int dc[] = {1 , -1 , 0 , 0};

	int map[410][410];

	int sum = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d" , &map[i][j]);
		}
	}
		

	int size[N * M / 2 + 10] , num = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map[i][j] == 1){
				map[i][j] = 0;
				size[num] = lake(i , j , N , M , map , dr , dc) + 1;
				num++;
			}
		}
	}

	qsort(size , num , sizeof(int) , compare);

	for(int i = 0; i < num; i++)
		printf("%d\n", size[i]);
}