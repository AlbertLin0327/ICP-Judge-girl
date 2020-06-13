#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
	int location[k];
	for(int i = 0; i < k; i++){
		location[i] = -1;
		head[i] = NULL;
	}

	int size = 0;

	//if you use sizeof(arr) / sizeif(arr[0]) to test length in an array will fail, 
	//cuz you will only recieve a pointer adress by calculating "arr".
	//This method only work in main
	
	do{
		size++;
	}while(a[size - 1] != NULL);


	for(int i = 0; i < size; i++)
		a[i] = NULL;

	for(int i = 0; i < size; i++){
		int mod = A[i] % k;
		if(location[mod] == -1){
			head[mod] = &A[i];
			location[mod] = i;
		}else{
			a[location[mod]] = &A[i];
			location[mod] = i;
		}
	}

}