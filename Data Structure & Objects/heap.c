#include <limits.h>
#include "heap.h"
 
void initialize(struct Heap *heap){
	heap->num = 0;
}

int removeMin(struct Heap *heap){
	int index , min = INT_MAX;
	for(int i = 0; i < heap->num; i++){
		if(heap->ary[i] < min){
			min = heap->ary[i]; index = i;
		}
	}
	memcpy(heap->ary + index , heap->ary + index + 1 , (heap->num - index) * sizeof(int));
	heap->num--;
	return min;
}

void add(struct Heap *heap, int i){
	heap->ary[heap->num] = i;
	heap->num++;
}

int isFull(struct Heap *heap){
	if(heap->num == 100)
		return 1;
	return 0;
}
int isEmpty(struct Heap *heap){
	if(heap->num == 0)
		return 1;
	return 0;
}
