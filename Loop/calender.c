#include <stdio.h>

int main(){
	int year , month , day , n;

	scanf("%d%d%d" , &year , &month , &day);

	if(month > 12 || day > 6 || month < 1 || day < 0){
		printf("invalid\n");
		return 0;
	}

	
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:  
				n = 31;
				break;

			case 2:
				if((!(year % 4) && year % 100) || !(year % 400)){
					n = 29;
					break;
				} else {
					n = 28;
					break;
				}

			case 4: case 6: case 9: case 11:
				n = 30;
				break;

		}

		printf(" Su Mo Tu We Th Fr Sa\n=====================\n");

		for(int i = 0; i < day; i++){
			printf("   ");
		} 

		for(int i = 1; i <= n; i++){
			if(!((i + day - 1) % 7) && i + day - 1 != 0) {
				printf("\n%3d" , i);
			}else{
				printf("%3d" , i);
			}
		}
		printf("\n");
		printf("=====================\n");

		return 0;

}