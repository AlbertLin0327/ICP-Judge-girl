#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

typedef struct{
	int value , index;
}data;

typedef struct{
	int sum , index1 , index2;
}pair;

int data_cmp(const void* a, const void* b){
	return (((data*)a)->value > ((data*)b)->value ? 1 : ((data*)a)->value < ((data*)b)->value ? -1 : ((data*)a)->index > ((data*)b)->index ? 1 : -1);
}

int pair_cmp(const void* a, const void* b){
#ifdef INC
	return (((pair*)a)->sum > ((pair*)b)->sum ? 1 : ((pair*)a)->sum < ((pair*)b)->sum ? -1 : ((pair*)a)->index1 > ((pair*)b)->index1 ? 1 : -1);
#else
	return (((pair*)a)->sum < ((pair*)b)->sum ? 1 : ((pair*)a)->sum > ((pair*)b)->sum ? -1 : ((pair*)a)->index2 < ((pair*)b)->index2 ? 1 : -1);
#endif
}

 
void pairPrint(int numbers[], int n){
	data *d = malloc(n * sizeof(data));
	for(int i = 0; i < n; i++){
		d[i].value = numbers[i];
		d[i].index = i;
	}

	qsort(d , n , sizeof(data) , data_cmp);

	pair *p = malloc(n / 2 * sizeof(pair));
	for(int i = 0; i < n / 2; i++){
		p[i].sum = d[i].value + d[n - 1 - i].value;
		p[i].index1 = (d[i].index < d[n - 1 - i].index ? d[i].index : d[n - 1 - i].index);
		p[i].index2 = (d[i].index > d[n - 1 - i].index ? d[i].index : d[n - 1 - i].index);
	}

	qsort(p , n / 2 , sizeof(pair) , pair_cmp);

	for(int i = 0; i < n / 2; i++)
#ifdef INC
        printf("%d = numbers[%d] + numbers[%d]\n" , p[i].sum , p[i].index1 , p[i].index2);
#else
        printf("%d = numbers[%d] + numbers[%d]\n" , p[i].sum , p[i].index2 , p[i].index1);
#endif
 	
 	free(d); free(p);
        return;
}