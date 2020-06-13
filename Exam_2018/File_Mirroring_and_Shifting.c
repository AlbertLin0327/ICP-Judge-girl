#include <stdio.h>
 
int main(){
    char in[17] , out[17]; int n;
    scanf("%s %s %d" , in , out , &n);

    FILE *input = fopen(in , "rb");
    FILE *output = fopen(out , "wb");

    fseek(input, 0, SEEK_END);
    int len = ftell(input);

    fseek(input , -n , SEEK_CUR);
    for (int i = n; i < len; i++){
        fseek(input, -1, SEEK_CUR);
        unsigned char temp , reversed = 0;   
        fread(&temp , 1 , 1 , input);
        for (int j = 0; j < 8; j++)
            if ((temp & (1 << j)))
                reversed |= 1 << (7 - j);
        fseek(input, -1, SEEK_CUR);
        fwrite(&reversed , 1 , 1 , output);
    }

    fseek(input , 0 , SEEK_END);
    for (int i = 0; i < n; i++){
        fseek(input, -1, SEEK_CUR);
        unsigned char temp , reversed = 0;   
        fread(&temp , 1 , 1 , input);
        for (int j = 0; j < 8; j++)
            if ((temp & (1 << j)))
                reversed |= 1 << (7 - j);
        fseek(input, -1, SEEK_CUR);
        fwrite(&reversed , 1 , 1 , output);
    }

    fclose(input);
    fclose(output);
    return 0;
}