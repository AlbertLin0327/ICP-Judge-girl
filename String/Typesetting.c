#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
int main(){
    int m; scanf("%d" , &m);
    char line[m + 5][m + 5]; scanf("%s" , line[0]);

    int sum = strlen(line[0]); 
    int index = 1;

    while(scanf("%s" , line[index]) != EOF){
    	if(sum + strlen(line[index]) + index - 1 >= m){
    		if(index == 1){	
                printf("%s", line[0]);
    			for(int i = 0; i < (m - sum); i++)
    				printf(" ");
    		}else{
    			int space = (m - sum) / (index - 1);
    			int extra = (m - sum) % (index - 1);
    			for(int i = 0; i < index; i++ , extra--){
    				printf("%s", line[i]);
    				if(extra > 0){
    					printf(" ");
                    }
    				for(int j = 0; j < space; j++){
    					if(i != index - 1){
    						printf(" ");
                        }
                    }
    			}
    		}
            printf("\n");
    		memcpy(line[0] , line[index] , strlen(line[index]));
    		line[0][strlen(line[index])] = '\0';
            for(int i = 1; i < index; i++)
                line[i][0] = '\0';
    		sum = 0;
    		index = 0;
    	}
        sum +=  strlen(line[index]);
        index++;
    }	
 
    if(index == 1){    
        printf("%s", line[0]);
        for(int i = 0; i < (m - sum); i++)
            printf(" ");
    }else{
        int space = (m - sum) / (index - 1);
        int extra = (m - sum) % (index - 1);
        for(int i = 0; i < index; i++ , extra--){
            printf("%s", line[i]);
            if(extra > 0){
                printf(" ");
            }
            for(int j = 0; j < space; j++){
                if(i != index - 1){
                    printf(" ");
                }
            }
        }
    }
}