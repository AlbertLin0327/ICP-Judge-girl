#include <stdio.h>
#define max(x , y) (x > y? x: y)
#define min(x , y) (x < y? x: y)

int main(){
	int x , y;

	//if you write arr[n] = {k}, you only initialize the first element to k. The rest would be automatically given the value 0!!
	int max[2] = {-10000 , -10000};
	int min[2] = {10000 , 10000};

	while(scanf("%d%d" , &x , &y) == 2){

		max[0] = max(max[0] , x);
		max[1] = max(max[1] , y);

		min[0] = min(min[0] , x);
		min[1] = min(min[1] , y);

	}

	int area = (max[0] - min[0]) * (max[1] - min[1]);

	printf("%d\n" , area);

	return 0;

}