#include <stdio.h>
#include <stdbool.h>

int make(int DA , int DB , int DC , int EA , int EB , int EC , int FA , int FB , int FC , int A , int B , int C){
	if(A == 0 && B == 0 && C == 0){
		return 1;
	}else if(A < 0 || B < 0 || C < 0){
		return 0;
	}else{
		return (make(DA , DB , DC , EA , EB , EC , FA , FB , FC , A - DA , B - DB , C - DC) + make(DA , DB , DC , EA , EB , EC , FA , FB , FC , A - EA , B - EB , C - EC) + make(DA , DB , DC , EA , EB , EC , FA , FB , FC , A - FA , B - FB , C - FC));
	}
	 
}

void init(int DA , int DB , int DC , int EA , int EB , int EC , int FA , int FB , int FC , int n){
	if(n > 0){
		int A , B , C; scanf("%d%d%d" , &A , &B ,  &C);
		if(make(DA , DB , DC , EA , EB , EC , FA , FB , FC , A , B , C)){
			printf("yes\n");
		}else{
			printf("no\n");
		}
		init(DA , DB , DC , EA , EB , EC , FA , FB , FC , n - 1);
	}
}

int main(){
	int DA , DB , DC; scanf("%d%d%d" , &DA , &DB , &DC);
	int EA , EB , EC; scanf("%d%d%d" , &EA , &EB , &EC);
	int FA , FB , FC; scanf("%d%d%d" , &FA , &FB , &FC);

	int n; scanf("%d", &n);
	init(DA , DB , DC , EA , EB , EC , FA , FB , FC , n);

	return 0;

}