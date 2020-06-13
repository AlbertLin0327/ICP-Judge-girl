#include <stdio.h>
#include <stdlib.h>

void bubble(int *num , int a , int b){
	int temp = *(num + b);
	for(int i = b; i > a; i--){
		*(num + i) = *(num + i - 1);
	}
	*(num + a) = temp;
}

void recover(int *num , int a , int b){
	int temp = *(num + a);
	for(int i = a; i < b; i++){
		*(num + i) = *(num + i + 1);
	}
	*(num + b) = temp;
}		

int compare(const void *a , const void *b){
	return (*(int*)a - *(int*)b);
}

void permute(int num[] , int current , int N){
	if(current == N){

		for(int j = 0; j < N - 1; j++){
			printf("%d ", num[j]);
		}
		printf("%d\n", num[N - 1]);

		return;
	}else{
		for(int i = current; i < N; i++){

			bubble(num , current , i);
			permute(num , current + 1 , N);
			recover(num , current , i);

		}
	}

}

int main(){
	int N; scanf("%d" , &N);

	int num[N];
	for(int i = 0; i < N; i++){
		scanf("%d" , &num[i]);
	}

	qsort(num , N , sizeof(int) , compare);

	permute(num , 0 , N);

	return 0;

}
