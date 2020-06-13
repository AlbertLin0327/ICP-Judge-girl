#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a , const void* b){
	return strcmp((char *)a , (char *)b);
}

void merge(char * str , int len){
	char temp[35000][4];
	for(int i = 0; str[i * 3] != '\0'; i++)
		for(int j = 0; j < 3; j++)
			temp[i][j] = str[i * 3 + j];

	/*

    void qsort (void* base , size_t num , size_t size , int (*compar)(const void*,const void*));

    base : Pointer to the first object of the array to be sorted, converted to a void*.
    num : Number of elements in the array pointed to by base.
    size : Size in bytes of each element in the array.

    */

	qsort(temp , len / 3 , 3 , cmp);

	for(int i = 0; str[i * 3] != '\0'; i++)
		for(int j = 0; j < 3; j++)
			printf("%c", temp[i][j]);
		
	printf("\n");

}


int main(){
	char result[100005] , str[100005];
	scanf("%s" , result);

	while(scanf("%s" , str) != EOF){
		strcat(result , str);
		merge(result , strlen(result));
	}

	return 0;

}