#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct{
    unsigned int id;
    char name[32];
}person;

person person_data[10000] = {};

typedef struct{
    unsigned int id1;
    unsigned int id2;
}friends;

friends friends_data[10000] = {};

int main(){
	FILE* input = fopen("friends" , "rb");

	unsigned int P; fread(&P , 4 , 1 , input);
	fread(person_data , sizeof(person) , P , input);

	unsigned int F; fread(&F , 4 , 1 , input);
	fread(friends_data , sizeof(friends) , F , input);

	fclose(input);

	char a[35] , b[35];
	while(scanf("%s %s" , a , b) == 2){

		unsigned int a_id , b_id;
		for(int i = 0; i < P; i++){
			if(!strcmp(a , person_data[i].name))
				a_id = person_data[i].id;
			else if(!strcmp(b , person_data[i].name))
				b_id = person_data[i].id;
		}

		bool found = 0;
		for(int i = 0; i < F; i++){
			if(((a_id == friends_data[i].id1 && b_id == friends_data[i].id2) || (a_id == friends_data[i].id2 && b_id == friends_data[i].id1))){
				found = 1; break;
			}
		}

		if(found)
			printf("yes\n");
		else
			printf("no\n");

	}

}