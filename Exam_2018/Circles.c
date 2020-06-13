#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a , const void* b){
	return *(int *)a - *(int *)b;
}

int main(){
	int n; scanf("%d" , &n);

	static int P[1000100] , x , y;
	for(int i = 0; i < n; i++){
		scanf("%d %d" , &x , &y);
		P[i] = x * x + y * y;
	}

	qsort(P , n , sizeof(int) , cmp);

	int max = 0 , max_count = 0 , count = 1 , prev = P[0];
	for(int i = 1; i < n; i++){
		
		if(P[i] == prev)
			count++;
		else
			count = 1 , prev = P[i];

		if(count >= max_count)
			max = P[i] , max_count = count;
			
	}
	printf("%d\n", max);
}