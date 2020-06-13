#include <stdio.h>
#include "nextMove.h"
#define MAXN 100

int main(){

	int visited[MAXN][MAXN] = {0};
	int map[MAXN][MAXN] = {0};
	int move[8][2] = {{-2 , 1} , {-1 , 2} , {1 , 2} , {2 , 1} , {2 , -1} , {1 , -2} , {-1 , -2} , {-2 , -1}};

	int n , m;
    scanf("%d%d" , &n , &m);

	int knight[m][2];
	int step[m];
    
    for(int i = 0; i < m; i++){
        scanf("%d%d" , &knight[i][0] , &knight[i][1]);
        visited[knight[i][0]][knight[i][1]] = 1;
        map[knight[i][0]][knight[i][1]] = 10000 * (i + 1);
        step[i] = 0;
    }
    
    int i = 0 , end = 0;
    while(1){
    	int result;
    	if((result = nextMove(knight[i % m][0] , knight[i % m][1] , n , visited)) != -1){
    		step[i % m]++;
    		knight[i % m][0] += move[result][0];
    		knight[i % m][1] += move[result][1];
    		visited[knight[i % m][0]][knight[i % m][1]] = 1;
        	map[knight[i % m][0]][knight[i % m][1]] = 10000 * (i % m + 1) + step[i % m];
        	end = 0;
    	}else{
    		end++;
    	}

    	i++;

    	if(end > m){
    		break;
    	}
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n - 1; j++){
			printf("%d " , map[i][j]);
		}printf("%d\n" , map[i][n - 1]);
    }
		


    return 0;

}