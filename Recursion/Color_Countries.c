#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool paint(int country[] , int adjacent[][2] , int index , int N , int P , int C){
	bool used[C];
	if(index == N){
		return 1;
	}

	for(int i = 0; i < C; i++)
		used[i] = 0;

	for(int i = 0; i < P; i++){
		if(adjacent[i][1] == index){
			int nearby = adjacent[i][0];
			used[country[nearby]] = 1;
		}
	}

	bool result = 0;

	for(int i = 0; i < C; i++){
		if(used[i] == 0){
			country[index] = i;
			result += paint(country , adjacent , index + 1 , N , P , C);

			// when you use array in recursion, be sure to break right when your target is complete.
			//Otherwise you will continue to change the value of it.
			if(result)
				break;
		}
	}
	return result;
}

int main(){
	int N , C , P; scanf("%d %d %d" , &N , &C , &P);
	int country[N];

	for(int i = 0; i < N; i++)
		country[i] = -1;

	int adjacent[P][2];

	for(int i = 0; i < P; i++){
		int a , b; scanf("%d %d" , &a , &b);
		if(a > b)
			a ^= b ^= a ^= b;
		adjacent[i][0] = a;
		adjacent[i][1] = b;
	}

	if(!paint(country , adjacent , 0 , N , P , C)){
		printf("no solution.\n");
	}else{
		for(int i = 0; i < N; i++)
			printf("%d\n", country[i] + 1);
	}

	return 0;

}