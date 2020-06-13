#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int arr[16385];

void balance(int start , int end){
	if(end - start + 1 < 3) 
		return;

	for(int i = start; i <= end; i++){
        int64_t left_sum = 0 , right_sum = 0;
 
        for(int j = start; j < i; j++)
            left_sum += (long long int)arr[j] * (i - j);
        for(int j = i + 1; j <= end; j++)
            right_sum += (long long int)arr[j] * (j - i);
 
        if(left_sum == right_sum){
            balance(start , i - 1);
            printf("%d\n", i);
            balance(i + 1 , end);
            return;
        }
    }
    return;
}

int main(){ 
	int n; scanf("%d" , &n);
	for(int i = 0; i < n; i++)
		scanf("%d" , &arr[i]);
	balance(0 , n - 1);
}