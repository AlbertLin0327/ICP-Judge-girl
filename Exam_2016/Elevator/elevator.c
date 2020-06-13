#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "elevator.h"

struct Elevator{
	int u , d , f , current;
	int up_invalid , down_invalid;
	bool visited[1024];
};

typedef struct Elevator Elevator;
 
Elevator* newElevator(int u, int d, int f){
	Elevator* my_Elevator = malloc(sizeof(Elevator));
	my_Elevator->u = u , my_Elevator->d = d , my_Elevator->f = f , my_Elevator->current = 1;
	my_Elevator->up_invalid = my_Elevator->down_invalid = 0;
	memset(my_Elevator->visited , 0 , sizeof(my_Elevator->visited)); my_Elevator->visited[1] = 1;
	return my_Elevator;
}

int up(Elevator* my_Elevator){
	my_Elevator->down_invalid = 0;
	if(my_Elevator->current + my_Elevator->u <= my_Elevator->f){
		my_Elevator->up_invalid = 0 , my_Elevator->current += my_Elevator->u;
		my_Elevator->visited[my_Elevator->current] = 1;
		return 1;
	}
	my_Elevator->up_invalid++;
	if(my_Elevator->up_invalid == 4)
		return -1;
	else 
		return 0;

}

int down(Elevator* my_Elevator){
	my_Elevator->up_invalid = 0;
	if(my_Elevator->current - my_Elevator->d >= 1){
		my_Elevator->down_invalid = 0 , my_Elevator->current -= my_Elevator->d;
		my_Elevator->visited[my_Elevator->current] = 1;
		return 1;
	}
	my_Elevator->down_invalid++;
	if(my_Elevator->down_invalid == 4)
		return -1;
	else 
		return 0;
}

int visited(Elevator* my_Elevator, int floor){
	if(my_Elevator->visited[floor])
		return 1;
	return 0;
}
int getPosition(Elevator* my_Elevator){
	return my_Elevator->current;
}