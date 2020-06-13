#include <stdio.h>
#include <string.h>

int main(){
	char word[32];
	int count = 0;
	
	char prev = '\0' , next = '\0';
	while(scanf("%s" , word) != EOF){

		// char *strtok_r(char *str, const char *delim, char **saveptr)
		// char *strtok(char *str, const char *delim)

		char* safe = NULL;
		char* sub = strtok_r(word , "aeiou" , &safe);

		while(sub){
			for(int i = 0; i < strlen(sub); i++){
				if(prev == '\0')
					prev = sub[i];
				else if(next == '\0')
					next = sub[i];

				if(prev != '\0' && next != '\0'){
					count += (prev < next ? 1 : 0);
					prev = next;
					next = '\0';
				}

			}
			sub = strtok_r(NULL, "aeiou" , &safe);
		}
		
	}

	printf("%d\n" , count);

	return 0;

}