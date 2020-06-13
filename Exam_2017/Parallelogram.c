#include <stdio.h>

int main(){
	int coordinate[6];
	for(int i = 0; i < 6; i++){
		scanf("%d" , &(coordinate[i]));
	}

	int x , y;
	x = coordinate[2] + coordinate[4] - coordinate[0];
	y = coordinate[3] + coordinate[5] - coordinate[1];
	printf("%d\n%d\n", x , y);

	x = coordinate[0] + coordinate[4] - coordinate[2];
	y = coordinate[1] + coordinate[5] - coordinate[3];
	printf("%d\n%d\n", x , y);

	x = coordinate[0] + coordinate[2] - coordinate[4];
	y = coordinate[1] + coordinate[3] - coordinate[5];
	printf("%d\n%d\n", x , y);

	return 0;

}