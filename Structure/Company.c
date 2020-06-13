#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct employee {
  int id;
  char first_name[40];
  char last_name[40];
  int boss_id;
};

typedef struct employee E;

int search_Name(E e[], char first_name[] , char last_name[] , int n){
	int index = 0;
	for(; index < n; index++){
		if(!strcmp(e[index].first_name , first_name) && !strcmp(e[index].last_name , last_name)){
			break;
		}
	}
	return index;
}

int searchID(E e[], int key){
	int index = 0;
	while(e[index].id != key){
		index++;
	}
	return index;
}

bool find_boss(E e[] , int boss[] , int index , int target){
	while(e[index].id != e[boss[index]].id){
		if(e[index].boss_id == target)
			return 1;
		index = searchID(e , e[index].boss_id);
	}
	//sequence[i] = counter;
	return 0;
}

int main(){
	int n; scanf("%d" , &n);

	E data[n];
	for(int i = 0; i < n; i++){
		scanf("%d %s %s %d" , &data[i].id , data[i].first_name , data[i].last_name , &data[i].boss_id);
	}

	int boss[n];
	//int sequence[n];

	for(int i = 0; i < n; i++){
		int index = i;
		while(data[index].id != data[index].boss_id){
			index = searchID(data , data[index].boss_id);
		}
		boss[i] = index;
	}

	int m; scanf("%d" , &m);

	for(int i = 0; i < m; i++){
		char first_person[2][40] , second_person[2][40];
		scanf("%s %s %s %s" , first_person[0] , first_person[1] , second_person[0] , second_person[1]);

		int first = search_Name(data , first_person[0] , first_person[1] , n);
		int second = search_Name(data , second_person[0] , second_person[1] , n);

		if(boss[first] != boss[second]){
			printf("unrelated\n");
		}else{
			if(find_boss(data , boss , second , data[first].id)){
				printf("supervisor\n");
			}else if(find_boss(data , boss , first , data[second].id)){
				printf("subordinate\n");
			}else{
				printf("colleague\n");
			}
		}

	}
}