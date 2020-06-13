#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
 
int main() {
    char s[1024];
 
    while (fgets(s , 1024 , stdin) != NULL) {
 
        int n = (int) strlen(s);
        bool consecutive = 0;
        int sum = 0;
 
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if(isdigit(c)){
                sum *= 10;
                sum += (int)(c - '0');
                consecutive = 1;
            }else if(!isdigit(c) && consecutive){
                printf("%d\n", sum);
                sum = 0;
                consecutive = 0;
            }
 
        }
 
        if(consecutive)
            printf("%d\n", sum);
 
    }
    return 0;
}