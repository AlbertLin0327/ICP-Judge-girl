#include <stdio.h>

typedef unsigned long long Set;

void init(Set *set){
	*set = 0;
}

void add(Set *set, int i){
	
	//remember to add ull to assign "unsigned long long" to 1
	*set |= (1ull << i);
}

void has(Set set, int i){
	if((set >> i) & 1)
		printf("set has %d\n", i);
	else
		printf("set does not have %d\n", i);
}

Set setUnion(Set a, Set b){
	return (a | b);
}

Set setIntersect(Set a, Set b){
	return (a & b);
}

Set setDifference(Set a, Set b){
	return (a ^ b);
}
