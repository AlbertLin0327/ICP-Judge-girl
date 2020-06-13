#include <stdio.h>
#include <ctype.h>
#define max(x , y) (x > y ? x : y)

int main(){
	char s;

	int result[26] = {0};

	while(scanf("%c" , &s) == 1){
		if(isalpha(s)){
			s = toupper(s);
			result[s - 65]++;
		}
	}

	for(int i = 0; i < 26; i++){
		printf("%d\n" , result[i]);
	}

	return 0;

}