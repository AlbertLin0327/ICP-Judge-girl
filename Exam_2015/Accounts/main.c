#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

Account data[100000];

int accountNum_cmp(const void *a, const void *b){
	return ((Account*)a)->accountNum - ((Account*)b)->accountNum;
}

int zipcode_cmp(const void *a, const void *b){
	return ((Account*)a)->zipcode - ((Account*)b)->zipcode;
}

int age_cmp(const void *a, const void *b){
	return ((Account*)a)->age - ((Account*)b)->age;
}

int main(){

	char filename[50]; scanf("%s", filename);
	FILE *f = fopen(filename , "rb");

	fread(data , sizeof(Account) , 100000 , f);
	int total = ftell(f) / sizeof(Account);
	fclose(f);

	qsort(data , total , sizeof(Account) , accountNum_cmp);

	printf("account, age, zipcode, balance\n");
	for(int i = 0; i < total; i++)
		printf("%d, %d, %d, %d\n" , data[i].accountNum , data[i].age , data[i].zipcode , data[i].balance);

	int prev = -1 , sum = 0;

#if SORTBY == ZIPCODE
	qsort(data , total , sizeof(Account) , zipcode_cmp);
	printf("zipcode, sum_balance\n");

	for(int i = 0; i < total; i++){
		if(data[i].zipcode == prev)
			sum += data[i].balance;
		else{
			if(prev != -1)
				printf("%d, %d\n", prev, sum);
			prev = data[i].zipcode; sum = data[i].balance;
		}
	}
	printf("%d, %d\n", prev, sum);
#else
	qsort(data , total , sizeof(Account) , age_cmp);
	printf("age, sum_balance\n");

	for(int i = 0; i < total; i++){
		if(data[i].age == prev)
			sum += data[i].balance;
		else{
			if(prev != -1)
				printf("%d, %d\n", prev, sum);
			prev = data[i].age; sum = data[i].balance;
		}
	}
	printf("%d, %d\n", prev, sum);
#endif


}