#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "fs.h"
 
int valid(Account* A){
    if(A->balance < 0 || (A->gender != 1 && A->gender != 0)) return 0;
 
    int len = strlen(A->name);
    for(int i = 0; i < len; i++)
        if(A->name[i] != ' ' && !isalpha(A->name[i]))
            return 0;
 
    return 1;
}
 
int cmp(const void* a , const void* b){
    return (strcmp(((Account *)a)->name , ((Account *)b)->name));
}
 
Account data[65536];
 
int main(){
    char in[128] , out[128];
    scanf("%s%s" , in , out);
 
    FILE* input = fopen(in , "rb");
    FILE* output = fopen(out , "wb");
 
    Account temp;
    int len = 0;
 
    while(fread(&temp , sizeof(Account) , 1 , input)){
        if(valid(&temp))
            data[len++] = temp;
    }
 
    qsort(data , len , sizeof(Account) , cmp);
    fwrite(data , sizeof(Account) , len , output);
    fclose(input); fclose(output);
 
}