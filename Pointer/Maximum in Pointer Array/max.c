int max(int *iptr[], int n){

	// for a pointer array *ptr[] , *ptr[0] == **ptr && *ptr[3] == **(ptr + 3)
	int max = *iptr[0];

	for (int i = 0; i < n; i++) {
        if(max < *(iptr[i]))
        	max = *(iptr[i]);
    }

    return max;

}