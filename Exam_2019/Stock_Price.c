#include <stdio.h>
#include <stdbool.h>

int main(){
	int first , second;
	if(scanf("%d%d" , &first , &second) != 2){
		printf("0\n");
		return 0;
	}

	bool up = second > first;

	int current , prev = second , index = 2;
	int currLen = 2 , currIndex = 1;
	int prevLen = 0 , prevIndex;
	int maxLen = 0 , maxLeft = 1 , maxIndex = 1;

	while(scanf("%d" , &current) != EOF){
		index++;

		if((up == 1 && current > prev) || (up == 0 && current < prev)){
			currLen++;
		}else{
			up = !up;
			prevLen = currLen;
			currLen = 2;
			prevIndex = currIndex;
			currIndex = index - 1;
		}

		if(currLen + prevLen - 1 > maxLen || (currLen + prevLen - 1 == maxLen && prevLen > maxLeft)){
			maxLen = currLen + prevLen - 1;
			maxIndex = prevIndex;
			maxLeft = prevLen;
		}
		prev = current;
	}

	if(prevLen == 0){
		printf("0\n");
	}else{
		printf("%d %d\n" , maxLen , maxIndex);
	}

	return 0;


}