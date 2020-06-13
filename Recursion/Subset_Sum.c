#include <stdio.h>

int sum(int n , int set[] , int k  , int bound){
	if(k > bound){
		return 0;
	}

	if(n == 0){
		return 1;
	}else if(n < 0){
		return 0;
	}else{
		return sum(n - set[k] , set , k + 1 , bound) + sum(n , set , k + 1 , bound);
	}
}

int main(){
	int n; scanf("%d" , &n);

	int set[n];
	for(int i = 0; i < n; i++){
		scanf("%d" , &set[i]);
	}

	int num;
	while(scanf("%d" , &num) != EOF){
		printf("%d\n", sum(num , set , 0 , n));
	}

}