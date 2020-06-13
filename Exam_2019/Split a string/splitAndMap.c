#include <string.h>

void splitAndMap(char*** ptr, char* str){
	int num[10] = {0};
	int ptr_index[10] = {0};
	char* sub = strtok(str , "*");
	int min , index = 0;

	while(sub){

		min = *num; index = 0;
		for(int i = 0; ptr[i] != NULL; i++){
			if(min > num[i]){
				min = num[i]; 
				index = i;
			}
		}

		ptr[index][ptr_index[index]] = sub;
		num[index] += strlen(sub);
		ptr_index[index]++;

		sub = strtok(NULL , "*");
		
	}

	for(int i = 0; ptr[i] != NULL; i++)
		ptr[index][num[index] + 1] = NULL;
	

}
