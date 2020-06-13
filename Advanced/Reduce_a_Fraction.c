#include <stdio.h>

int gcd(int a , int b){
	if(b > a){
		a ^= b; b ^= a; a ^= b;
	}

	if(b == 0)
		return a;

	if(a % b == 0)
		return b;
	else
		return gcd(b , a % b);
}
int main(){
	int x , y;
	while(scanf("%d%d" , &x , &y) != EOF){
		int common = gcd(x , y);
		printf("%d / %d\n", x / common , y / common);
	}

	return 0;

}