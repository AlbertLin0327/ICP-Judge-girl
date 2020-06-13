#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "set.h"

void initializeSet(Set* set, int numberOfElement){
	set->index = 0;
}

bool intersect(Set set1, Set set2){
	return ((set1.index & set2.index) != 0);
}

void addElement(Set* set, int element){
	set->index |= ((uint64_t)1 << (element - 1));
}

void removeElement(Set* set, int element){
	set->index ^= ((uint64_t)1 << (element - 1));
}

void printSet(Set set){
	for(int i = 0; i < 64; i++)
		if(set.index & (uint64_t)1 << i)
			printf("%d " , i + 1);
	printf("\n");	
}