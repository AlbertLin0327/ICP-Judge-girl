#include <stdio.h>

int main(){

	int x , ans;

	scanf("%d" , &x);

	if(x <= 0) {

		ans = -100;

	}else {

		ans = 0;

		if(!(x % 3)) ans += 3;
		if(!(x % 5)) ans += 5;
		if(x >= 100 && x <=200) ans += 50; else ans -= 50;

	}
	

	printf("%d\n" , ans);

	return 0;
	
}