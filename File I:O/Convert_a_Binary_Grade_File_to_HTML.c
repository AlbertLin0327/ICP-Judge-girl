#include <stdio.h>
#include <string.h>
 
struct student{
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
};
 
typedef struct student data;
 
int main(){
 
    char in[80] , out[80]; scanf("%s%s" , in , out);
    FILE* input = fopen(in , "rb");
    FILE* output = fopen(out , "wt");
 
    fseek(input , 0 , SEEK_END);
    int n = ftell(input) / sizeof(data);
    fseek(input , 0 , SEEK_SET);
 
    data Student[n];
    fread(Student , sizeof(data) , n , input);
 
    fprintf(output , "<table border=\"1\">\n<tbody>\n");
    for(int i = 0; i < n; i++){                
        fprintf(output , "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n" , Student[i].name , Student[i].id , Student[i].phone , Student[i].grade[0] , Student[i].grade[1] , Student[i].grade[2] , Student[i].grade[3] , Student[i].birth_year , Student[i].birth_month , Student[i].birth_day);
    }
 
    fprintf(output , "</tbody>\n</table>\n");
 
    fclose(input); fclose(output);
}