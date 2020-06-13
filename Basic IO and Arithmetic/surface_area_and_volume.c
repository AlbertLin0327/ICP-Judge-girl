#include <stdio.h>

int main(){

	int height , width , depth;

	scanf("%d\n%d\n%d" , &height , &width , &depth);
	printf("%d\n" , 2 * height * width + 2 * width * depth + 2 * depth * height);
	printf("%d\n" , height * width * depth);

	return 0;
	
}
