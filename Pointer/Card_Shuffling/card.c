#include <stddef.h>
#include <stdio.h>

void shuffle(int *deck[]){
	int num = 0;
	for(int i = 0; i < 10000; i++){
		if(deck[i] == NULL){
			num = i;
			break;
		}
	}	

	int shuffle[num];
	for(int i = 0; i < num; i++){
		if(!(i % 2)){
			shuffle[i] = i / 2;
		}else{
			shuffle[i] = (i / 2) + ((num + 1) / 2);
		}
	}


	int *new[num];
	for(int i = 0; i < num; i++){
		new[i] = deck[shuffle[i]];
	}

	for(int i = 0; i < num; i++){
		deck[i] = new[i];
	}
}

void print(int *deck[]){
	int num = 0;
	for(; num < 10000; num++){
		if(deck[num] != NULL){
			printf("%d ", *(deck[num]));
		}else{
			break;
		}
	}

}