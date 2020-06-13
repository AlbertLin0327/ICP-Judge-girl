#include <stdio.h>

int main(){

	int a = 0 , b = 0;

	//remeber to save one more space for the ending "\0" which also use one space
	char num_one[5] , num_two[5];
	scanf("%s %s" , num_one , num_two);

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(num_one[i] == num_two[j] && i == j){
				a++;
				break;
			}else if(num_one[i] == num_two[j] && i != j){
				b++;
				break;
			}
		}
	}

	printf("%dA%dB\n" , a , b);

	return 0;

}