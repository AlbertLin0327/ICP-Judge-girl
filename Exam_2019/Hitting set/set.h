#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
typedef struct set{
	uint64_t index;
}Set;
 
void initializeSet(Set* set, int numberOfElement);
bool intersect(Set set1, Set set2);
void addElement(Set* set, int element);
void removeElement(Set* set, int element);
void printSet(Set set);