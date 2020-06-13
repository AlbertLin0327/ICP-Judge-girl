#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

	unsigned long long int ans = 0;
	unsigned int L = 0;
	unsigned short S = 0;
	unsigned char C[2] = {0 , 0};

	int mode; scanf("%d" , &mode);
	char sequence[4];

	switch(mode){
		case 0:
			while(scanf("%s %u %hu %c%c" , sequence , &L , &S , &C[0] , &C[1]) != EOF){
				int shift = 0;
				bool index = 0;
				for(int i = 0; i < 4; i++){
					switch(sequence[i]){
						case 'L':
							ans |= ((unsigned long long int)L << (32 - shift));
							shift += 32;
							break;

						case 'S':
							ans |= ((unsigned long long int)S << (48 - shift));
							shift += 16;
							break;

						case 'C':
							ans |= ((unsigned long long int)C[index] << (56 - shift));
							shift += 8; index = !index;
							break;

					}
				}
				printf("%llu\n", ans);
				ans = 0;
			}
			break;

		case 1:
			while(scanf("%s %llu" , sequence , &ans) != EOF){
				int shift = 0;
				bool index = 0;
				for(int i = 0; i < 4; i++){
					switch(sequence[i]){
						case 'L':
							L |= (ans >> (32 - shift));
							shift += 32;
							break;

						case 'S':
							S |= (ans >> (48 - shift));
							shift += 16;
							break;

						case 'C':
							C[index] |= (char)(ans >> (56 - shift));
							index = !index;
							shift += 8;
							break;
					}
				}
				printf("%u %hu %c%c\n", L , S , C[0] , C[1]);
				L = 0; S = 0; C[0] = 0; C[1] = 0;
			}	
			
	}
	
}