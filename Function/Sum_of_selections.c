#include <stdio.h>

int Count(int a , int b){

	if(b == 0){
		return 1;
	}

	int ans = 1;

	for(int i = a - b + 1; i <= a; i++){
		ans *= i;
	}
	for(int i = 1; i <= b; i++){
		ans /= i;
	}

	return ans + Count(a , b - 1);
}

int main(){
	int m , n;
	scanf("%d%d" , &m , &n);

	printf("%d\n" , Count(m , n));

	return 0;

}