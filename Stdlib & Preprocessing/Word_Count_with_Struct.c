#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string_count{
        char seen[80];
        int count;
};

int cmp(const void* a , const void* b){
        return ((struct string_count*)a)->count > ((struct string_count*)b)->count ? 1 : ((struct string_count*)a)->count < ((struct string_count*)b)->count ? -1 : strcmp(((struct string_count*)a)->seen , ((struct string_count*)b)->seen);
}

int compare_and_add(char *string , struct string_count strings[]){
        int index = 0;
        while(strings[index].count != 0){
                if(strcmp(string , strings[index].seen) == 0){
                        strings[index].count += 1;
                        return 1;
                }
                index++;
        }
        strcpy(strings[index].seen , string);
        strings[index].count = 1;
        return 0;
}
void sort(struct string_count strings[]){
        int index = 0;
        while(strings[index].count != 0){
                index++;
        }
        
        qsort(strings , index , sizeof(struct string_count) , cmp);
}
void print(struct string_count strings[]){
      int index = 0;
        while(strings[index].count != 0){
                printf("%d %s\n" , strings[index].count , strings[index].seen);
                index++;
        }
}
