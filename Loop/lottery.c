#include <stdio.h>
#include <stdbool.h>

int main(){
	int special_one , special_two , special_three;
	int first_one , first_two , first_three;

	scanf("%d" , &special_one);
	scanf("%d" , &special_two);		
	scanf("%d" , &special_three);	
	scanf("%d" , &first_one);	
	scanf("%d" , &first_two);	
	scanf("%d" , &first_three);	
		

	int mine;

	int sum = 0;


	while(scanf("%d" , &mine) == 1){
		if( mine == special_one || mine == special_two || mine == special_three) {
			sum += 2000000;
			continue;
		}else if(mine == first_one || mine == first_two || mine == first_three){
			sum += 200000;
			continue;
		}else if( !((mine - first_one)%10000000)  || !((mine - first_two)%10000000) || !((mine - first_three)%10000000) ){
			sum += 40000;
			continue;
		}else if( !((mine - first_one)%1000000) || !((mine - first_two)%1000000) || !((mine - first_three)%1000000) ){
			sum += 10000;
			continue;
		}else if( !((mine - first_one)%100000) || !((mine - first_two)%100000) || !((mine - first_three)%100000) ){
			sum += 4000;
			continue;
		}else if( !((mine - first_one)%10000) || !((mine - first_two)%10000) || !((mine - first_three)%10000) ){
			sum += 1000;
			continue;
		}else if( !((mine - first_one)%1000) || !((mine - first_two)%1000) || !((mine - first_three)%1000) ){
			sum += 200;
			continue;
		}
		
	}
	
	printf("%d\n" , sum);

	return 0;
	
}
