#include <stdio.h>

int sum_of_square(n){
	if(n > 1){
		return (n * n + sum_of_square(n - 1));
	}else if(n == 1){
		return 1;
	}
}

int main(){
	int n;
	scanf("%d" , &n);

	int result = sum_of_square(n);
	printf("%d\n", result);

	return 0;

}