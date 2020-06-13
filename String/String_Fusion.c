#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define min(x , y) (x < y ? x : y)

int main(){
	char result[127] , data[127]; result[0] = '\0';
	
	while(scanf("%s" , data) != EOF){
		int length = strlen(result);
		int repeat = 0;

		if(length == 0){
			strcpy(result , data);
		}else{

			for(int i = 0; i < strlen(result) && i < strlen(data); i++){
				char temp[127];
				for(int j = 0; j<= i; j++){
					temp[j] = result[length + j - i - 1];
				}
				temp[i + 1] = '\0';
				char target[127];
				for(int j = 0; j <= i; j++){
					target[j] = data[j];
				}
				target[i + 1] = '\0';

				if(strcmp(temp , target) == 0){
					repeat = i + 1;
				}
			}
			for(int i = 0; i + repeat < strlen(data); i++){
				result[length + i] = data[repeat + i];
			}
			result[length + strlen(data) - repeat] = '\0';

		}

	}

	printf("%s\n", result);

	return 0;

}