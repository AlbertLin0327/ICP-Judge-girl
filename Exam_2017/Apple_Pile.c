#include <stdio.h>

int main(){
	int a , b;
	scanf("%d%d" , &a , &b);

	int sum = 0;
	for(int i = a; i <= b; i++){
		sum += i;
	}
	printf("%d\n", sum);

	int surround = a + b + 2 * (b - a - 1);
	printf("%d\n", surround);

	return 0;

}