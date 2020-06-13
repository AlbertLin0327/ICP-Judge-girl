#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mstTA.h"

bool best[45];
int instruction[45][3];

int cmp(const void *a, const void *b){
	return *((int *)a + 2) - *((int *)b + 2);
}

void brute(MSTTA *mst , int index , int n , int m , int added){
	if(added == n - 1)
		return;
	
	if(!hasPathTA(mst , instruction[index][0] , instruction[index][1])){
		addRoadTA(mst , instruction[index][0] , instruction[index][1] , instruction[index][2]);	
		best[index] = 1; brute(mst , index + 1 , n , m , added + 1);
		return;
	}

	brute(mst , index + 1 , n , m , added);
	return;
}	

int main(){
	for (int i = 0; i < 45; i++){
		best[i] = 0;
	}

	int n , m; scanf("%d%d" , &n , &m);
	MSTTA* mst = malloc(sizeof(MSTTA)); 
	initTA(mst , n);

	for(int i = 0; i < m; i++){
		scanf("%d%d%d" , &instruction[i][0] , &instruction[i][1] , &instruction[i][2]);
	}

	qsort(instruction , m , sizeof(instruction[0]) , cmp);
	brute(mst , 0 , n , m , 0);

#ifdef ADD
	for(int i = 0; i < m; i++)
		if(best[i])
#else
	for(int i = m - 1; i >= 0; i--)
		if(!best[i])
#endif
			printf("%d %d %d\n" , instruction[i][0] , instruction[i][1] , instruction[i][2]);
		return 0;
}