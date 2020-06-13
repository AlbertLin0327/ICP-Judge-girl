#include <stdio.h>

int main(){
	const int bill[] = {1000 , 500 , 100 , 50 , 10 , 5, 1};

	int money;
	while(scanf("%d" , &money) != EOF){
		int num[7] = {0};

		for(int i = 0; i < 7; i++){
			printf("%d%c" , money / bill[i] , (i == 6 ? '\n' : ' ')) ;
			money %= bill[i];
		}
	}
}