#include <stdlib.h>
#include <stdbool.h>

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
	int index = 0 , block = 0;

	while(ptrArray[index] != NULL || ptrArray[index + 1] != NULL){\

		if(ptrArray[index] == NULL){
			block++; index++;
			continue;
		}

		bool repeat = 0;
		for(int i = index - 1; i >= 0 && ptrArray[i] != NULL; i--){
			if(ptrArray[index] == ptrArray[i]){
				repeat = 1; break;
			}
		}
		
		if(!repeat){
			answer[block] += (*ptrArray[index]);
		}

		index++;
		
	}


	*numberOfBlocks = (block + 1);

}