#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#define max(a , b) (a > b ? a : b)
 
struct Civilian{
    char lastname[81];
    char firstname[81];
    char ID[12];
    int salary;
    int age;
};
 
typedef struct Civilian civilian;
civilian data[52];
 
void print_data(int select_index[] , int number_to_print , char select[][10] , int number_being_select){
    for(int i = 0; i < number_to_print; i++){
        int data_index = select_index[i];
        if(data_index == -1)
            break;
        for(int j = 0; j < number_being_select; j++){
            if(!memcmp(select[j] , "lastname" , 9))
                fputs(data[data_index].lastname , stdout);
            else if(!memcmp(select[j] , "firstname" , 10))
                fputs(data[data_index].firstname , stdout);
            else if(!memcmp(select[j] , "ID" , 3))
                fputs(data[data_index].ID , stdout);
            else if(!memcmp(select[j] , "salary" , 7))
                printf("%d", data[data_index].salary);
            else if(!memcmp(select[j] , "age" , 4))
                printf("%d", data[data_index].age);
 
            printf("%s" , j == number_being_select - 1 ? " \n" : " ");
 
        }
    }
    return;
}
 
int find_target(char condition[3][81] , int list[50] , int n){
    int selected_number = 0;
    int length = strlen(condition[2]);
 
    //a bunch of crappy if else to find what to print
    for(int i = 0; i < n; i++){
        if(!memcmp(condition[0] , "lastname" , 9)){
            if(!memcmp(condition[1] , "==" , 3)){
                if(!memcmp(data[i].lastname , condition[2] , max(strlen(data[i].lastname) , length))){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else{
                if(memcmp(data[i].lastname , condition[2] , max(strlen(data[i].lastname) , length)) != 0){
                    list[selected_number] = i;
                    selected_number++;
                }
            }
        }else if(!memcmp(condition[0] , "firstname" , 10)){
            if(!memcmp(condition[1] , "==" , 3)){
                if(!memcmp(data[i].firstname , condition[2] , max(strlen(data[i].firstname) , length))){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else{
                if(memcmp(data[i].firstname , condition[2] , max(strlen(data[i].firstname) , length)) != 0){
                    list[selected_number] = i;
                    selected_number++;
                }
            }
        }else if(!memcmp(condition[0] , "ID" , 3)){
            if(!memcmp(condition[1] , "==" , 3)){
                if(!memcmp(data[i].ID , condition[2] , max(strlen(data[i].ID) , length))){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else{
                if(memcmp(data[i].ID , condition[2] , max(strlen(data[i].ID) , length)) != 0){
                    list[selected_number] = i;
                    selected_number++;
                }
            }
        }else if(!memcmp(condition[0] , "salary" , 7)){
            int number = atoi(condition[2]);
            if(!memcmp(condition[1] , "==" , 3)){
                if(data[i].salary == number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else if(!memcmp(condition[1] , ">" , 2)){
                if(data[i].salary > number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else{
                if(data[i].salary < number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }
        }else if(!memcmp(condition[0] , "age" , 4)){
            int number = atoi(condition[2]);
            if(!memcmp(condition[1] , "==" , 3)){
                if(data[i].age == number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else if(!memcmp(condition[1] , ">" , 2)){
                if(data[i].age > number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }else{
                if(data[i].age < number){
                    list[selected_number] = i;
                    selected_number++;
                }
            }
        }
    }
 
    return selected_number;
 
}
 
void read_instruction(int n){
    char select[10][10] = {0};
    char condition[3][81] = {0};
 
    char input[80] = {0};
    int select_index = 0;
 
    //ninja code for storing condition 
    while(scanf("%s" , input) != EOF){
        if(!memcmp(input , "where" , 6)){
            for(int i = 0; i < 3; i++)
                scanf("%s" , condition[i]);
            break;
        }else if(!memcmp(input , "select" , 7)){
            continue;
        }else{
            memcpy(select[select_index] , input , strlen(input));
            select_index++;
        }
    }
 
    int target_index[50];
    memset(target_index , -1 , 50 * sizeof(int));
    int person_selected = find_target(condition , target_index , n);
 
#ifdef DEBUG
    printf("%d\n", person_selected);
    for(int i = 0; i < person_selected; i++)
        printf("%d " , target_index[i]);
#endif
 
    print_data(target_index , person_selected , select , select_index);
 
}
 
void database_construction(int n){
    for(int i = 0; i < n; i++)
        scanf("%s %s %s %d %d" , data[i].lastname , data[i].firstname , data[i].ID , &data[i].salary , &data[i].age);
    return;
}
 
int main(){
    int n; scanf("%d" , &n);
    database_construction(n);
 
    int m; scanf("%d" , &m);
    for(int i = 0; i < m; i++){
        read_instruction(n);
    }
}