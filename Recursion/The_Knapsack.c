#include <stdio.h>
#define max(x , y) (x > y ? x : y)

int pack(int W , int n , int w[] , int v[]){
	if(n < 0 || W < 0){
		return 0;
	} 

	if(W >= w[n]){
		return max(pack(W , n - 1 , w , v) , (pack(W - w[n] , n - 1 , w , v) + v[n]));
	}else if(W > 0){
		return pack(W , n - 1 , w , v);
	}else{
		return 0;
	}
	
}

int main(){
	int n , W; scanf("%d%d" , &n , &W);

	int w[n] , v[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d" , &w[i] , &v[i]);
	}

	int max = pack(W , n - 1 , w , v);

	printf("%d\n", max);

	return 0;
	
}