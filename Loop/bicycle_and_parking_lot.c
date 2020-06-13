#include <stdio.h>
#include <stdlib.h>

int main(){

	int n ,bound_n , m;
	scanf("%d" , &n);

	bound_n = n;
	int parking_lot[10][4] = {0};

	while(n--){
		scanf("%d %d %d" , &(parking_lot[bound_n - n-1][0]) , &(parking_lot[bound_n - n-1][1]) , &(parking_lot[bound_n - n-1][2]));	
	}

	scanf("%d" , &m);

	while(m--){
		int x , y , park , nearest = 2147483647;
		scanf("%d %d" , &x , &y);

		int distance[10] = {0};

		for(int i = 0;i < bound_n; i++){

			if(parking_lot[i][2] > parking_lot[i][3]){
				distance[i] = abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]);
			}else {
				distance[i] = -1;
			}
			
		}

		for(int i = 0; i < bound_n; i++){
			if(distance[i] == -1){
				continue;
			}else{

				if(abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]) < nearest ){
					nearest = abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]);
					park = i;
				}else if(abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]) == nearest && parking_lot[i][0] < parking_lot[park][0]){
					nearest = abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]);
					park = i;
				}else if(abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]) == nearest && parking_lot[i][0] == parking_lot[park][0] && parking_lot[i][1] < parking_lot[park][1]){
					nearest = abs(x - parking_lot[i][0]) + abs(y - parking_lot[i][1]);
					park = i;
				}

			}
		}

		parking_lot[park][3]++;
		
 
	}
 
	for(int i = 0; i < bound_n; i++){
		printf("%d\n" , parking_lot[i][3]);
	}
 
	return 0;
 
}