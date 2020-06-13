#include <stdio.h>
#include "set.h"
 
int main(){
    Set s;
    int numberOfElement = 4;
    initializeSet(&s, numberOfElement);
 
    addElement(&s, 1);
    addElement(&s, 2);
    addElement(&s, 4);
 
    removeElement(&s, 1);
 
    printSet(s); 
}