#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(x , y) (x >= y? x: y)
#define min(x , y) (x <= y? x: y)

bool overlap= 1;

int overlap_area(int coordination[3][4] , int a , int b){
	if((coordination[a][2] - coordination[b][0]) * (coordination[a][0] - coordination[b][2]) <= 0 && (coordination[a][3] - coordination[b][1]) * (coordination[a][1] - coordination[b][3]) <= 0){
		return abs((min(coordination[a][2] , coordination[b][2]) - max(coordination[a][0] , coordination[b][0])) * (min(coordination[a][3] , coordination[b][3]) - max(coordination[a][1] , coordination[b][1])));
	}else {
		overlap = 0;
		return 0;
	}
}

int overlap_area_triple(int coordination[3][4] , int a , int b , int c){
	if(overlap == 0){
		return 0;
	}else {
		return abs((min(coordination[c][2] , min(coordination[a][2] , coordination[b][2])) - max(coordination[c][0] , max(coordination[a][0] , coordination[b][0]))) * (min(coordination[c][3] , min(coordination[a][3] , coordination[b][3])) - max(coordination[c][1] , max(coordination[a][1] , coordination[b][1]))));
	}
}

int main(){
	int coordination[3][4];

	for(int i = 0; i < 3 ; i++){
		for(int j = 0 ; j < 4; j++){
			scanf("%d" , &(coordination[i][j]));
		}
	}

	int area = 0;
	for(int i = 0; i < 3; i++){
		area += (coordination[i][2] - coordination[i][0]) * (coordination[i][3] - coordination[i][1]);
	}

	area -= overlap_area(coordination , 0 , 1);
	area -= overlap_area(coordination , 1 , 2);
	area -= overlap_area(coordination , 0 , 2);
	area += overlap_area_triple(coordination , 0 , 1 , 2);

	printf("%d\n", area);

	return 0;

}