#include <stdio.h>

int main(){

	int s , f , t , chicken , rabbit , crab;

	scanf("%d\t%d\t%d" , &s , &f , &t);

	crab = s - t;
	rabbit = f / 2 - t - 4 * crab;
	chicken = t - rabbit;

	printf("%d\n%d\n%d\n" , chicken , rabbit , crab);

	return 0;

}