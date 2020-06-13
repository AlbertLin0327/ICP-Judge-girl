#include <stdio.h>

int main(){

	int a , b , c , d , e , surface_Area , volume;

	scanf("%d\n%d\n%d\n%d\n%d" , &a , &b , &c , &d , &e);

	surface_Area = 2 * a * b + 2 * b * c + 2 * c * a + 8 * d * (a - 2 * e) + 8 * d * (b - 2 * e) + 8 * d * (c - 2 * e);
	volume = a * b * c - 2 * d * (a - 2 * e) * (b - 2 * e) - 2 * d * (b - 2 * e) * (c - 2 * e) - 2 * d * (c - 2 * e) * (a - 2 * e);
	
	printf("%d\n" , surface_Area);
	printf("%d\n" , volume);

	return 0;

}