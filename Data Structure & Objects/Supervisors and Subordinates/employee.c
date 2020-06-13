#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id ){
	Employee* result;
	for(int i = 0; i < n; i++)
		if(set[i].id == id){
			result = &set[i]; break;
		}
	return result;
}

Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ){
	Employee* result;
	for(int i = 0; i < n; i++)
		if(!strcmp(set[i].first_name , first_name) && !strcmp(set[i].last_name , last_name)){
			result = &set[i]; break;
		}
	return result;
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ){
	Employee* result;
	while(employee->boss_id != employee->id){
		for(int i = 0; i < n; i++)
			if(employee->boss_id == set[i].id){
				employee = &set[i]; break;
			}
	}
	return result;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B){
	Employee* real_boss_A = A;
 
    while(real_boss_A->boss_id != real_boss_A->id){
    	if(real_boss_A->boss_id == B->id)
    		return 1;

    	for(int i = 0; i < n; i++)
    		if(real_boss_A->boss_id == set[i].id){
    			real_boss_A = &set[i]; break;
    		}
    }
 
    Employee* real_boss_B = B;
 
    while(real_boss_B->boss_id != real_boss_B->id){
    	if(real_boss_B->boss_id == A->id)
    		return 2;
    	
    	for(int i = 0; i < n; i++)
    		if(real_boss_B->boss_id == set[i].id){
    			real_boss_B = &set[i]; break;
    		}
    }
 
    return (real_boss_A->id == real_boss_B->id ? 3 : 4);
}
