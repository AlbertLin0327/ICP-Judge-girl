#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool used[20] = {0}; 
int num[20] , path[20] , n;

int dfs(int index){
	if(index == n - 1){
		int left = 0 , right = 0;
		for(int i = 0; i < n / 2; i++){
			left += path[i] * (n / 2 - i);
			right += path[i + n / 2] * (i + 1);
		}

		if(right == left){
			for(int i = 0; i < n / 2; i++)
				printf("%d " , path[i]);
			printf("_^_");
			for(int i = n / 2; i < n - 1; i++)
				printf(" %d" , path[i]);
			printf("\n");

			return 1;
		}
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(!used[i]){
			path[index] = num[i] , used[i] = 1;
			if(dfs(index + 1))
				return 1;
			used[i] = 0;
		}
	}
	return 0;
}

int main(){
	while(scanf("%d" , &n) == 1){
		for(int i = 0; i < n; i++)
			scanf("%d" , &num[i]);

		memset(used , 0 , sizeof(used));

		if(!dfs(0))
			printf("N\n");
	}
	return 0;
}