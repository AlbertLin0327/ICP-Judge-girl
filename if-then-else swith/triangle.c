#include <stdio.h>

int main(){

	int n;
	scanf("%d" , &n);

	while(n--){

		int a , b , c , d , e , f , line_one_square , line_two_square , line_three_square;
		scanf("%d %d %d %d %d %d" , &a , &b , &c , &d , &e , &f);

		line_one_square = (c - a) * (c - a) + (d - b) * (d - b);
		line_two_square = (e- c) * (e - c) + (f - d) * (f - d);
		line_three_square = (a- e) * (a- e) + (b - f) * (b - f);

		if(line_one_square == line_two_square || line_two_square == line_three_square || line_three_square == line_one_square){
			printf("isosceles\n");
		}else {

			if(line_one_square + line_two_square == line_three_square || line_two_square + line_three_square == line_one_square || line_three_square + line_one_square == line_two_square){
				printf("right\n");
			}else if(line_one_square + line_two_square > line_three_square && line_two_square + line_three_square > line_one_square && line_three_square + line_one_square > line_two_square){
				printf("acute\n");
			}else{
				printf("obtuse\n");
			}

		}

	}

	return 0;

}