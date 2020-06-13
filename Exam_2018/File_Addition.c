#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define min(x , y) (x < y ? x : y)
 
uint8_t first[1025] , second[1025] , result[1025];
 
void adder(FILE* a , FILE* b , FILE* ans){
    fseek(a , 0 , SEEK_END); fseek(b , 0 , SEEK_END);
    uint64_t a_len = ftell(a) , b_len = ftell(b);
 
    if(a_len < b_len){
        FILE* temp = a;
        a = b; b = temp;
        a_len ^= b_len ^= a_len ^= b_len;
    }
 
    // remember to seek the larger, not "SEEK_END"
    fseek(ans , a_len , SEEK_SET); 
 
    int carry = 0; bool second_end = 0;
    while(a_len){
        int k = (b_len <= 0 ? min(a_len , 1024) : min(b_len , 1024));
 
        // read a
        fseek(a , -k , SEEK_CUR);
        fread(first , sizeof(uint8_t) , k , a);
        fseek(a , -k , SEEK_CUR);
 
        // read b
        if(b_len > 0){
            fseek(b , -k , SEEK_CUR);
            fread(second , sizeof(uint8_t) , k , b);
            fseek(b , -k , SEEK_CUR);
            b_len -= k;
        }else if(!second_end){
        	second_end = 1;
        	memset(second , 0 , k);
        }
 
        // adder
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum = first[k - 1 - i] + second[k - 1 - i] + carry;
            result[k - 1 - i] = first[k - 1 - i] + second[k - 1 - i] + carry;
            carry = (sum > 255 ? 1 : 0);
        }
 
        // write result
        fseek(ans , -k , SEEK_CUR);
        fwrite(result , sizeof(uint8_t) , k , ans);
        fseek(ans , -k , SEEK_CUR);
 
        a_len -= k;
    }
}
 
int main(){
    char filename[40]; 
 
    scanf("%s" , &filename);
    FILE* fp_one = fopen(filename , "rb");
 
    scanf("%s" , &filename);
    FILE* fp_two = fopen(filename , "rb");
 
    scanf("%s" , &filename);
    FILE* fp = fopen(filename , "wb");
 
    adder(fp_one , fp_two , fp);
    fclose(fp_one); fclose(fp_two); fclose(fp);
}