#include <stdio.h>

int main(){
	int arr[10][10][10][10] = {0};

	int *ptr1 , *ptr2 , **ptr1_2D;

	//arr[0] = &(arr[0][0])
	ptr1 = arr[0][0][0];
	ptr2 = &(arr[0][0][0][0]);
	ptr1_2D = &ptr1;

	printf("ptr1 : %p\nptr2 : %p\n", ptr1 , ptr2);
	printf("ptr1_2D : %p\n*ptr1_2D : %p\n" , ptr1_2D , *ptr1_2D);
	printf("ptr1 : %d\nptr2 : %d\n", *ptr1 + 1 , *ptr2 + 2);

	/*
	//incompatible pointer types initializing 'int *' with an expression of type 'int [10][10]'
	int *ptr3 = arr[0][0];
	printf("ptr3 : %p\n" , ptr3);
	*/

	//a pointer that cross ten int
	//ptr3[10] = &arr[0][0][0]  -->  ptr3[10] + 1 = &arr[0][0][1]
	int (*ptr3)[10] = arr[0][0];
	printf("ptr3[10] : %p\nptr3[10] + 1 : %p\n", ptr3 , ptr3 + 1);
	printf("arr[0][0][0] : %p\narr[0][0][1] : %p\n", arr[0][0][0] , arr[0][0][1]);

	//ptr4[10][10]
	int (*ptr4)[10][10] = arr[0];
	printf("ptr4[10][10] : %p\nptr4[10][10] + 1 : %p\n", ptr4 , ptr4 + 1);
	printf("arr[0][0] : %p\narr[0][1] : %p\n", arr[0][0][0] , arr[0][1]);

	printf("arr[0][1] : %p\n&arr[0][1] : %p\n&arr[0][1][0] : %p\n", arr[0][1] , &arr[0][1] , &arr[0][1][0]);

	//(*ptr)[][] : a pointer points to 2D array
	//*ptr[][] : a 2D pointer array
	int *ptr5[10][10];

	printf("sizeof(ptr4) : %ld\nsizeof(ptr5) : %ld\n", sizeof(ptr4) , sizeof(ptr5));

	return 0;

}