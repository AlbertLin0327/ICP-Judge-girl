#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(){
	char str[100];

	while(fgets(str , 100 , stdin)){
		int front = 0;
		for(; front < strlen(str); front++){
			if(!(isspace(str[front]))){
				break;
			}
		}

		int backward = strlen(str) - 1;
		for(; backward >= 0; backward--){
			if(!(isspace(str[backward]))){
				break;
			}
		}

		for(int i = front; i <= backward; i++){
			printf("%c", str[i]);
		}
		printf("\n");

	}

	return 0;
}