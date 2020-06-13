#include "computeGrade.h"
#include <stdio.h>

void computeGrade(Classes classes[2]){

	int class_Num[2] = {classes[0].numStudent , classes[1].numStudent};

	for(int i = 0; i < 18; i++){
		int raw_Sum[2] = {0};

		for(int j = 0; j < 2; j++){
			for(int k = 0; k < class_Num[j]; k++){
				raw_Sum[j] += classes[j].student[k].score[i].rawScore;
			}
		}

		double raw_Avg[2] = {(double)raw_Sum[0] / class_Num[0] , (double)raw_Sum[1] / class_Num[1]};

		if(raw_Avg[0] < raw_Avg[1]){
			double ratio = raw_Avg[1] / raw_Avg[0];
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < class_Num[j]; k++){
					classes[j].student[k].score[i].scaledScore = classes[j].student[k].score[i].rawScore * (j == 0 ? ratio : 1);
					if(classes[j].student[k].score[i].scaledScore > 100)
						classes[j].student[k].score[i].scaledScore = 100;
				}
			}
		}else if(raw_Avg[0] > raw_Avg[1]){
			double ratio = raw_Avg[0] / raw_Avg[1];
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < class_Num[j]; k++){
					classes[j].student[k].score[i].scaledScore = classes[j].student[k].score[i].rawScore * (j == 1 ? ratio : 1);
					if(classes[j].student[k].score[i].scaledScore > 100)
						classes[j].student[k].score[i].scaledScore = 100;
				}
			}
		}else{
			for(int j = 0; j < 2; j++){
				for(int k = 0; k < class_Num[j]; k++){
					classes[j].student[k].score[i].scaledScore = classes[j].student[k].score[i].rawScore;
				}
			}
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < class_Num[i]; j++){
			double Avg = 0;
			for(int k = 0; k < 18; k++){
				Avg += classes[i].student[j].score[k].scaledScore;
			}

			Avg *= 0.06;

			printf("%s %f\n", classes[i].student[j].id , (Avg > 100 ? 100.000000 : Avg));
		}
	}
}