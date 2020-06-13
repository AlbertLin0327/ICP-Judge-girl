#include <stdio.h>

int main(){

	int n , a = 0 , b = 0 , c = 0;
	scanf("%d" , &n);

	while(n--){

		int num;
		scanf("%d" , &num);

		switch(num % 3){

			case 0:
				a++;
				break;

			case 1:
				b++;
				break;

			case 2:
				c++;
				break;
		}

	}

	printf("%d %d %d\n" , a , b , c);

	return 0;

}