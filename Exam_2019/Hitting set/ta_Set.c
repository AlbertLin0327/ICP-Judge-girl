#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "ta_Set.h"

void initializeSet(ta_Set* set, int numberOfElement){
	set->index = 0;
}

bool intersect(ta_Set set1, ta_Set set2){
	return ((set1.index & set2.index) != 0);
}

void addElement(ta_Set* set, int element){
	set->index |= ((uint64_t)1 << (element - 1));
}

void removeElement(ta_Set* set, int element){
	set->index ^= ((uint64_t)1 << (element - 1));
}

void printSet(ta_Set set){
	for(int i = 0; i < 64; i++)
		if(set.index & (uint64_t)1 << i)
			printf("%d " , i + 1);
	printf("\n");	
}