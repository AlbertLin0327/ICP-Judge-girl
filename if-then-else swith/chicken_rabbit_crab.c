#include <stdio.h>

int main(){

	int s , f , t , chicken , rabbit , crab;

	scanf("%d\t%d\t%d" , &s , &f , &t);

	crab = s - t;
	rabbit = f / 2 - t - 4 * crab;
	chicken = t - rabbit;

	if(chicken >= 0 && rabbit >= 0 && crab >= 0 && s == chicken + rabbit + crab && f == 2 * chicken + 4 * rabbit + 8 * crab && t == chicken + rabbit) {
		printf("%d\n%d\n%d\n" , chicken , rabbit , crab);
	}else{
		printf("0\n");
	}

	return 0;

}