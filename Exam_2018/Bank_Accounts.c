#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Data{
	char name[40];
	int money;
};

typedef struct Data data;

int main(void){
	int n; scanf("%d" , &n);

	data user[n];
	for(int i = 0; i < n; i++)
		scanf("%s %d" , user[i].name , &(user[i].money));
	
	char user_name[40] , instruction[40];
	char error[120];

	while(scanf("%s %s" , user_name , instruction) == 2){
		bool not_found = 1;
		int first = -1;
		for(int i = 0; i < n; i++){
			if(!strcmp(user[i].name , user_name)){
				not_found = 0;
				first = i;
				break;
			}
		}

		if(not_found){

			//remember to get rid of error message before you break
			//in C++ getlin(cin , str) OR cin.getline(str , int)
			fgets(error , 120 , stdin);
			continue;
		}
		
		if(strstr(instruction , "gives")){
			scanf("%s" , user_name);
			int second = -1;
			bool found = 0;
			for(int i = 0; i < n; i++){
				if(!strcmp(user[i].name , user_name)){
					found = 1;
					second = i;
					break;
				}
			}

			if(found){
				int transaction; scanf("%d" , &transaction);
				if(user[first].money >= transaction){
					user[first].money -= transaction;
					user[second].money += transaction;
				}
			}else{
				fgets(error , 120 , stdin);
			}

		}else{
			int transaction; scanf("%d" , &transaction);

			if(strstr(instruction , "earns"))
				user[first].money += transaction;
			else if(strstr(instruction , "spends") && user[first].money >= transaction)
				user[first].money -= transaction;
			else if(strstr(instruction , "becomes"))
				user[first].money = transaction;
			
		}

	}

	for(int i = 0; i < n; i++)
		printf("%s %d\n", user[i].name , user[i].money);
	

	return 0;
}