#include <stdio.h>
#include <math.h>

int main(){
	int count = 0 , max = 0;

	int num;
	scanf("%d" , &num);
	int lsd = num % 10;

	int k = 0;

	while(num / pow(10 , k - 1) > 10){
		k++;
	}
	
	count += k;
	max = count;

	while(scanf("%d" , &num) == 1){

		int i = 0;
		while(num / pow(10 , i - 1) > 10){
			i++;
		}

		int msd = num / pow(10 , i - 1);

		if(lsd == msd){
			count += i;
		}else{
			count = i;
		}

		if(count > max){
			max = count;
		}

		lsd = num % 10;

	}

	printf("%d\n" , max);

	return 0;

}