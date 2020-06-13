#include <stdio.h>

int path(r , c){
	if(r == 0 && c == 0){
		return 1;
	}else{
		int result = 0;
		if(r > 0)
			result += path(r - 1 , c);
		if(c > 0)
			result += path(r , c - 1);
		return result;
	}
}

int main(){
	int r , c; scanf("%d%d" , &r , &c);

	printf("%d\n" , path(r - 1 , c - 1));
}