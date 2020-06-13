#include <stdio.h>

int main(){
	int num;

	while(scanf("%d" , &num) != EOF){
		int count = 0;
		int max = 0;

		for(int i = 0; i < 32; i++){
			if((num >> i) & 1){
				count++;
				max = (max > count ? max : count);
			}else{
				count = 0;
			}
		}

		printf("%d\n" , max);

	}

	return 0;

}