#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{	
	char name[40];
	char club[40];
}Student;

typedef struct{
	char club[40];
	char leader[40];
}Club;

Student student[100000];
Club data[100000];

void create(char name[40] , char club[40] , int* club_ctr , int* student_ctr){
	strcpy(data[*club_ctr].club , club);
	strcpy(data[*club_ctr].leader , name);
	strcpy(student[*student_ctr].club , club);
	strcpy(student[*student_ctr].name , name);
	(*club_ctr)++; (*student_ctr)++;
}

void add_club(char name[40] , char club[40] , int* student_ctr){
	strcpy(student[*student_ctr].club , club);
	strcpy(student[*student_ctr].name , name);
	(*student_ctr)++;
}

void leader_trace(char club[40] , int club_ctr){
	for(int i = 0; i < club_ctr; i++){
		if(strcmp(data[i].club , club) == 0){
			printf("%s\n", data[i].leader); 
			return;
		}
	}
	printf("None\n");
}

void query(char name[40] , char club[40] , int club_ctr , int student_ctr){
	for(int i = 0; i < student_ctr; i++){
		if(strcmp(student[i].name , name) == 0){
			if(strcmp(student[i].club , club) == 0){
				printf("1\n"); return; 
			}
		}
	}
	for(int i = 0; i < club_ctr; i++)
		if(strcmp(data[i].club , club) == 0){
			printf("0\n"); return; 
		}
	
	printf("-1\n"); return; 
}

int main(){
	int N; scanf("%d" , &N);
	int student_ctr = 0 , club_ctr = 0;
	for(int i = 0; i < N; i++){
		int mode; char name[40] , club_name[40];
		scanf("%d %s %s" , &mode , name , club_name);
		switch(mode){
			case 0:
				create(name , club_name , &club_ctr , &student_ctr);
				break;

			case 1:
				add_club(name , club_name , &student_ctr);
				break;
		}
	}

	int M; scanf("%d" , &M);
	for(int i = 0; i < M; i++){
		int mode; char name[40] , club_name[40]; 
		scanf("%d" , &mode);
		switch(mode){
			case 0:
				scanf("%s" , club_name);
				leader_trace(club_name , club_ctr);
				break;

			case 1:
				scanf("%s %s" , name , club_name);
				query(name , club_name , club_ctr , student_ctr);
				break;
		}
	}

}