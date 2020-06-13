#include "employee.h"
#include <stdbool.h>
 
int relation(Employee *employee1, Employee *employee2) {
    Employee* real_boss1 = employee1;

    while(real_boss1->boss != real_boss1){
    	if(real_boss1->boss == employee2)
    		return 1;

    	real_boss1 = real_boss1->boss;
    }

    Employee* real_boss2 = employee2;

    while(real_boss2->boss != real_boss2){
    	if(real_boss2->boss == employee1)
    		return 2;

    		real_boss2 = real_boss2->boss;
    }
    
    return (real_boss1 == real_boss2 ? 3 : 4);

}