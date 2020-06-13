#include <stdio.h>

int main(){
	int a , b , c , d , e , f , perimeter , area;

	scanf("%d\n%d\n%d\n%d\n%d\n%d" , &a , &b , &c , &d , &e , &f);

	perimeter = 2 * (a + b + c + d + e + f);
	area = a * (b + d + f) + c * (d + f) + e * f;

	printf("%d\n%d\n" , perimeter , area);

	return 0;

}