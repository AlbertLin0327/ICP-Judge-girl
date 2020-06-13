#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h> 

/* 
void* memcpy (void* destination , const void* source , size_t num);
	Copy byte by byte, but might has malperformance while destination and source overlap.
	Cuz memcpy works on the same string.

void* memmove (void* destination , const void* source , size_t num);
	Get a copy of source to buffer, so you wouldn't come across the problem as in memcpy.

Ex: char s[20] = "alightechs";;
	
	memmove(s+5,s,7);  
	memcpy(s+5,s,7); 

	o/p for memmove is alighalighte  
	o/p for memmove is alighalighal 

*/

void insert(char* result , int k , int block , char a){
	memmove(result + k + 1 , result + k , block);
	result[k] = a;
}

void delete(char* result , int k , int block){
	memcpy(result + k , result + k + 1 , block);
}

int main(){
	char result[20000]; result[0] = '\0';
	int index = 0;

	char instruction[2][30];
	while(scanf("%s%s" , instruction[0] , instruction[1]) != EOF){
		int k = 0;
		if(isdigit(instruction[1][0])){
			k = atoi(instruction[1]) - 1;
		}else if(strcmp(instruction[1] , "left") == 0){
			k = 0;
		}else if(strcmp(instruction[1] , "right") == 0){
			k = strlen(result);
			k -= ((strcmp(instruction[0] , "insert") == 0) ? 0 : 1);
		}

		if(strcmp(instruction[0] , "insert") == 0){
			char word;
			scanf(" %c" , &word);
			insert(result , k , strlen(result) - k + 1 , word);
		}else{
			delete(result , k , strlen(result) - k);
		}
		
	}

	//printf("%s\n", result);

	char ans[20000]; ans[0] = '\0';
	int max = 0 , current = 1;

	for(int i = 1; i <= strlen(result); i++){
		if(result[i] == result[i - 1]){
			current++;
		}else{
			if(current > max){
				max = current;
				ans[0] = result[i - 1];
				memset(ans + 1 , '\0' , strlen(ans));	
			}else if(current == max){
				ans[strlen(ans)] = result[i - 1]; 
				ans[strlen(ans)] = '\0';
			}
			current = 1;
		}
	}

	for(int i = 0; i < strlen(ans); i++)
		printf("%c ", ans[i]);
	printf("%d\n", max);

	return 0;

}