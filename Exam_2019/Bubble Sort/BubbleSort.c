#include <stdint.h>
#include <stdbool.h>
 
void BubbleSort(uint64_t input, uint64_t output[63]){
    for(int time = 0; time < 63; time++){
        for(int i = 0; i < 63; i++){
 
            if((bool)((input >> (63 - i)) & 1) && !(bool)((input >> (62 - i)) & 1)){
                input |= ((uint64_t)1 << (62 - i));
                input &= ~((uint64_t)1 << (63 - i));
            }
            
        }
        output[time] = input;
    }
}