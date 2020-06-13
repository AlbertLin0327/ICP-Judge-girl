#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
	char word[1000];

	int index = 0;
	while((word[index] = getchar()) != EOF){
		if(word[index] == '.'){
			bool print = 1;
			for(int i = 0; i <= index; i++){
				if(isspace(word[i])){
					print = 1;
					continue;
				}
				if(print == 1){
					if((word[i] == 't' && word[i + 1] == 'h' && word[i + 2] == 'e' && !isalpha(word[i + 3])) || (word[i] == 'o' && word[i + 1] == 'f' && !isalpha(word[i + 2])) || (word[i] == 'a' && word[i + 1] == 't' && !isalpha(word[i + 2])) || (word[i] == 'a' && word[i + 1] == 'n' && word[i + 2] == 'd' && !isalpha(word[i + 3]))){
						print = 0;
						continue;
					}else if(isalpha(word[i])){
						printf("%c", (word[i] - 'a' + 'A'));
						print = 0;
					}
				}
			}
			printf("\n");
			word[0] = '\0';
			index = 0;
		}
		index++;
	}

	return 0;

}