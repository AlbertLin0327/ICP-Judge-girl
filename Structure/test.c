#include <stdio.h>

int ReadString(char* str){
    while(1){
    	char ch = getchar();
	    int i = 0;
	    if(ch != ' ' && ch != '\n' && i != 0){
	    	str[i] = ch;
	    	i++;
	    }else{
	    	str[i] = '\0';
	    	return 1;
	    }
    }  
}

int main(){
	char str[80] = {0};
	ReadString(&str[0]);

	printf("%s\n", str);
}