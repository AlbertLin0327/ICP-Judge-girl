#include <stdio.h>
#include <stdbool.h>

bool potion(int D , int a , int b , int c , int A , int B , int C , int current){
	switch(current){
		case 0:
			for(int i = 0; i <= a && D - i * A >= 0; i++){
				if(potion(D - i * A , a - 1 , b , c , A , B , C , current + 1))
					return 1;
			}
			break;
		case 1:
			for(int i = 0; i <= b && D - i * B >= 0; i++){
				if(potion(D - i * B , a , b - 1 , c , A , B , C , current + 1))
					return 1;
			}
			break;
		case 2:
			for(int i = 0; i <= c && D - i * C >= 0; i++){
				if(potion(D - i * C , a , b , c  - 1 , A , B , C , current + 1))
					return 1;
			}
			break;
		case 3:
			return D == 0;
			break;

	}

	return 0;

	/*
	//This method would calculate the same combination in different sequence
	if(D == 0 || (a > 0 && A != 0 && !(D % A)) || (b > 0 && B != 0 && !(D % B)) || (c > 0 && C != 0 && !(D % C)))
        return 1;
 
     int result = 0;
     if(a > 0 && D > A && A > 0)
         result += potion(D - A , a - 1 , b , c , A , B , C);
     if(b > 0 && D > B && B > 0)
         result += potion(D - B , a , b - 1 , c , A , B , C);
     if(a > 0 && D > A && C > 0)
         result += potion(D - C , a , b , c - 1 , A , B , C);
 
     return result;
     */

}

int main(){
	int N; scanf("%d" , &N);

	while(N--){

		int D , a , b , c , A , B , C; 
		scanf("%d%d%d%d%d%d%d" , &D , &a , &b , &c , &A , &B , &C);

		if(potion(D , a , b , c , A , B , C , 0)){
			printf("yes\n");
		}else{
			printf("no\n");
		}

	}

	return 0;

}