#include <stdio.h>
#include <stdlib.h>

int main(){
    char file_name[20]; scanf("%s" , file_name);
    FILE* input = fopen(file_name , "rb");

    int type , instruction;
    char buffer[5];
    while(fread(&type , 4 , 1 , input)){
        switch(type){
            case 0:
                fread(&instruction , 4 , 1 , input);
                printf("%d", instruction);
                break;

            case 1:
                fread(buffer , 1 , 4 , input);
                printf("%s", buffer);
                break;

            case 2:
                fread(&instruction , 4 , 1 , input);
                char c;
                while((c = fgetc(input)) != EOF){
                    if(c == '\0')
                        break;
                    fputc(c , stdout);
                }
                break;

            case 3:
                fread(&instruction , 4 , 1 , input);
                fseek(input , instruction - 8 , SEEK_CUR);
                break;

            case 4:
                fread(&instruction , 4 , 1 , input);
                fseek(input , instruction , SEEK_SET);
                break;

            case 5:
                fread(&instruction , 4 , 1 , input);
                fseek(input , instruction , SEEK_END);
                break;

            default:
                printf("Seek end\n");
                exit(0);

        }
    }
}