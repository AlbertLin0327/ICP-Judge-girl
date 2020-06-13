#include <stdio.h>
#include <string.h>

char str[100005] = {0};
unsigned long long int ans = 0;

void str_to_num(){

	fgets(str , 100005 , stdin);
	
	int length = strlen(str);
	str[--length] = '\0';
	
	for(int i = 0; i <= length; i++){
		ans |= (unsigned long long int)str[i] << (7 - i % 8) * 8;
		if(((i & 7) == 7 && i != 0) || i == length){
			printf("%llu\n", ans);
			ans = 0;
		}
	}

	return;

}

void num_to_str(){
	int n; scanf("%d" , &n);

	for(int i = 0; i < n; i++){
		scanf("%llu" , &ans);
		memcpy(str , (char *)&ans , 8);

	}

	puts(str);

	return;

}

int main(){
	int type; scanf("%d\n" , &type);

	switch(type){
		case 0:
			str_to_num();
			break;
		case 1:
			num_to_str();
			break;
	}

	return 0;
}