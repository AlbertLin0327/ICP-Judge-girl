#include <stdio.h> 
#include <stdbool.h>

void merge(int A[], int B[], int* a[], int* b[]){
	int i = 0 , j = 0 , pa = 0 , pb = 0;

	int A_bound = 0 , B_bound = 0;
	do{
        A_bound++;
    }while(a[A_bound - 1] != NULL);
	do{
        B_bound++;
    }while(b[B_bound - 1] != NULL);

	bool A_turn = 1;

	if(A[0] < B[0]){
		i++;
		A_turn = 1;
	}else{
		j++;
		A_turn = 0;
	}

	while(i < A_bound && j < B_bound){
		if(A[i] < B[j]){
			if(A_turn){
				a[pa] = &(A[i]);
				pa++; i++;
				A_turn = 1;
			}else{
				b[pb] = &(A[i]);
				pb++; i++;
				A_turn = 1;
			}
		}else{
			if(A_turn){
				a[pa] = &(B[j]);
				pa++; j++;
				A_turn = 0;
			}else{
				b[pb] = &(B[j]);
				pb++; j++;
				A_turn = 0;
			}
		}
	}

	if(i == A_bound){
    	for(;j < B_bound; j++){
    		if(A_turn || pb == B_bound){
        		(a[pa]) = &(B[j]);
        		pa++;
        		A_turn = 0;
        	}else{
        		(b[pb]) = &(B[j]);
        		pb++;
        		A_turn = 0;
        	}
    	}
        if(A_turn)
            a[pa] = NULL;
        else
            b[pb] = NULL;
    }else if(j == B_bound){
    	for(;i < A_bound; i++){
    		if(A_turn || pb == B_bound){
        		(a[pa]) = &(A[i]);
        		pa++;
        		A_turn = 1;
        	}else{
        		(b[pb]) = &(A[i]);
        		pb++;
        		A_turn = 1;
        	}
    	}
        if(A_turn)
            a[pa] = NULL;
        else
            b[pb] = NULL;
    }

}