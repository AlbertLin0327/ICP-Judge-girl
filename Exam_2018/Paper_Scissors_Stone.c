#include <stdio.h>
#include <stdbool.h>

int main(){
	int X , a , b , c;
	scanf("%d%d%d%d" , &X , &a , &b , &c);
	int Y , d , e , f;
	scanf("%d%d%d%d" , &Y , &d , &e , &f);
	
	int n;
	scanf("%d" , &n);

	

	while(n--){
		int winner;
		bool end = 0;
		int pairs = 0;

		while(end == 0){
			pairs++;
			if((X % 3 == 2 && Y % 3 == 1) || (X % 3 == 1 && Y % 3 == 0) || (X % 3 == 0 && Y % 3 == 2)){
				winner = 0;
				end = 1;
			}else if((Y % 3 == 2 && X % 3 == 1) || (Y % 3 == 1 && X % 3 == 0) || (Y % 3 == 0 && X % 3 == 2)){
				winner = 1;
				end = 1;
			}

			X = (a * X + b) % c;
			Y = (d * Y + e) % f;
		}

		printf("%d %d\n", winner , pairs);
		
	}

	return 0;

}