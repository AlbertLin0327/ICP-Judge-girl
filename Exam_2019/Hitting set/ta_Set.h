#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
typedef struct set{
	uint64_t index;
}ta_Set;
 
void initializeSet(ta_Set* set, int numberOfElement);
bool intersect(ta_Set set1, ta_Set set2);
void addElement(ta_Set* set, int element);
void removeElement(ta_Set* set, int element);
void printSet(ta_Set set);