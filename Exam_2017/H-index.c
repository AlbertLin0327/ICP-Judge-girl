#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int citation;
	char author[20];
}Paper;

Paper paper[20005];

int cmp(const void* a , const void* b){
	return strcmp(((Paper*)a)->author , ((Paper*)b)->author) != 0 ? strcmp(((Paper*)a)->author , ((Paper*)b)->author) : ((Paper*)b)->citation - ((Paper*)a)->citation;
}

int main(){

	int counter = 0;
	while(scanf("%s %d" , paper[counter].author , &(paper[counter].citation)) != EOF)
		counter++;
	
	qsort(paper , counter , sizeof(Paper) , cmp);

	char prev[20]; int i = 0;
	while(i < counter){
		int total = 0 , index[20005];
		strcpy(prev , paper[i].author);

		while(strcmp(prev , paper[i + total].author) == 0){
			index[total] = paper[i + total].citation; total++;
		}
		int max = 0;
		for(int j = 0; j < total; j++){
			if(index[j] >= j + 1)
				max = j + 1;
			else
				break;
		}
		printf("%s %d\n", prev , max);
		i += total;
	}
}