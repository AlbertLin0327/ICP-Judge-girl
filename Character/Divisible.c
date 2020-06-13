#include <stdio.h>
#include <stdbool.h>

int main(){
	char chr;
	int num;
	int two = 0 , three = 0 , five = 0 , odd = 0 , even = 0;
	bool first = 0;

	while((chr = getchar()) != '-'){
		if(chr != '\n'){
			num = (int)(chr - '0');
			two = num;
			three += num;
			three %= 3;
			five = num;
			if(first == 0){
				odd += num;
				first = 1;
			}else{
				even += num;
				first = 0;
			}
			odd %= 11;
			even %= 11;
		}
		else if(chr == '\n'){
			if(two % 2 == 0){
				printf("yes ");
			}else{
				printf("no ");
			}
			if(three % 3 == 0){
				printf("yes ");
			}else{
				printf("no ");
			}
			if(five == 0 || five == 5){
				printf("yes ");
			}else{
				printf("no ");
			}
			if(odd - even % 11 == 0){
				printf("yes\n");
			}else{
				printf("no\n");
			}
			two = three = five = odd = even = 0;
		}
	}
}