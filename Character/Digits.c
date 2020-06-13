#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
int main(){
    int width , height;
    char input[12];
    
    while(scanf("%s %d %d", input, &width, &height) == 3){
        int length = strlen(input);

        for(int i = 0; i < height; i++){
            for(int j = 0; j < length; j++){
                if(i == 0 || i == height / 2 || i == height - 1){
                    if(i == 0){
                        switch(input[j]){
                            case '0': case '2': case '3': case '5' ... '9':
                                printf(" ");
                                for(int k = 0; k < width - 3; k++)
                                    printf("%c", input[j]);
                                printf("  ");
                                break;

                            default:
                                for(int k = 0; k < width; k++)
                                    printf(" ");
                                break;
                        }
                    }else if(i == height / 2){
                        switch(input[j]){
                            case '2' ... '6': case '8': case '9':
                                printf(" ");
                                for(int k = 0; k < width - 3; k++)
                                    printf("%c", input[j]);
                                printf("  ");
                                break;

                            default:
                                for(int k = 0; k < width; k++)
                                    printf(" ");
                                break;
                        }
                    }else{
                        switch(input[j]){
                            case '0': case '2': case '3': case '5': case '6': case '8':
                                printf(" ");
                                for(int k = 0; k < width - 3; k++)
                                    printf("%c", input[j]);
                                printf("  ");
                                break;
                                
                            default:
                                for(int k = 0; k < width; k++)
                                    printf(" ");
                                break;
                        }
                    }
                    
                }else{
                    if(i < height / 2){
                        switch(input[j]){
                            case '0': case '4' ... '9':
                                 printf("%c", input[j]);
                                for(int k = 0; k < width - 3; k++)
                                    printf(" ");
                                break;

                            default:
                                for(int k = 0; k < width - 2; k++)
                                    printf(" ");
                                break;
                        }

                        switch(input[j]){
                            case '0' ... '4': case '7' ... '9':
                                printf("%c ", input[j]);
                                break;

                            default:
                                printf("  ");
                                break;
                        }

                    }else{
                        switch(input[j]){
                            case '0': case '2': case '6': case '8':
                                 printf("%c", input[j]);
                                for(int k = 0; k < width - 3; k++)
                                    printf(" ");
                                break;
                                
                            default:
                                for(int k = 0; k < width - 2; k++)
                                    printf(" ");
                                break;
                        }

                        switch(input[j]){
                            case '0': case '1': case '3' ... '9':
                                printf("%c ", input[j]);
                                break;

                            default:
                                printf("  ");
                                break;
                        }

                    }
                }
            }
            printf("\n");
        }
    }
}