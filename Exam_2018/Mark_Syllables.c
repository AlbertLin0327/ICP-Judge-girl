#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isvowel(int c){
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(){
	char k[10005] , ka[10005] , kb[10005] , kc[10005]; 

	int a , b;
	while(scanf("%s %d %d" , k , &a , &b) == 3){
		int count = 0;
		for(int i = 0; i < strlen(k); i++){
			ka[i] = (count == a ? k[i] : '+');
			kb[i] = (count == b ? k[i] : '+');
			kc[i] = (count != a && count != b ? k[i] : '+');

			if(isvowel(k[i]))
				count++;
		}
		ka[strlen(k)] = kb[strlen(k)] = kc[strlen(k)] = '\0';
		printf("%s\n%s\n%s\n", ka , kb , kc);
	}

}