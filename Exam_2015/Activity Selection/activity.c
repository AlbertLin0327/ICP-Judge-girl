#include <stdio.h>
#include <stdlib.h>
#include "activity.h"
#define max(x , y) (x > y ? x : y)
#define min(x , y) (x < y ? x : y)

int cmp(const void* a , const void* b){
	return (((Activity *)a)->end - ((Activity *)b)->end);
}

int select(Activity activities[] , int n){
	qsort(activities , n , sizeof(Activity) , cmp);
	int total_event = 0 , prev = 0;

	// Greedy Algorithm
	for(int i = 0; i < n; i++){
		if(activities[i].start >= prev){
			#ifdef PRINT
					printf("%d %d\n", activities[i].start , activities[i].end);
			#endif
			total_event++ , prev = activities[i].end;
		}
	}

	return total_event;
}