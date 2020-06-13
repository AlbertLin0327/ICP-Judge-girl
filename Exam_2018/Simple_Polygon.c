#include <stdio.h>

int main(){
	int coordination[8];
	for(int i = 0; i < 8; i++){
		scanf("%d" , &(coordination[i]));
	}

	int perimeter = 2 * (coordination[4] - coordination[0]) + 2 * (coordination[5] - coordination[1]);

	int area = (coordination[4] - coordination[0]) * (coordination[5] - coordination[1]) - (coordination[4] - coordination[2]) * (coordination[3] - coordination[1]) - (coordination[6] - coordination[0]) * (coordination[5] - coordination[7]);

	printf("%d\n%d\n", perimeter , area);

	return 0;

}