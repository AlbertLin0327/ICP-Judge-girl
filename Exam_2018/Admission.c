#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int score[5];
	int total;
	int index;
}Score;

int cmp(const void* a, const void* b){
	Score* pa = (Score *)a;
	Score* pb = (Score *)b;
	return (pa->total < pb->total ? 1 : pa->total > pb->total ? -1 : pa->score[2] < pb->score[2] ? 1 : pa->score[2] > pb->score[2] ? -1 :\
		pa->score[1] < pb->score[1] ? 1 : pa->score[1] > pb->score[1] ? -1 : pa->score[3] < pb->score[3] ? 1 : pa->score[3] > pb->score[3] ? -1 :\
		pa->score[0] < pb->score[0] ? 1 : pa->score[0] > pb->score[0] ? -1 : pa->score[4] < pb->score[4] ? 1 : pa->score[4] > pb->score[4] ? -1 : pa->index - pb->index);
}

int main(){
	int m , n; scanf("%d%d" , &m , &n);

	Score data[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d%d%d" , &data[i].index , &data[i].score[0] , &data[i].score[1] , &data[i].score[2] , &data[i].score[3] , &data[i].score[4]);
		data[i].total = data[i].score[0] + data[i].score[1] + data[i].score[2] + data[i].score[3] + data[i].score[4]; 
	}

	qsort(data , n , sizeof(Score) , cmp);

	for(int i = 0; i < m; i++)
		printf("%d\n" , data[i].index);
	
	for(int i = m; i < n; i++){
		if(data[i].total == data[m - 1].total && memcmp(data[i].score , data[m - 1].score , sizeof(data[i].score)) == 0)
			printf("%d\n" , data[i].index);
		else
			return 0;
	}
}