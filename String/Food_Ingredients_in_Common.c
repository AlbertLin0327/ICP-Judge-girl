#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a , const void* b){

	//strcmp((char const *)a , (char const *)b)
	//if a == b return 0
	//if a > b return > 0
	//if a < b return < 0

    //a points to a sequence of char
    return strcmp((char const *)a , (char const *)b);
}
 
int main(){
    int n; scanf("%d\n" , &n);
    char food_name[100][70];
    int num[100];
    char ingrediant[100][10][70];

    for(int i = 0; i < n ; i++){
        scanf("%s %d" , food_name[i] , &(num[i]));

        for(int j = 0; j < num[i]; j++){
            scanf("%s" , ingrediant[i][j]);
        }

        qsort(ingrediant[i] , num[i] , 70 , cmp);
    }

    int m; scanf("%d" , &m);
  
    while(m--){
    	char target[2][70];
    	scanf("%s %s" , target[0] , target[1]);

    	int a , b;
    	for(int i = 0; i < n; i++){
    		if(strcmp(target[0] , food_name[i]) == 0)
    			a = i;
    		if(strcmp(target[1] , food_name[i]) == 0)
    			b = i;
    	}

    	char result[10][70];
    	int sum = 0;
    	for(int i = 0; i < 10; i++)
    		result[i][0] = '\0';

    	for(int i = 0; i < num[a]; i++){
    		for(int j = 0; j < num[b]; j++){
    			if(strcmp(ingrediant[a][i] , ingrediant[b][j]) == 0){

    				//remember to add '\0' after using memcpy!!!
    				memcpy(result[sum] , ingrediant[b][j] , strlen(ingrediant[b][j]));
    				result[sum][strlen(ingrediant[b][j])] = '\0';
    				sum++;
    			}
    		}
    	}

    	if(result[0][0] == '\0')
            printf("nothing\n");
        else{
            for(int i = 0; i < sum; i++){
                printf("%s%c", result[i] , (i == sum - 1 ? '\n' : ' '));
            }
        }
    }

 
    
    return 0;
 
}



/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void* a , const void* b){
	const char *ia = (const char *)a;
    const char *ib = (const char *)b;
    return strcmp(ia , ib);
}
 
int main(){
    char food[100][400];
    int n; scanf("%d\n" , &n);
 
    for(int i = 0; i < n; i++){
        fgets(food[i] , 400 , stdin);
    }
 
    int m; scanf("%d" , &m);
 
    while(m--){
        char target[2][400];
        scanf("%s %s" , target[0] , target[1]);
        int a = -1 , b = -1;
        for(int i = 0; i < n; i++){
            if(strstr(food[i] , target[0]) != NULL)
                a = i;
            else if(strstr(food[i] , target[1]) != NULL)
                b = i;
        }
 		
 		char temp[400];
 		memcpy(temp , food[a] , strlen(food[a]) + 1);
        char* sub = temp;
        sub = strtok(sub , " \n");
 
        char result[10][80];
        result[0][0] = '\0';
 
        int same = 0;
        while(sub != NULL){
            if(isdigit(*sub)){
                sub = strtok(NULL , " \n");
                continue;
            }else{
                if(strstr(food[b] , sub) != NULL){
                    //strcat(result , sub);
                    //strcat(result , " \0");
                    strcpy(result[same] , sub);
                    same++;
                }
 
                sub = strtok(NULL , " \n");
            }
        }

        free(sub);
 
        if(result[0][0] == '\0')
            printf("nothing\n");
        else{
            qsort(result , same , sizeof(char) , cmp);
            for(int i = 0; i < same; i++){
                printf("%s%c", result[i] , (i == same - 1 ? '\n' : ' '));
            }
        }
 
    }
 
    return 0;
 
}*/