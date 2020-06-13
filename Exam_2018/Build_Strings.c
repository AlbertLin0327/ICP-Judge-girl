#include <stdio.h>
#include <string.h>
#include <stdint.h>
 
short index_array[1024];
char pool[26];
 
 
void print(int* L , char* C , int* K){
    char to_print = *C;
    int shift = 0;
 
    for(int i = 0; i < *L; i++){
        int previous = 0;
        for(int j = 0; j < i; j++)
            previous += index_array[j];
 
        if(i != 0){
            for(int j = 0; j < *K ; j++){
                pool[j] = ((to_print + j + 1 - 'a') % 26 + 'a'); 
            }
 
            for(int i = 0; i < *K - 1; i++){
                for(int j = 0; j < *K - i; j++){
                    if(pool[j] > pool[j + 1])
                        pool[j] ^= pool[j + 1] ^= pool[j] ^= pool[j + 1];
                }
            }
 
        }else
            pool[0] = *C;
        to_print = pool[index_array[i]];
 
        printf("%c", to_print);
    }
    printf("\n");
 
}
 
int main(){
    char C; scanf("%c" , &C);
    int K; int L; int64_t N; scanf("%d%d%lld" , &K , &L , &N);
    int64_t* N_ptr = &N;
 
    memset(index_array , 0 , L * sizeof(int));
 
    for(int i = 0; i < N; i++){

        print(&L , &C , &K);
        int carry_index = L - 1;
        index_array[carry_index]++;

        while(index_array[carry_index] == K){
            index_array[carry_index] = 0;
            carry_index--;
            index_array[carry_index]++;
        }
    }
}