#include <stdlib.h>
#include <stdio.h>
#include "GPA_calculation.h"

int cmp(const void* a , const void* b){
	return ((((struct Student*)a)->GPA < ((struct Student*)b)->GPA) ? 1 : -1);
}

void GPA_calculation(struct Student all_student[], int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < all_student[i].N_class; j++){
			double current = 0;
			switch(all_student[i].all_class[j].score[0]){
				case 'A':
					current = 4;
					break;
				case 'B':
					current = 3;
					break;
				case 'C':
					current = 2;
					break;
				default:
					current = 0;
					break;
			}
			switch(all_student[i].all_class[j].score[1]){
				case '+':
					current += 0.3;
					break;
				case '-':
					current -= 0.3;
					break;
				default:
					current += 0;
					break;
			}
			all_student[i].GPA += (current * (double)all_student[i].all_class[j].academic_credit);
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
		}
		all_student[i].GPA /= (double)all_student[i].N_credit;
	}

	qsort(all_student , N , sizeof(struct Student) , cmp);

	int award = (N - 1) / 20 + 1;

	for(int i = 0; i < award; i++){
		if(all_student[i].N_credit >= 15 && all_student[i].GPA >= 3.38){
			printf("%d %s %f\n", i + 1 , all_student[i].name , all_student[i].GPA);
		}
	}

}