#include <stdio.h>

int main(){
	int year , init_day;

	scanf("%d %d" , &year , &init_day);

	int m;
	scanf("%d" , &m);

	while(m--){
		int mth , date , distance = 0;

		scanf("%d %d" , &mth , &date);
		if(mth > 12 || mth < 1){
			printf("-1\n");
			continue;
			}
		if(date < 1){
			printf("-2\n");
			continue;
		}

		if((!(year % 4) && year % 100) || !(year % 400)){

			switch (mth){

				case 1 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 1;
					continue;
				case 2 :
					if(date > 29){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 2;
					break;
				case 3 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 3;
					break;
				case 4 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 1;
					break;
				case 5 :
					if(date > 31){
						printf("-2\n");
						continue;
					}	
					distance += init_day + date + 1;
					break;
				case 6 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 3;
					break;
				case 7 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 1;
					break;
				case 8 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 2;
					break;
				case 9 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 2;
					break;
				case 10 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date;
					break;
				case 11 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 3;
					break;
				case 12 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 2;
					break;

			}
		}else {
			switch (mth){

				case 1 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 1;
					break;
				case 2 :
					if(date > 28){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 2;
					break;
				case 3 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 2;
					break;
				case 4 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 2;
					break;
				case 5 :	
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date;
					break;
				case 6 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 4;
					break;
				case 7 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 2;
					break;
				case 8 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 1;
					break;
				case 9 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 3;
					break;
				case 10 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 1;
					break;
				case 11 :
					if(date > 30){
						printf("-2\n");
						continue;
					}
					distance += init_day + date + 2;
					break;
				case 12 :
					if(date > 31){
						printf("-2\n");
						continue;
					}
					distance += init_day + date - 3;
					break;
			}
			
		}

		printf("%d\n" , distance % 7);

	}

	return 0;
	
}