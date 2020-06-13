#include <stdio.h>
#include <stdbool.h>
 
int main(){
    int n; scanf("%d" ,  &n);
 
    int seat[n][20][5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 5; k++){
                seat[i][j][k] = 0;
            }
        }
    }
    int single[3] = {0 , 0 , 0};
    int two[3] = {0 , 0 , 0};
 
    int people;
    while(scanf("%d" , &people) == 1){
    	bool exit = 0;
        bool init = 0;
        switch(people){
    		case 1:
    			for(int i = 0; i < n; i++){
    				for(int j = 0; j < 20; j++){
    					for(int k = 0; k < 5; k++){
    						if(init == 0){
    							i = single[0]; j = single[1]; k = single[2];
    							init = 1;
    						}
    						if(seat[i][j][k] == 0){
    							printf("%d %d %d\n", i + 1 , j + 1 , k + 1);
    							seat[i][j][k] = 1;
    							single[0] = i; single[1] = j; single[2] = k;
                                exit = 1;
                                break;
    						}
    						if(exit) break;
    					}
    					if(exit) break;
    				}
    				if(exit) break;
    			}
    			break;

    			case 2: 

    				if(!(two[0] == n - 1 && two[1] == 19 && (two[2] == 3))){
		    			for(int i = 0; i < n; i++){
		    				for(int j = 0; j < 20; j++){
		    					for(int k = 0; k < 5; k++){
		    						if(init == 0){
		    							i = two[0]; j = two[1]; k = two[2];
		    							init = 1;
		    						}
		    						if(seat[i][j][k] == 0){
		    							switch(k){
		    								case 2: case 4:
		    									break;
		    								case 0: case 1: case 3:
		    									printf("%d %d %d %d %d %d\n", i + 1 , j + 1 , k + 1 , i + 1 , j + 1 , k + 2);
		    									seat[i][j][k] = 1; seat[i][j][k + 1] = 1;
			    								two[0] = i; two[1] = j; two[2] = k;
			    								exit = 1;
			    								break;
			    						}
		    						}
		    						if(exit) break;
		    					}
		    					if(exit) break;
		    				}
		    				if(exit) break;
		    			}
	    			}else{
	    				int time = 0;
	    				for(int i = 0; i < n; i++){
		    				for(int j = 0; j < 20; j++){
		    					for(int k = 0; k < 5; k++){
		    						if(init == 0){
		    							i = single[0]; j = single[1]; k = single[2];
		    							init = 1;
		    						}
		    						if(seat[i][j][k] == 0){
		    							seat[i][j][k] = 1;
		    							if(time == 0){
		    								printf("%d %d %d ", i + 1 , j + 1 , k + 1);
		    								single[0] = i; single[1] = j; single[2] = k;
		    								time++;
		    								continue;
		    							}else if(time == 1){
		    								printf("%d %d %d\n", i + 1 , j + 1 , k + 1);
			    							single[0] = i; single[1] = j; single[2] = k;
			                                exit = 1;
			                                break;
		    							}
		    						}
		    						if(exit) break;
		    					}
		    					if(exit) break;
		    				}
		    				if(exit) break;
		    			}
	    			}
	    			break;
	    		}
 
    }
}