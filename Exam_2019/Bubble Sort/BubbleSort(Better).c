#include <stdint.h>

void BubbleSort(uint64_t number, uint64_t output[63]){
    for(int i = 0 ; i < 63; ++i){
    	//c == 1100  ,  8 = 0100
    	uint64_t start = 0xc000000000000000, one_zero = 0x8000000000000000;  
        for(int j = 0 ; j < 63; ++j){

        	//XOR something even times make no different(0 for 62 times)
            if((number & start) == one_zero) 
            	number ^= start;
            
            start >>= 1;
            one_zero >>= 1;
        }
        output[i] = number;
    }
}