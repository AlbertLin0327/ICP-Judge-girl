#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grading.h"
 
int cmp(const void* a , const void* b){
    return ((Submission *)a)->studentID > ((Submission *)b)->studentID ? 1 : ((Submission *)a)->studentID < ((Submission *)b)->studentID ? -1 : ((Submission *)a)->subID > ((Submission *)b)->subID ? 1 : -1;
}
 
void grading(char answer[10][maxL], Submission* sub, int num_of_submission){

    qsort(sub , num_of_submission , sizeof(Submission) , cmp);
    int consecutive = sub[0].studentID , max = 0;
    for(int i = 0; i < num_of_submission; i++){
 
        int score = 0;
        for(int j = 0; j < 10; j++)
            if(!strcmp(answer[j] , sub[i].outputs[j]))
                score += 10;
 
        if(consecutive != sub[i].studentID){
            printf("Student %d gets %d in this exam.\n" , consecutive , max);
            consecutive = sub[i].studentID;
            max = score; i--;
        }else{
            printf("Student %d gets %d with Submission %d.\n", consecutive , score , sub[i].subID);
            max = max > score ? max : score;
        }
    }
    printf("Student %d gets %d in this exam.\n" , consecutive , max);
}