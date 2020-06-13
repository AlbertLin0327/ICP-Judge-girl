#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char str[3][12]; 
char* ptr_arr[26][30]; // point to each alphabet
int arr_num[26]; // how many times each alphabet appears
bool valid_alphabet[26]; // which alphabet occurs
int total_alpha; // how many alphabet do i have to deal with
int strlength[3];

int toInt(char x[] , int n){
	int result = 0;
	for(int i = 0; i < strlength[n]; i++){
		result = result * 10 + x[i];
	}
	return result;
}

void hash(int alpha , char value){
	if(value > 9 || alpha > total_alpha)
		return;
	
	int index = alpha;
	for(int i = 0; i < 26; i++){
		if(valid_alphabet[i])
			index--;
		if(index == -1){
			index = i; break;
		}
	}

	int a = toInt(str[0] , 0) , b = toInt(str[1] , 1) , c = toInt(str[2] , 2);
	if(a * b == c){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < strlength[i]; j++){
				printf("%d", str[i][j]);
			}
			printf("%s" , i == 0 ? " x " : i == 1 ? " = " : "\n");
		}
		exit(0);
	}

	for(int i = 0; i < arr_num[index]; i++){
		if(*ptr_arr[index][i] > '9')
			return;
		*ptr_arr[index][i] = value;
	}

	for(int j = 1; j < total_alpha - alpha; j++)
			hash(alpha + j , 1);

	hash(alpha , value + 1);

}


int main(){
	scanf("%s%s%s" , str[0] , str[1] , str[2]);
	for(int i = 0; i < 3; i++)
		strlength[i] = strlen(str[i]);

	memset(arr_num , 0 , 26); memset(valid_alphabet , 0 , 26);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < strlength[i]; j++){
			if(isdigit(str[i][j])){
				str[i][j] -= '0';
				continue;
			}
			int index = (str[i][j] - 'A'); str[i][j] = 1;
			ptr_arr[index][arr_num[index]] = &(str[i][j]);
			arr_num[index]++; valid_alphabet[index] = 1;
		}
	}

	for(int i = 0; i < 26; i++)
		if(valid_alphabet[i])
			total_alpha++;

	hash(0 , 1);
}
