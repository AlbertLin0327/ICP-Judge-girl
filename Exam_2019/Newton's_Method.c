#include <stdio.h>

double power(double x , double time){
	double y = 1.0;
	
	for(int i = 0; i < time; i++)	
		y *= x;

	return y;
}

double value(double polynominal[] , int n , double x){
	double result = 0;

	for(int i = 0; i <= n; i++){
		result += polynominal[i] * power(x , n - i);
	}

	return result;
}

int main(){

	int n; scanf("%d" , &n);
	double polynominal[n + 1];
	double polynominal_derivative[n];

	for(int i = 0; i <= n; i++){
		scanf("%lf" , &polynominal[i]);
		if(i != n){
			polynominal_derivative[i] = (n - i) * polynominal[i];
		}
	}

	int iterate; scanf("%d" , &iterate);

	double prev; scanf("%lf" , &prev);
	double next;

	while(iterate--){
		printf("%.4f %.4f\n", prev , value(polynominal , n , prev));
		next = prev - (value(polynominal , n , prev) / value(polynominal_derivative , n - 1 , prev));
		prev = next;
	}

	return 0;

}
