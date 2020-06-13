#include "value.h"
#include <math.h>
#define min(x , y) (x < y? x: y)
#define max(x , y) (x > y? x: y)


int gcd(int a , int b){
	if(!(max(a , b) % min(a , b))){
		return min(a , b);
	}else {
		return gcd(min(a , b) , max(a , b) % min(a , b));
	}
}

int value(int type, int width, int height, int length){
	int unit_price;


	if(width <= 0 || height <= 0 || length <= 0)
		return -2;

	switch(type) {
		case 79:
			unit_price = 30;
			break;
		case 47:
			unit_price = 10;
			break;
		case 29:
			unit_price = 4;
			break;
		case 82:
			unit_price = 5;
			break;
		case 26:
			unit_price = 3;
			break;
		case 22:
			unit_price = 9;
			break;
		default:
			return -1;
	}

	int cube = gcd(width , gcd(height , length));

	return pow(cube , 6) * unit_price * (width * height * length) / pow(cube , 3);

}