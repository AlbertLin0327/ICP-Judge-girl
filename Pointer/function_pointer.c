#include <stdio.h>

int add(int a , int b){
	return a + b;
}

int substract(int a , int b){
	return a - b;
}

int multiple(int a , int b){
	return a * b;
}

int* point(int a , int arr[]){
	int* k;

	for(int i = 0; i < 10 ; i++){
		if(arr[i] == a){
			k = &arr[i];
		}
	}

	return k;

}



int main(){
	int a = 3 , b = 7;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};

	//function pointer return_type (*pointer_name)(variable_type , variable_name ...)
	int (*func_p)(int , int) = add;
	int (*func_p_arr[])(int , int) = {add , substract , multiple};

	//return type is a pointer
	int* (*pointer_funtion_p)(int , int[]) = point;

	/*
	// invalid conversion from ‘int (*)(int, int)’ to ‘int’ [-fpermissive]
	int func = add;
	printf("%d\n", func_p(a , b));
	*/

	printf("%d\n", func_p(a , b));

	for(int i = 0; i < 3; i++){
		printf("%d\n", func_p_arr[i](a , b));
	}

	//remember to add *
	printf("%d\n", *pointer_funtion_p(a , arr));

	return 0;

}