#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Number{
	unsigned long long int value;
	int ones;
};

typedef struct Number number;

number data[1005];

int cmp(void const* a , void const* b){
	if( ((number *)a)->ones == ((number *)b)->ones ){
		if((((number *)a)->value > ((number *)b)->value))
			return 1;
		return -1;
	}
	return ( ((number *)a)->ones - ((number *)b)->ones );
}

int main(){
	
	int size = 0;
	unsigned long long int num;

	while(scanf("%llu" , &num) != EOF){
		data[size].value = num;

		//__bultin_popcont() || __bultin_popcontl() || __bultin_popcontll()
		data[size].ones = __builtin_popcountll(num);
		size++;
	}

	qsort(data , size , sizeof(number) , cmp);

	for(int i = 0; i < size; i++)
		printf("%llu\n", data[i].value);

	return 0;

}