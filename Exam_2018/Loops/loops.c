#include <stdbool.h>

void loops(int N, int *A, int *B[], int ans[4]){
	bool visited[N];
	for(int i = 0; i < N; i++)
		visited[i] = 0;

	int maxLen = 0 , maxVal = A[0] , minLen = 1000000 , minVal = A[0];

	for(int i = 0; i < N; i++){
		if(visited[i] == 0){
			int currLen = 0 , currMax = A[i] , currMin = A[i];
			int index = i;
			do{
				visited[index] = 1;
				currMax = (currMax > *B[index] ? currMax : *B[index]);
				currMin = (currMin < *B[index] ? currMin : *B[index]);
				currLen++;
				index = (B[index] - A);
			}while(visited[index] == 0);

			if(minLen > currLen){
				minLen = currLen;
				minVal = currMin;
			}
			if(maxLen < currLen){
				maxLen = currLen;
				maxVal = currMax;
			}
			if(minLen == currLen){
				minVal = (minVal < currMin ? minVal : currMin);
			}
			if(maxLen == currLen){
				maxVal = (maxVal > currMax ? maxVal : currMax);
			}


		}
	}

	ans[0] = maxLen; ans[1] = minLen; ans[2] = maxVal; ans[3] = minVal;

	return;

}