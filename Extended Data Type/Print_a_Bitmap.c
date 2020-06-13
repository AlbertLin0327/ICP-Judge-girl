#include <stdio.h>
#include <stdbool.h>

int main(){
	int r , c; scanf("%d%d" , &r , &c);

	char map[c][r];

	//The leading whitespace ensures it's the previous newline is ignored (when scanf %c)
	char one; scanf(" %c" , &one);
	char zero; scanf(" %c" , &zero);

	unsigned int num;
	int index = 0;
	bool stop = 0;

	while(scanf("%u" , &num) != EOF){
		for(int i = 31; i >= 0; i--){
			if(index < r * c){
				if((num >> i) & 1){
					map[index / r][index % r] = one;
				}else{
					map[index / r][index % r] = zero;
				}
				index++;
				
			}else{
				stop = 1;
				break;
			}
		}
		if(stop) break;
	}

	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;

}