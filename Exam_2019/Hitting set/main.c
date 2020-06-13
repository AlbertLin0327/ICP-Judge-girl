#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ta_set.h"

int best[100] , solve[100];
int best_index , solve_index;

bool intersect_all(ta_Set* set_series , int n , ta_Set solution_set){
	for(int i = 0; i < n; i++)
		if(!intersect(set_series[i] , solution_set))
			return false;
	return true;
}

void check(ta_Set* set_series , int n , ta_Set solution_set , int bound , ta_Set* best_set , int index , int element[]){
	if(intersect_all(set_series , n , solution_set)){
		if(best_index == 0 || solve_index < best_index){
			memcpy(best , solve , sizeof(int) * solve_index);
			best_index = solve_index;
			*best_set = solution_set;
		}else if(solve_index == best_index){
#ifdef LARGESTDICTIONARYORDER
			for(int i = 0; i < solve_index; i++)
				if(best[index] > solve[i])
					return;
#elif defined SMALLESTDICTIONARYORDER
			for(int i = 0; i < solve_index; i++)
				if(best[index] < solve[i])
					return;
#endif
			memcpy(best , solve , sizeof(int) * solve_index);
			best_index = solve_index;
			*best_set = solution_set;
		}
		return;
	}

	if(index == bound + 1)
		return;

	for(int i = 0; i < n; i++)
		if(element[i] < index)
			if(!intersect(set_series[i], solution_set))
				return;

	addElement(&solution_set , index); solve[solve_index] = index; solve_index++;
	check(set_series , n , solution_set , bound , best_set , index + 1 , element);
	removeElement(&solution_set , index); solve_index--;
	check(set_series , n , solution_set , bound , best_set , index + 1 , element);

	return;
}


int main(){
	int bound , n; 
	scanf("%d%d" , &bound , &n);

	int element[n];
	ta_Set set_series[n];

	for(int i = 0; i < n; i++){
		int m; scanf("%d" , &m);
		element[i] = 0;
		initializeSet(&set_series[i] , m);
		while(m--){
			int num; scanf("%d" , &num);
			element[i] = (element[i] < num ? num : element[i]);
			addElement(&set_series[i] , num);
		}
	}

	ta_Set solution_set , best_set;
	best_index = solve_index = 0;
	initializeSet(&solution_set , bound);
	initializeSet(&best_set , bound);
	check(set_series , n , solution_set , bound , &best_set , 1 , element);
	printSet(best_set);
}