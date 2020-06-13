#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
	int n;
	scanf("%d" , &n);

	char a[80] , b[80];
	while(n--){

		scanf("%s" , a);
		scanf("%s" , b);

		int diff = 0 , diff_index = 0;
		bool same = 1;

		if(strlen(a) == strlen(b)){

			for(int i = 0; i < strlen(a); i++){
				if(a[i] != b[i]){
					diff++;
					same = 0;
				}
			}

		}else if(strlen(a) - strlen(b) == 1){

			while(a[diff_index] == b[diff_index]){
				diff_index++;
			}
			for(int i = diff_index; i < strlen(b); i++){
				if(a[i + 1] != b[i]){
					same = 0;
				}
			}
			
		}else if(strlen(b) - strlen(a) == 1){
			
			while(a[diff_index] == b[diff_index]){
				diff_index++;
			}
			for(int i = diff_index; i < strlen(a); i++){
				if(b[i + 1] != a[i]){
					same = 0;
				}
			}
			
		}else{
			same = 0;
		}

		if(diff == 2 || same == 1){
			printf("yes\n");
		}else{
			printf("no\n");
		}

	}

	return 0;

}