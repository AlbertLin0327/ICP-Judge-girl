#include <stdio.h>
#include <ctype.h>

int main(){
	char s;

	int digits = 0 , letters = 0 , vowels = 0 , consonants = 0;

	while(scanf("%c" , &s) == 1){
		
		if(isdigit(s)){
			digits++;
		}

		if(isalpha(s)){
			letters++;
		}

		if(s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U' || s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
			vowels++;
		}

	}
	
	consonants = letters - vowels;

	printf("%d %d %d %d\n", digits , letters , vowels , consonants);

	return 0;
}