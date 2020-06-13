#include <stdio.h>
#include <stdbool.h>

bool palindrome(int arr[100] , int a , int b){

	int bound = (b - a) / 2;
	bool same = 1;

	for(int i = 0; i <= bound; i++){
		if(arr[a + i] != arr[b - i]){
			same = 0;
		}
	}

	return same;
}

int main(){
	int arr[100];
	int length = 0;

	while(scanf("%d" , &arr[length]) != EOF){
		length++;
	}

	int start, maxStart = 0;
	int final , maxFinal = 0;

	for(int i = length; i > 0; i--){
		for(int j = 0; j < length; j++){
			if(palindrome(arr , j , i)){
				final = i;
				for(int k = 0; k < j; k++){
					if(palindrome(arr , k , j - 1)){
						start = k;
						if(final - start > maxFinal - maxStart){
							maxStart = start;
							maxFinal = final;
						}
					}
				}
			}

		}
	}

	for(int i = maxStart; i < maxFinal; i++){
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[maxFinal]);
}