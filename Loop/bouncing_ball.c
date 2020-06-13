#include <stdio.h>

int main(){
	int X , Y , x1 , y1 , x2 , y2 , dx1 , dy1 , dx2 , dy2 , second;
	scanf("%d%d%d%d%d%d%d%d%d%d%d" , &X , &Y , &x1 , &y1 , &x2 , &y2 , &dx1 , &dy1 , &dx2 , &dy2 , &second);

	while(second--){

		if(x1 == x2 && y1 == y2){
			if(dx1 * dx2 < 0) {
				dx1 *= -1;
				dx2 *= -1;
			}
			if(dy1 * dy2 < 0) {
				dy1 *= -1;
				dy2 *= -1;
			}

		}

		if(x1 == X || x1 == 1) dx1 *= -1;
		if(y1 == Y || y1 == 1) dy1 *= -1;
		
		if(x2 == X || x2 == 1) dx2 *= -1;
		if(y2 == Y || y2 == 1) dy2 *= -1;

		x1 += dx1;
		y1 += dy1;
		x2 += dx2;
		y2 += dy2;

	}

	printf("%d\n%d\n%d\n%d\n", x1 , y1 , x2 , y2);

	return 0;

}