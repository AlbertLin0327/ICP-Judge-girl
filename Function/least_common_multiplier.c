#include <stdio.h>
#define min(x , y) (x < y? x: y)
#define max(x , y) (x > y? x: y)


//
int gcd_f(int a , int b){
	if(!(max(a , b) % min(a , b)))
		return min(a , b);
	else return gcd_f(min(a , b) , max(a , b) % min(a , b));
}

int main(){
	int num;
	scanf("%d" , &num);
	int lcm = num;
	int gcd = gcd_f(num , 1);

	while(scanf("%d" , &num) == 1){
		if(!(lcm % num))
			continue;
		gcd = gcd_f(num , lcm);
		lcm = lcm * num / gcd;
	}

	printf("%d\n" , lcm);

	return 0;

}
