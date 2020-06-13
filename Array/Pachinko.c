#include <stdio.h>
#include <stdbool.h>

long gcd(long a , long b){

	if(b == 0){
		return a;
	}else if(a % b == 0){
		return b;
	}else{
		return gcd(b , a % b);
	}

}

int main(){

	int n;
	scanf("%d" , &n);

	if(n == 0){
		printf("1/1\n");
		return 0;
	}

	long pin[n][n][2];
	bool stop = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(scanf("%ld%ld" , &pin[i][j][0] , &pin[i][j][1]) == EOF){
				stop = 1;
				break;
			}

			long common = gcd(pin[i][j][1] , pin[i][j][0]);
			pin[i][j][0] /= common;
			pin[i][j][1] /= common;

		}
		if(stop == 1){
			break;
		}
	}

	long result[n + 2][n + 2][2];
	long common;
	
	result[1][0][0] = pin[0][0][0];
	result[1][1][0] = pin[0][0][1];
	result[1][0][1] = (pin[0][0][0] + pin[0][0][1]);
	result[1][1][1] = (pin[0][0][0] + pin[0][0][1]);



	for(int i = 2; i <= n; i++){
		result[i][0][0] = result[i - 1][0][0] * pin[i - 1][0][0];
		result[i][0][1] = result[i - 1][0][1] * (pin[i - 1][0][0] + pin[i -1][0][1]);
		common = gcd(result[i][0][1] , result[i][0][0]);
		
		result[i][0][0] /= common;
		result[i][0][1] /= common;

		result[i][i][0] = result[i - 1][i - 1][0] * pin[i - 1][i - 1][1];
		result[i][i][1] = result[i - 1][i - 1][1] * (pin[i - 1][i - 1][0] + pin[i - 1][i - 1][1]);
		common = gcd(result[i][i][1] , result[i][i][0]);
	
		result[i][i][0] /= common;
		result[i][i][1] /= common;
		

		for(int j = 1; j < i; j++){
			
			result[i][j][0] = (result[i - 1][j - 1][0] * pin[i - 1][j - 1][1]) * (result[i - 1][j][1] * (pin[i - 1][j][0] + pin[i - 1][j][1])) + (result[i - 1][j][0] * pin[i - 1][j][0]) * (result[i - 1][j - 1][1] * (pin[i - 1][j - 1][0] + pin[i - 1][j - 1][1]));
			result[i][j][1] = result[i - 1][j][1] * (pin[i - 1][j][0] + pin[i - 1][j][1]) * result[i - 1][j - 1][1] * (pin[i - 1][j - 1][0] + pin[i - 1][j - 1][1]);
			common = gcd(result[i][j][1] , result[i][j][0]);


			result[i][j][0] /= common;
			result[i][j][1] /= common;
		}
	}




	for(int i = 0; i <= n; i++){
		printf("%ld/%ld\n" , result[n][i][0] , result[n][i][1]);
	}
	
	
	return 0;

}