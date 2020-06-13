#include <stdio.h>

int main(){

	//c Language doesn't provide string type
	char number[3];

	scanf("%s" , number);
	printf("%c\n%c\n%c\n" , number[0] , number[1] , number[2]);

	return 0;

}