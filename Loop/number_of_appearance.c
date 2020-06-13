#include <stdio.h>

int main(){

	int n = 0;
	char num[3] , target[8];
	scanf("%s %s" , num , target);

	for(int i = 0; i < 6; i++){
		if(num[0] == target[i] && num[1] == target[i + 1]) n++;
	}

	printf("%d\n" , n);

	return 0;

}