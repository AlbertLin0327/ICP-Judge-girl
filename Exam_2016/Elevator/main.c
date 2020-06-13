#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "elevator.h"

int main(){
	int N , u , d , F;
	char instruction[1500];

	scanf("%d" , &N);
	while(N--){
		scanf("%d%d%d%s" , &u , &d , &F , instruction);
		int len = strlen(instruction);

		Elevator* my_Elevator = newElevator(u , d , F);
		bool end = 0;
		for(int i = 0; i < len && !end; i++){
			int result;
			if(instruction[i] == 'U')
				result = up(my_Elevator);
			else
				result = down(my_Elevator);

			if(result == 1)
				printf("Valid %d\n", getPosition(my_Elevator));
			else if(result == 0)
				printf("Invalid\n");
			else{
				printf("Broken\n");
				break;
			}
		}

		for(int i = 1; i <= F; i++)
			if(visited(my_Elevator , i))
				printf("%d\n", i);

		free(my_Elevator);
	}
}