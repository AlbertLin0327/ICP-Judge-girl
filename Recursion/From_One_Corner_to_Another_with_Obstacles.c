#include <stdio.h>

int path(int r , int c , int map[12][12]){
	if(r == 0 && c == 0){
		return 1;
	}else{
		int result = 0;
		if(r > 0 && map[r - 1][c] == 1){
			result += path(r - 1 , c , map);
		}
		if(c > 0 && map[r][c - 1] == 1){
			result += path(r , c - 1 , map);
		}
		return result;
	}
}

int main(void){
	int r , c; scanf("%d%d" , &r , &c);

	int map[12][12];
	for(int i = 0; i < r; i++){
		for(int j = c - 1; j >= 0; j--){
			scanf("%d" , &(map[i][j]));
		}
	}

	printf("%d\n" , path(r - 1 , c - 1 , map));

	return 0;

}