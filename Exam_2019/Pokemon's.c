#include <stdio.h>
#include <stdbool.h>

int main(){
	int k;
	scanf("%d" , &k);

	int sum = 0;

	int highest = 0, second = 0;

	int wind = 0, fire = 0, water = 0;

	int cp;
	while(scanf("%d" , &cp) != EOF){
		if(cp % 3 == 0){
			wind++;
		}else if(cp % 3 == 1){
			fire++;
		}else if(cp % 3 == 2){
			water++;
		}

		if(cp > highest){
			second = highest;
			highest = cp;
		}else if(cp >= second){
			second = cp;

		}

		if(wind >= k && fire >= k && water >= k){
			sum += second;
			wind = 0; fire = 0; water = 0;
			highest = 0; second = 0;
		}
	}

	if(second != 0){
		sum += second;
	}else if(highest != 0 && second == 0){
		sum += highest;
	}

	printf("%d\n" , sum);

	return 0;

}