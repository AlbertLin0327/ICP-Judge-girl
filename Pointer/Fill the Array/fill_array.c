#include <stdio.h>
void fill_array(int *ptr[], int n){
	int arr_size = (ptr[n - 1] - ptr[0]) + 1;
	int ptr_loc_arr[arr_size];

	for (int i = 0; i < arr_size; ++i){
		ptr_loc_arr[i] = -1;
	}

	for(int i = 0; i < n; i++){
		int ptr_loc = (ptr[i] - ptr[0]);
		ptr_loc_arr[ptr_loc] = i;
		**(ptr + i) = i;
	}

	int* order = *ptr;

	for(int i = 1; i < arr_size; i++){
		if(ptr_loc_arr[i] == -1){
			int prev = i , next = i;
			while(ptr_loc_arr[prev] == -1){
				prev--;
			}
			while(ptr_loc_arr[next] == -1){
				next++;
			}
			*(order + i) = *(ptr[ptr_loc_arr[prev]]) + *(ptr[ptr_loc_arr[next]]);
		}else{
			continue;
		}
	}
}