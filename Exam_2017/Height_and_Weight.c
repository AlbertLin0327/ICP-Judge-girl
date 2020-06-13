#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[64];
	int height , weight;
	float BMI;
}Person;

Person data[100000];

int cmp(const void* a , const void* b){
	Person* pa = (Person *)a;
	Person* pb = (Person *)b;

	return pa->BMI > pb->BMI ? 1 : pa->BMI < pb->BMI ? -1 : pa->weight > pb->weight ? 1 : pa->weight < pb->weight ? -1 : pa->height > pb->height ? 1 : pa->height < pb->height ? -1 : strcmp(pa->name , pb->name); 
}

int main(){
	int N; scanf("%d" , &N);
	for(int i = 0; i < N; i++){
		scanf("%s %d %d" , data[i].name , &data[i].height , &data[i].weight);
		data[i].BMI = data[i].weight / (0.0001 * data[i].height * data[i].height);
	}

	qsort(data , N , sizeof(Person) , cmp);

	for(int i = 0; i < N; i++)
		printf("%s %d %d\n" , data[i].name , data[i].height , data[i].weight);
}