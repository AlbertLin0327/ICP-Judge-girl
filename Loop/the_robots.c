#include <stdio.h>

int main(){
	int M , N , X1 , Y1 , E1 , N1 , F1 , X2 , Y2 , E2 , N2 , F2;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d" , &M , &N , &X1 , &Y1 , &E1 , &N1 , &F1 , &X2 , &Y2 , &E2 , &N2 , &F2);

	int time = 0;

	int SN1 = 0 , SE1 = 0 , SN2 = 0 , SE2 = 0;

	while(1 == 1){
		F1--; F2--; time++;

		if(F1 >= 0){
			if(N1 > SN1){
				Y1++; SN1++;
				if(Y1 == N)
					Y1 = 0;
			}else if(E1 > SE1){
				X1++; SE1++;
				if(X1 == M)
					X1 = 0;
			}
		}
		if(SN1 + SE1 == E1 + N1){
			SN1 = 0; SE1 = 0;
		}
				
		if(F2 >= 0){
			if(E2 > SE2){
				X2++; SE2++;
				if(X2 == M)
					X2 = 0;
			}else if(N2 > SN2){
				Y2++; SN2++;
				if(Y2 == N)
					Y2 = 0;
			}
		}
		if(SE2 + SN2 == N2 + E2){
			SE2 = 0; SN2 = 0;
		}
				

		if(X1 == X2 && Y1 == Y2){
			printf("robots explode at time %d\n" , time);
			break;
		}

		if(F1 < 0 && F2 < 0){
			printf("robots will not explode\n");
			break;
		}

	}

	return 0;

}