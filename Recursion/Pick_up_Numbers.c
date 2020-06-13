#include <stdio.h>

int ways(int sum , int sLimit , int element , int eLimit , int index , int boundary , int num[]){
	int result = 0;
	
	if(sum <= sLimit && element >= eLimit && index == boundary)
		result += 1;
	
	if(index < boundary)
		result += (ways(sum + num[index] , sLimit , element + 1 , eLimit , index + 1 , boundary , num) + ways(sum , sLimit , element , eLimit , index + 1 , boundary , num));

	return result;

}

int main(){
	int k , N , M; scanf("%d%d%d" , &k , &N , &M);

	int num[N];
	for(int i = 0; i < N; i++){
		scanf("%d" , &num[i]);
	}

	printf("%d\n", ways(0 , M , 0 , k , 1 , N , num) + ways(num[0] , M , 1 , k , 1 , N , num));

	return 0;

}