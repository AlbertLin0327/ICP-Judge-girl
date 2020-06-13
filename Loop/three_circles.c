#include <stdio.h>

int main(){
	int n;
	scanf("%d" , &n);

	while(n--){
		long x[3] , y[3] , r[3];

		for(int i = 0; i < 3; i++){
			scanf("%ld %ld %ld" , &(x[i]) , &(y[i]) , &(r[i]));
		}

		int count = 0 , overlap = 0;

		for(int i = 0; i < 3; i++){
			for(int j = -r[i]; j <= r[i]; j++){
				for(int k = -r[i]; k <= r[i]; k++){

					if(j * j + k * k > r[i] * r[i]) continue;

					if( (x[i] + j - x[0]) * (x[i] + j - x[0]) + (y[i] + k - y[0]) * (y[i] + k - y[0]) <= r[0] * r[0] &&\
						(x[i] + j - x[1]) * (x[i] + j - x[1]) + (y[i] + k - y[1]) * (y[i] + k - y[1]) <= r[1] * r[1] &&\
						(x[i] + j - x[2]) * (x[i] + j - x[2]) + (y[i] + k - y[2]) * (y[i] + k - y[2]) <= r[2] * r[2] ){
						overlap++;
					} 
					
					if( (x[i] + j - x[0]) * (x[i] + j - x[0]) + (y[i] + k - y[0]) * (y[i] + k - y[0]) <= r[0] * r[0] &&\
						(x[i] + j - x[1]) * (x[i] + j - x[1]) + (y[i] + k - y[1]) * (y[i] + k - y[1]) > r[1] * r[1] &&\
						(x[i] + j - x[2]) * (x[i] + j - x[2]) + (y[i] + k - y[2]) * (y[i] + k - y[2]) > r[2] * r[2] ) count++;

					if( (x[i] + j - x[0]) * (x[i] + j - x[0]) + (y[i] + k - y[0]) * (y[i] + k - y[0]) > r[0] * r[0] &&\
						(x[i] + j - x[1]) * (x[i] + j - x[1]) + (y[i] + k - y[1]) * (y[i] + k - y[1]) <= r[1] * r[1] &&\
						(x[i] + j - x[2]) * (x[i] + j - x[2]) + (y[i] + k - y[2]) * (y[i] + k - y[2]) > r[2] * r[2] ) count++;

					if( (x[i] + j - x[0]) * (x[i] + j - x[0]) + (y[i] + k - y[0]) * (y[i] + k - y[0]) > r[0] * r[0] &&\
						(x[i] + j - x[1]) * (x[i] + j - x[1]) + (y[i] + k - y[1]) * (y[i] + k - y[1]) > r[1] * r[1] &&\
						(x[i] + j - x[2]) * (x[i] + j - x[2]) + (y[i] + k - y[2]) * (y[i] + k - y[2]) <= r[2] * r[2] ) count++;

				}
			}
		}

		count += (overlap/3);

		printf("%d\n" , count);

	}

	return 0;
}