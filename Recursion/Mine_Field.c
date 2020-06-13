#include <stdio.h>
#include <stdbool.h>

//Calculate the value of -- count[i + 1][j + 1]
int cell_value(bool mine_field[11][11] , const int count[11][11] , int i , int j){
	return (count[i][j] - mine_field[i - 1][j - 1] - mine_field[i - 1][j] - mine_field[i - 1][j + 1] - mine_field[i][j - 1] \
		- mine_field[i][j] - mine_field[i][j + 1] - mine_field[i + 1][j - 1] - mine_field[i + 1][j] - mine_field[i + 1][j + 1]);
}

bool check(bool mine_field[11][11] , const int count[11][11]){
	for(int i = 2; i < 10; i++)
		for(int j = 2; j < 10; j++)
			mine_field[i][j] = 0;
	
	for(int i = 1; i < 9; i++){
		for(int j = 1; j < 9; j++){

			int flag = cell_value(mine_field , count , i , j);
			if(flag == 1)
				mine_field[i + 1][j + 1] = 1;
			else if(flag != 0)
				return 0;

		}
		if(cell_value(mine_field , count , i , 9) != 0)
			return 0;
	}

	for(int i = 1; i < 10; i++){
		if(cell_value(mine_field , count , 9 , i) != 0)
			return 0;
	}
	return 1;
}

bool build(bool mine_field[11][11] , const int count[11][11] , int index){

	//printf("%d。%d\n", 1 + (index < 9 ? 0 : (index - 9)) , 1 + (index < 9 ? index : 0));
 
	if(check(mine_field , count))
        return 1;

    if(index == 18)
        return 0;

    // consider current to be 0. If without this, you will have all your ones consecutive
 	mine_field[1 + (index < 9 ? 0 : (index - 9))][1 + (index < 9 ? index : 0)] = 0;
    if(build(mine_field , count , index + 1))
    	return 1;

    mine_field[1 + (index < 9 ? 0 : (index - 9))][1 + (index < 9 ? index : 0)] = 1;
    if(build(mine_field , count , index + 1))
    	return 1;
 
}

// this method is too time consuming
/*
bool check(bool mine_field[11][11] , const int count[11][11] , int target_RC){
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			if(count[i][j] != mine_field[i][j] + mine_field[i - 1][j - 1] + mine_field[i - 1][j] + mine_field[i - 1][j + 1] + \
				mine_field[i][j - 1] + mine_field[i][j + 1] + mine_field[i + 1][j - 1] + mine_field[i + 1][j] + mine_field[i + 1][j + 1])
				return 0;
		}
	}
	return 1;
}

bool add_one(bool mine_field[11][11]){
	bool carry = 0;
	for(int i = 0; i < 81; i++){
		carry = 1 & mine_field[1 + i / 9][1 + i % 9] & carry;
		mine_field[1 + i / 9][1 + i % 9] = (carry ^ 1 ^ mine_field[1 + i / 9][1 + i % 9]);

		if(!carry)
			return 1;

		if(i == 80 && carry)
			return 0;
	}
}

bool build(bool mine_field[11][11] , const int count[11][11] , int index){
		
	while(add_one(mine_field) == 1){
		if(check(mine_field , count))
			return 1;
	}
	return 0;
}
*/

int main(){
	int count[11][11];
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < 10; j++)
			scanf("%d" , &count[i][j]);

	bool mine_field[11][11] = {0};

	if(build(mine_field , count , 0)){
		for(int i = 1; i < 10; i++)
			for(int j = 1; j < 10; j++)
				printf("%d%c" , mine_field[i][j] , j == 9 ? '\n' : ' ');
	}else{
		printf("no solution\n");
	}
}