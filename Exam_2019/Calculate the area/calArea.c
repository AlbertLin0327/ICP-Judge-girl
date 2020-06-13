#include<stdio.h>
#include<stdlib.h>
#include "calArea.h"

int calArea(NODE* head){

	// count upper
	int total_r = 0 , total_d = 0;
	int upper_d = 0 , lower_r = 0;

	NODE *upper , *lower;
	upper = head->rightPtr;
	lower = head->downPtr;
	total_r++;

	int substract_area = 0;
	while(upper != lower){
		if(upper->rightPtr != NULL){
			upper = upper->rightPtr;
			total_r++;
			substract_area += upper_d;
		}else if(upper->downPtr != NULL){
			upper = upper->downPtr;
			total_d++; upper_d++;
		}
		if(lower->rightPtr != NULL){
			lower = lower->rightPtr;
			lower_r++;
		}else if(lower->downPtr != NULL){
			lower = lower->downPtr;
			substract_area += lower_r;
		}
	}
	return (total_d * total_r - substract_area);
}