#include <stdio.h>
#include <stdbool.h>

int main(){

	int N , M;scanf("%d%d" , &N , &M); //M rows , N column

	int insturction , x = 0 , y = 0; 
	printf("%d\n%d\n", x , y);

	while(scanf("%d" , &insturction) != EOF){
		char flag = insturction % 5;
		bool print = 0;

		if(flag == 1 && x + insturction < N){
			x += insturction;
			print = 1;
		}else if(flag == 2 && x - insturction >= 0){
			x -= insturction;
			print = 1;
		}else if(flag == 3 && y + insturction < M){
			y += insturction;
			print = 1;
		}else if(flag == 4 && y - insturction >= 0){
			y -= insturction;
			print = 1;
		}

		if(print){
			printf("%d\n%d\n", x , y);
			print = 0;
		}
	}

	return 0;

}